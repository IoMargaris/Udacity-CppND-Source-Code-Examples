/**
 * @author [Ioannis Margaris]

 * @create date 28 Aug. 2020 - 12:06:51

 * @desc [In a previous section, we have looked at a code example which came pretty close to the functionality of 
 * a monitor object : the class WaitingVehicles. 
 * Let us modify and partially re-implement this class, which we want to use as a shared place where concurrent threads may store data, 
 * in our case instances of the class Vehicle. As we will be using the same WaitingVehicles object for all the threads, we have to pass it 
 * to them by reference - and as all threads will be writing to this object at the same time (which is a mutating operation) we will pass it
 * as a shared pointer. 
 * 
 * Keep in mind that there will be many threads that will try to pass data to the WaitingVehicles object simultaneously and thus 
 * there is the danger of a data race.
 * 
 * Instead of using push_back we will again be using emplace_back to construct the futures in place rather than moving them into the vector. 
 * After constructing a new Vehicle object within the for-loop, we start a new task by passing it a reference to the pushBack function, 
 * a shared pointer to our WaitingVehicles object and the newly created vehicle.
 * 
 * Now let us take a look at the implementation of the WaitingVehicle object.
 * Our storage container will be an std::vector. As we need to protect the vector from simultaneous access later, we also need to integrate a mutex
 * into the class. As we already know, a mutex has the methods lock and unlock. In order to avoid data races, the mutex needs to be locked every time 
 * a thread wants to access the vector and it needs to be unlocked one the write operation is complete. In order to avoid a program freeze due to 
 * a missing unlock operation, we will be using a lock guard object, which automatically unlocks once the lock object gets out of scope.
 * 
 * In our modified pushBack function, we will first create a lock guard object and pass it the mutex member variable. 
 * Now we can freely move the Vehicle object into our vector without the danger of a data race
 * 
 * Another function within the WaitingVehicle class is printIDs(), which loops over all the elements of the vector and prints their respective IDs 
 * to the console. One major difference between pushBack() and printIDs() is that the latter function accesses all Vehicle objects by 
 * looping through the vector while pushBack only accesses a single object - which is the newest addition to the Vehicle vector.]

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

    void printIDs()
    {
        std::lock_guard<std::mutex> myLock(_mutex); // lock is released when myLock goes out of scope
        for(auto &v : _vehicles)
            std::cout << "   Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
        
    }

    void pushBack(Vehicle &&v)
    {
        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl; 
        _vehicles.emplace_back(std::move(v));

        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    std::mutex _mutex;
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

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Collecting results..." << std::endl;
    queue->printIDs();

    return 0;
}