/* 
Date: 14 Aug. 2020
Author: Ioannis Margaris

The following code example shows several ways of making the external variable "id" accessible within a Lambda
*/

#include <iostream>

int main()
{
    // Creating Lamda expressions (aka "Lamdas")

    int id = 0;

    //auto f0 = [] () {std::cout << "ID = " << id << std::endl;}; // Error as "id" cannot be accessed

    id++;
    auto f1 = [id] () {std::cout << "ID = " << id << std::endl;}; // "id" is captured by value

    id++;
    auto f2 = [&id] () {std::cout << "ID = " << id << std::endl;}; // "id" is captured by reference

    //auto f3 = [id] () {std::cout << "ID = " << ++id << std::endl;}; // Error as "id" cannot be modified by Lamda

    auto f4 = [id] () mutable {std::cout << "ID = " << ++id << std::endl;}; // "id" can be modifed with the use of the "mutable" keyword

    // Executing Lamdas

    //f0();
    f1();
    f2();
    //f3();
    f4();

    return 0;
}