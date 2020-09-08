/**
 * @author [author]

 * @desc [Unfortunately, there isn't a built-in way to print vectors in C++ using `cout`. 
 * You will learn how to access vector elements and you will write your own function to print vectors later. 
 * For now, you can see how vectors are created and stored. Below, you can see how to nest vectors to create 2D containers.]
 */

#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() 
{
    // Creating a 2D vector.
    vector<vector<int>> v {{1,2}, {3,4}};
    cout << "Great! A 2D vector has been created." << "\n";

    // Printing a 1d vector
    vector<int> v2{6,7,8};
    for(int i : v2)
        cout << i << " ";
    cout << "\n";
}