/**
 * @author [Ioannis Margaris]

 * @create date 28 Aug. 2020 - 14:17:39

 * @desc [The alternative to a polling loop is for the main thread to block and wait for a signal that new data is available.
 * This would prevent the infinite loop from keeping the processor busy. We have already discussed a mechanism that would fulfill 
 * this purpose - the promise-future construct. The problem with futures is that they can only be used a single time.
 * Once a future is ready and get() has been called, it can not be used any more. 
 * For our purpose, we need a signaling mechanism that can be re-used. The C++ standard offers such a construct in the form of "condition variables".
 * 
 * A std::condition_variable has a method wait(), which blocks, when it is called by a thread. 
 * The condition variable is kept blocked until it is released by another thread. The release works via the method notify_one() or 
 * the notify_all method. The key difference between the two methods is that notify_one will only wake up a single waiting thread 
 * while notify_all will wake up all the waiting threads at once.
 * 
 * A condition variable is a low-level building block for more advanced communication protocols. It neither has a memory of its own nor 
 * does it remember notifications. Imagine that one thread calls wait() before another thread calls notify(), the condition variable works 
 * as expected and the first thread will wake up. Imagine the case however where the call order is reversed such that notify() is called before 
 * wait(), the notification will be lost and the thread will block indefinitely
 * 
 * Now that we have all the ingredients to implement the concurrent queue to store waiting Vehicle objects, let us start with the implementation:
 * 1. The first step is to add a condition variable to WaitingVehicles class as a private member - just as the mutex.
 * 2. The next step is to notify the client after pushing a new Vehicle into the vector.
 * 3. In the method popBack, we need to create the lock first - it can not be a lock_guard any more as we need to pass it to the condition variable - to its method wait. Thus it must be a unique_lock.
 * 
 * NOTE: Before we continue, we need to discuss the problem of "spurious wake-ups": Once in a while, the system will - for no obvious reason - 
 * wake up a thread. If such a spurious wake-up happened with taking proper precautions, we would issue wait without new data being available 
 * (because the wake-up has not been caused by the condition variable but by the system in this case)
 * 
 * 3 (continued) We can further simplify this code by letting the wait() function do the testing as well as the looping for us. 
 * Instead of a while loop, we can just pass a Lambda to wait(), which repeatedly checks wether the vector contains elements.
 * When wait() finishes, we are guaranteed to find a new element in the vector this time. Also, we are still holding the lock and thus 
 * no other thread is able to access the vector - so there is no danger of a data race in this situation. 
 * As soon as we are out of scope, the lock will be automatically released. 
 * 4. In the main() function, there is still the polling loop that infinitely queries the availability of new Vehicle objects. 
 * But contrary to the example before, a call to popBack now puts the main() thread into a wait state and only resumes when 
 * new data is available - thus significantly reducing the load to the processor]
 */


#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    int getID() { return _id; }

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}

    Vehicle popBack()
    {
        // perform vector modification under the lock
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_vehicles.empty(); }); // pass unique lock to condition variable

        // remove last vector element from queue
        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();

        return v; // will not be copied due to return value optimization (RVO) in C++
    }

    void pushBack(Vehicle &&v)
    {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // add vector to queue
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.push_back(std::move(v));
        _cond.notify_one(); // notify client after pushing new Vehicle into vector
    }

private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
};

int main()
{
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        // create a new Vehicle instance and move it into the queue
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::cout << "Collecting results..." << std::endl;
    while (true)
    {
        // popBack wakes up when a new element is available in the queue
        Vehicle v = queue->popBack();
        std::cout << "   Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished!" << std::endl;

    return 0;
}