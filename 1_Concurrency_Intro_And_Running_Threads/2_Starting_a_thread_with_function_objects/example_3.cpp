/* 
Date: 14 Aug. 2020
Author: Ioannis Margaris

In this code example, the class Vehicle has a constructor that takes an integer and it will store it internally in a variable _id.
In the overloaded function call operator, the vehicle id is printed to the console.
In main(), we are creating the Vehicle object using copy initialization
*/

#include <iostream>
#include <thread>

class Vehicle
{
private:
    int _id;
public:
    Vehicle(int id) : _id(id){}
    void operator ()()
    {
        std::cout << "Vehicle #" << _id << " has been created!" << std::endl;
    }
};


int main()
{
    std::thread t = std::thread(Vehicle(1)); // Copy initialization

    std::cout << "Finished work in main!" << std::endl; // Simulate work in main

    t.join(); // Wait for threads to finish


    return 0;
}