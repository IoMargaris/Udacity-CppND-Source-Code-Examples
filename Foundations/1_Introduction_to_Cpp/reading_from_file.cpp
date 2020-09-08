/**
 * @author [Ioannis Margaris]

 * @desc [In C++, you can use the `std::ifstream` object to handle input file streams. 
 * To do this, you will need to include the header file that provides the file streaming classes: `<fstream>`. 
 * 
 * C++ `ifstream` objects can also be used as a boolean to check if the stream has been created successfully.
 * If the stream were to initialize successfully, then the `ifstream` object would evaluate to `true`. 
 * If there were to be an error opening the file or some other error creating the stream, 
 * then the `ifstream` object would evaluate to `false`.
 * 
 * If the input file stream object has been successfully created, the lines of the input stream can be read using the `getline` method.
 * 
 * There are essentially four steps to reading a file:
 * 1. `#include <fstream>`
 * 2. Create a `std::ifstream` object using the path to your file.
 * 3. Evaluate the `std::ifstream` object as a `bool` to ensure that the stream creation did not fail.
 * 4. Use a `while` loop with `getline` to write file lines to a string.]
 */

#include <fstream>
#include <iostream>
#include <string>

int main() 
{
    std::ifstream my_file;
    my_file.open("files/1.board");
    if (my_file) 
    {
        std::cout << "The file stream has been created!" << "\n";
        std::string line;
        while (getline(my_file, line)) 
        {
            std::cout << line << "\n";
        }
    }
}