/* 
Date: 14 Aug. 2020
Author: Ioannis Margaris

In the following code we start a thread and pass it a Lambda object (aka "Closure") to execute
*/

#include <iostream>
#include <thread>

int main()
{
    int id = 0;

    // Starting our first thread (by reference)
    auto f0 = [&id] () {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "a) ID in first Thread (call-by-reference) = " << id << std::endl;
    };
    std::thread t1(f0);

    // Starting a second thread (by value)
    std::thread t2([id] () mutable {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "b) ID in second Thread (call-by-value) = " << id << std::endl;
    });

    // increment "id" and print its value in main
    id++;
    std::cout << "c) ID in main (call-by-value) = " << id << std::endl;

    // Wait for Threads to finish before returning
    t1.join();
    t2.join();
    
    return 0;
}