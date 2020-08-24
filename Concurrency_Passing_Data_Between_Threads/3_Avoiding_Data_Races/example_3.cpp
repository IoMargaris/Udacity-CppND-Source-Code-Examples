/**
 * @author [Ioannis Margaris]

 * @create date 24 Aug. 2020 - 16:24:23

 * @desc [Even though a customized copy constructor can help us to avoid data races, it is also time (and memory) consuming.
 * In the following, we will use move semantics to implement a more effective way of safely passing data to a thread
 * 
 * To define a move constructor for a C++ class, the following steps are required:
 * 1. Define an empty constructor method that takes an rvalue reference to the class type as its parameter
 * 2. In the move constructor, assign the class data members from the source object to the object that is being constructed
 * 3. Assign the data members of the source object to default values.
 
 * Note: When launching the thread, the Vehicle object v0 can be passed using std::move() -
 * which calls the move constructor and invalidates the original object v0 in the main thread]

 */

#include <iostream>
#include <thread>
#include <future>

class Vehicle
{
public:
    //default constructor
    Vehicle() : _id(0), _name(new std::string("Default Name"))
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    //initializing constructor
    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name))
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }

    // copy constructor 
    Vehicle(Vehicle const &src)
    {
        //...
        std::cout << "Vehicle #" << _id << " copy constructor called" << std::endl;
    };

    // move constructor 
    Vehicle(Vehicle && src)
    {
        _id = src.getID();
        _name = new std::string(src.getName());

        src.setID(0);
        src.setName("Default Name");

        std::cout << "Vehicle #" << _id << " move constructor called" << std::endl;
    };

    // setter and getter
    void setID(int id) { _id = id; }
    int getID() { return _id; }
    void setName(std::string name) { *_name = name; }
    std::string getName() { return *_name; }

private:
    int _id;
    std::string *_name;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0;    // default constructor
    Vehicle v1(1, "Vehicle 1"); // initializing constructor

    // launch a thread that modifies the Vehicle name
    std::future<void> ftr = std::async([](Vehicle v) {
        v.setName("Vehicle 2");
    },std::move(v0));

    ftr.wait();
    std::cout << v0.getName() << std::endl;

    return 0;
}