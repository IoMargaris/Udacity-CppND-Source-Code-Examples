/**
 * @author [Ioannis Margaris]
 
 * @create date 21 Aug. 2020 - 09:40:21

 * @desc [Starting a thread with a Variadic Template. The thread constructor may be called with a function and all its arguments. 
 * That is possible because the thread constructor is a variadic template that takes multiple arguments]

 */

#include <iostream>
#include <thread>
#include <string>

void PrintID(int id)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID = " << id << std::endl;
}


void PrintIDAndName(int id, std::string name) 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID = " << id << std::endl;
}

int main() 
{

    int id = 0; // Define an integer variable

    // starting threads using variadic templates
    std::thread t1(PrintID, id);
    std::thread t2(PrintIDAndName, ++id, "MyString");
    //std::thread t3(printIDAndName, ++id); // this procudes a compiler error

    // wait for threads before returning
    t1.join();
    t2.join();
    //t3.join();
}
