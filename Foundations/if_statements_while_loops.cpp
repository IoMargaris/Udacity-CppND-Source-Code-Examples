/**
 * @author [Ioannis Margaris]
 */

#include <iostream>
using std::cout;

int main() 
{
    auto i = 0;

    while (i < 5) {
      cout << i << "\n";
      i++;
    }

    int number = 0;
    while(number < 10)
    {
        if(number % 2 == 0)
        {
            cout << number << "\n";
        }
        number++;
    }

}