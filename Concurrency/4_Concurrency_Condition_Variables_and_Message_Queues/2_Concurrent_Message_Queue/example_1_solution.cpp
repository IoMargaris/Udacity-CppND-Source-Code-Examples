/**
 * @author [Ioannis Margaris]

 * @create date 29 Aug. 2020 - 14:22:49

 * @desc [The following changes are required to turn the WaitingVehicles queue into a generic message queue:
 * 
 * 1. Enable the class for templates by prepending template<class T> and change the name of the class to MessageQueue
 * 2. Replace the std::vector by a std::deque as it makes more sense to retrieve the objects in the order "first-in, first-out (FIFO)". Also, rename it to _messages.
 * 3. Adapt the method pushBack for use with templates and rename it send. Do the same with popBack and rename it to receive.
 * 4. Test the queue by executing the following code in main
 * 
 * A message queue is an effective and very useful mechanism to enable a safe and reusable communication channel between threads. 
 * In the final project, we will use shorty use this construct to integrate another component into our simulation - traffic lights at intersections.
 * ]
 */

#include <iostream>
#include <thread>
#include <queue>
#include <future>
#include <mutex>
#include <algorithm>

template <class T>
class MessageQueue
{
public:
    T receive()
    {
        // perform queue modification under the lock
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_messages.empty(); }); // pass unique lock to condition variable

        // remove last vector element from queue
        T msg = std::move(_messages.back());
        _messages.pop_back();

        return msg; // will not be copied due to return value optimization (RVO) in C++
    }

    void send(T &&msg)
    {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // add vector to queue
        std::cout << "   Message " << msg << " has been sent to the queue" << std::endl;
        _messages.push_back(std::move(msg));
        _cond.notify_one(); // notify client after pushing new Vehicle into vector
    }

private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<T> _messages;
};

int main()
{
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
    }

    std::cout << "Collecting results..." << std::endl;
    while (true)
    {
        int message = queue->receive();
        std::cout << "   Message #" << message << " has been removed from the queue" << std::endl;
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished!" << std::endl;

    return 0;
}
