/**
 * @author [Ioannis Margaris]

 * @desc [To begin, it is helpful to know how to access vector elements of an existing vector.]
 */


#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() 
{
    vector<int> a = {0, 1, 2, 3, 4};
    // Add some code here to access and print elements of a.
    for (int i : a)
        cout << a[i] << " ";
    cout << "\n";
    cout << a[10]; // out of bounds that will not produce an error
}