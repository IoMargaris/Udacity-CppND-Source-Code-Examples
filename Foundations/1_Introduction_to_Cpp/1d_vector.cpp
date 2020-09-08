/**
 * @author [Ioannis Margaris]

 * @desc [C++ also has several container types that can be used for storing data. We will start with vector`s, 
 * as these will be used throughout this lesson, but we will also introduce other container types as needed. 
 * Vectors are a sequence of elements of a single type, and have useful methods for getting the size, testing 
 * if the vector is empty, and adding elements to the vector.]
 */


#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() 
{
    // Three ways of declaring and initializing vectors.
    vector<int> v_1{0, 1, 2};
    vector<int> v_2 = {3, 4, 5};
    vector<int> v_3;
    v_3 = {6};
    cout << "Everything worked!" << "\n";
}