/**
 * @author [Ioannis Margaris]

 * @create date 21 Aug. 2020 11:08:14

 * @desc [In the following example, the signature of the thread function is modified to take a non-const reference to the string instead.
 * Even though the code works, we are now sharing mutable data between threads - 
 * which will be something we discuss in later sections of this course as a primary source for concurrency bugs]
 
 */

#include <iostream>
#include <thread>
#include <string>

void printName(std::string &name, int waitTime)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    name += " (from Thread)";
    std::cout << name << std::endl;
}

int main()
{
    std::string name("MyThread");

    // starting thread
    std::thread t(printName, std::ref(name), 50);

    // wait for thread before returning
    t.join();

    // print name from main
    name += " (from Main)";
    std::cout << name << std::endl;

    return 0;
}