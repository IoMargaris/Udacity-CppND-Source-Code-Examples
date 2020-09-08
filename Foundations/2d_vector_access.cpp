/**
 * @author [author]

 * @desc [In the previous exercise, you stored a 2D vector - a `vector<vector<int>>`. 
 * The syntax for accessing elements of a 2D vector is very similar to accessing in a 1D vector. 
 * In the second cell below, try accessing an element of `b`.]
 */

#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() 
{
    vector<vector<int>> b = {{1, 1, 2, 3},
                             {2, 1, 2, 3},
                             {3, 1, 2, 3}};
    cout << b[2][0] << "\n";
    
}