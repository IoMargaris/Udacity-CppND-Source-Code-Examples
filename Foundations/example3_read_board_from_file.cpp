/**
 * @author [author]

 * @desc [Write a function void ReadBoardFile which reads lines from a file. 
 * Write each line to cout, followed by a newline character "\n". The function should accept a string argument, 
 * which represents the path to the file. For now, since ReadBoardFile does not need to return anything, you can use a void return type.
 * 
 * Call ReadBoardFile from main using the argument "1.board".]
 */


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::string;
using std::vector;
using std::ifstream;

void ReadBoardFile(string path)
{
  ifstream my_file(path);
  if(my_file){
    cout << "The file can be opened" << "\n";
    string line;
    while(getline(my_file, line)){    
    	cout << line << "\n";
    }
  }
  
}

int main() 
{
  string path = "1.board";
  ReadBoardFile(path);
}