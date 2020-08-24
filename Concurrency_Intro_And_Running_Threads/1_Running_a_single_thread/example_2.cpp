/* 
Date: 13 Aug. 2020
Author: Ioannis Margaris

Prints the number of CPU cores to the console
*/

#include <iostream>
#include <thread>

int main()
{
    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "This machine supports concurrency with " << nCores << " cores available!" << std::endl;

    return 0;
}