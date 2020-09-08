/**
 * @author [Ioannis Margaris]

 * @desc [It is helpful to manually declare the type of a variable if you want the variable type to be clear 
 * for reader of your code, or if you want to be explicit about the number precision being used; C++ has several number types
 * with different levels of precision, and this precision might not be clear from the value being assigned.]
 */

#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() 
{
    // Declare and initialize v using auto here.
    auto v = {7, 8, 9, 10};
    for (int i : v)
        cout << i << " ";
    cout << "\n";
}