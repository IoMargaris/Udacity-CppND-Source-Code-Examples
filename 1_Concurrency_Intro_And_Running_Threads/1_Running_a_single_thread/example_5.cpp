/*
Date: 13 Aug. 2020
Author: Ioannis Margaris

In this example, the .join() has been moved to before the work in main(). 
Now, the order of execution is always the same.
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

    t.join(); // Waits for thread to fininsh before continuing

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in main!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main!\n";

    return 0;
}
