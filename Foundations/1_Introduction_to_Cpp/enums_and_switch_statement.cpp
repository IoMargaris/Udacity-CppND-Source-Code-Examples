/**
 * @author [Ioannis Margaris]

 * @desc [C++ allows you to define a custom type which has values limited to a specific range you list or "enumerate". 
 * This custom type is called an "enum".
 * 
 * Note: The keyword `enum` is followed by the keyword `class` and then the class name Direction. This creates what are called "scoped" `enum`s.]
 */

#include <iostream>
using std::cout;

int main()
{
    enum class Direction {kUp, kDown, kLeft, kRight};

    Direction a = Direction::kDown;

    switch (a) {
      case Direction::kUp : cout << "Going up!" << "\n";
        break;
      case Direction::kDown : cout << "Going down!" << "\n";
        break;
      case Direction::kLeft : cout << "Going left!" << "\n";
        break;
      case Direction::kRight : cout << "Going right!" << "\n";
        break;
    }
}