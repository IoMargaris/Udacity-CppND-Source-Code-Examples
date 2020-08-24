/*
Date: 13 Aug. 2020
Author: Ioannis Margaris

Executing the code several times shows that the program output interchanges in a seemingly random manner.
This element of randomness is an important characteristic of concurrent programs and we have to take measures to deal with it in a controlled way 
that prevent unwanted behavior or even program crashes.

The order of execution is determined by the scheduler!
*/

#include <iostream>
#include <thread>

void thread_function()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate some work
    std::cout << "Finished work 1 in thread!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate some work
    std::cout << "Finished work 2 in thread!\n";
}

int main()
{
    std::thread t(thread_function);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in main!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main!\n";

    t.join(); // Waits for thread to fininsh before returning 

    return 0;
}
