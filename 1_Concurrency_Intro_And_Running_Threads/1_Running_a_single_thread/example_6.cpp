/*
Date: 13 Aug. 2020
Author: Ioannis Margaris

In the following example, detach() is called on the thread object, 
which causes the main thread to immediately continue until it reaches the end of the program code and returns.

Note: that a detached thread can not be joined ever again
*/

#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread\n"; 
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // detach thread and continue with main
    t.detach();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    return 0;
}