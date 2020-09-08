/* 
Date: 13 Aug. 2020
Author: Ioannis Margaris

Prints the thread identifier of the main thread and outputs it to the console
*/

#include <iostream>
#include <thread>

int main()
{
    std::cout << "Hello concurrent world from main!" << std::endl << "Thread ID = " << std::this_thread::get_id() << std::endl;
    return 0;
}
