/* 
Date: 13 Aug. 2020
Author: Ioannis Margaris

The code shows how to use join() to ensure that main() waits for the thread t to finish its operations before returning.
It uses the function sleep_for(), which pauses the execution of the respective threads for a specified amount of time.
The idea is to simulate some work to be done in the respective threads of execution
*/

#include <iostream>
#include <thread>

void thread_function()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout << "Finished work in thread!\n";
}

int main()
{
    std::thread t(thread_function);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main!\n";

    t.join(); // Waits for thread to fininsh before returning 

    return 0;
}