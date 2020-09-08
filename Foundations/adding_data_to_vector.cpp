/**
 * @author [Ioannis Margaris]

 * @desc [Let's store the streamed `int`s from each line of the board in a `vector<int>`. 
 * To do this, you will add the `int`s to the back of the vector, using the `vector` method `push_back`]
 */

#include <vector>
#include <iostream>

using std::cout;

int main() 
{
    // Initial Vector
    std::vector<int> v {1, 2, 3};
    
    // Print the contents of the vector
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }
    
    // Push 4 to the back of the vector
    v.push_back(4);

    // Print the contents again
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }
    
}