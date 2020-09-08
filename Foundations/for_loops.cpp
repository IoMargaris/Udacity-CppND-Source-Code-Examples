/**
 * @author [Ioannis Margaris]

 * @desc [description]
 */

#include <iostream>
#include <vector>
using std::cout;

int main() 
{
    // A simple `for` loop using an index variable has the following syntax. 
    for (int i=0; i < 5; i++) 
    {
      cout << i << "\n";
    }

    /*
    If you haven't seen the `++` operator before, this is the *post-increment operator*, and it is where the `++` in the name "C++" comes from. 
    The operator increments the value of `i`. There is also a *pre-increment operator* which is used before a variable, as well as *pre* and *post 
    decrement* operators: `--`. The difference between *pre* and *post* lies in what value is returned by the operator when it is used.
    */
    auto i = 1;

    // Post-increment assigns i to c and then increments i.
    auto c = i++;

    cout << "Post-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";
    cout << "The value of i is: " << i << "\n";
    cout << "\n";

    // Reset i to 1.
    i = 1;

    // Pre-increment increments i, then assigns to c.
    c = ++i;

    cout << "Pre-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";
    cout << "The value of i is: " << i << "\n";
    cout << "\n";

    // Decrement i;
    i--;
    cout << "Decrement example:" << "\n";
    cout << "The value of i is: " << i << "\n\n";

    // C++ offers several ways to iterate over containers. 

    // One way is to use an index-based loop as above. Another way is using a "range-based loop"
    std::vector<int> a {1, 2, 3, 4, 5};
    for (int i: a) 
    {
        cout << i << "\n\n";
    }

    // Iterating over a 2d vector
    std::vector<std::vector<int>> b {{1, 2},
                           {3, 4},
                           {5, 6}};
    for(auto v : b) 
    {
        for(int i : v) 
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}