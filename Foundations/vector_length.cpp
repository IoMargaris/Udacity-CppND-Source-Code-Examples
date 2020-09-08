/**
 * @author [author]

 * @desc [One method of a `vector` object that will be useful in the next code exercise is the `.size()` method. 
 * This returns the length of the vector. ]
 */

#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() {
    vector<int> a = {0, 1, 2, 3, 4};
    
    // Print the length of vector a to the console.
    cout << a.size() << "\n";

    // For the `vector<vector<int>>` `b` defined above, try to get the size of one of the inner vectors - this should be 4
    vector<vector<int>> b = {{1, 1, 2, 3},
                             {2, 1, 2, 3},
                             {3, 1, 2, 3}};
    // Print the length of an inner vector of b here.
    cout << b[0].size() << "\n";
}