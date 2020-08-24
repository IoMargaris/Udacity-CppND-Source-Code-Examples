/* 
Date: 14 Aug. 2020
Author: Ioannis Margaris

The following example illustrates how the function object is first created and then used to pass the parameter id later in the code
*/

#include <iostream>

int main()
{
    int id = 0;

    auto f1 = [] (int id) {std::cout << "Id = " << ++id << std::endl;}; // "id" is passed as a parameter // "id" can also be modified if passed as parameter

    // Execute the Lamda and pass "id" as an argument
    f1(id);

    return 0;
}