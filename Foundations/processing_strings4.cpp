/**
 * @author [Ioannis Margaris]

 * @desc [In the stream example before, the string contained only whitespaces and characters which could be converted to `int`s. 
 * If the string has mixed types, more care is needed to process the string. In the following example, the type `char` is used, 
 * which is a type that can hold only a single ASCII character.
 * 
 * Notice that the `3` was not printed! The expression: "my_stream >> n >> c" tried to stream an `int` followed by a `char`. 
 * Since there was no `char` after the `3`, the stream failed and the `while` loop exited.]
 */

#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main() 
{
    string b("1,2,3");

    istringstream my_stream(b);

    char c;
    int n;

    while (my_stream >> n >> c) {
      cout << "That stream was successful: " << n << " " << c << "\n";
    }
    cout << "The stream has failed." << "\n";
}