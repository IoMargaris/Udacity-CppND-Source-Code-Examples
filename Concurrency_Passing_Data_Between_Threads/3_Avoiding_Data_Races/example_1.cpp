/**
 * @author [Ioannis Margaris]

 * @create date 24 Aug. 2020 - 13:28:54

 * @desc [ In this example, one safe way of passing data to a thread would be to carefully synchronize 
 * the two threads using either join()or the promise-future concept that can guarantee the availability of a result
 *
 * The class Vehicle has a default constructor and an initializing constructor. 
 * In the main function, when the instances v0 and v1 are created, each constructor is called respectively. 
 * Note that v0 is passed by value to a Lambda, which serves as the thread function for std::async. 
 * Within the Lambda, the id of the Vehicle object is changed from the default (which is 0) to a new value 2. 
 * Note that the thread execution is paused for 500 milliseconds to guarantee that the change is performed well after the main thread 
 * has proceeded with its execution.
 * In the main thread, immediately after starting up the worker thread, the id of v0 is changed to 3. 
 * Then, after waiting for the completion of the thread, the vehicle id is printed to the console]
 
 */

#include <iostream>
#include <thread>
#include <future>

class Vehicle
{
public:
    //default constructor
    Vehicle() : _id(0)
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    //initializing constructor
    Vehicle(int id) : _id(id)
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }

    // setter and getter
    void setID(int id) { _id = id; }
    int getID() { return _id; }

private:
    int _id;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0; // default constructor
    Vehicle v1(1); // initializing constructor

    // read and write name in different threads (which one of the above creates a data race?)
    std::future<void> ftr = std::async([](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
        v.setID(2);
    }, v0);

    v0.setID(3);

    ftr.wait();
    std::cout << "Vehicle #" << v0.getID() << std::endl;

    return 0;
}