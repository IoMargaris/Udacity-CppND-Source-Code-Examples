/**
 * @author [Ioannis Margaris]

 * @desc [1. A simple function to add two numbers and return the result.
 *        2. A function should accept a vector of ints as its argument and return the sum of all the ints in the vector.]
 */

#include <iostream>
#include <vector>
#include <string>
using std::cout;

// Function declared and defined here.
int AdditionFunction(int i, int j) 
{
    return i + j;
}

/*
* The function should accept a `vector` of `int`s as its argument and return the sum of all the `int`s in the vector.
* @param v A vector of integers
*/
int AdditionFunction2(std::vector<int> &v)
{
    int sum = 0;
    for (int &i : v)
        sum = sum + i;
    
    return sum;
}

/*
* Sometimes a function doesn't need to return anything. For example, a function might simply modify an object that is passed into it, or it might just print to the terminal. If a function doesn't need to return a value, the `void` type can be used for the return type
* @param s1 first string
* @param s2 second string
*/
void PrintStrings(std::string s1, std::string s2)
{
    cout << s1 << s2 << "\n";
}

int main() 
{
    auto d = 3;
    auto f = 7;
    cout << AdditionFunction(d, f) << "\n";

    // Your function should accept a `vector` of `int`s as its argument and return the sum of all the `int`s in the vector.
    std::vector<int> v {1, 2, 3};
    cout << AdditionFunction2(v) << "\n";

    std::string s1 = "C++ is ";
    std::string s2 = "super awesome.";

    PrintStrings(s1, s2);
}