#include <iostream>
#include "Genstack.h"
#include <fstream>
using namespace std;

class SyntaxCheck
{

public:
//Appropriate member variables
  string InputFile;
  Genstack<char>* stack;

//Constructor for Class
SyntaxCheck(string UserInput) {
  InputFile = UserInput;
  stack = new Genstack<char>();
    }
//Method that checks syntax for delimiters
bool DelimiterCheck() {
  string line;
  ifstream file(InputFile);
  if(!file) {
    cout << "File not found." << endl;
    exit(0);
      }
      int numline = 1;
//Loops through file
      while(getline(file, line)) {
//Loops through lines
        for(int i = 0; i < line.length(); ++i) {
//Pushing Appropriate chars to stack
          if(line[i] == '(' || line[i] == '{' || line[i] == '[' || line[i] == ')' || line[i] == '}' || line[i] == ']') {
            if(line[i] == '(' || line[i] == '{' || line[i] == '[') {
              stack->push(line[i]);
            }
//Chacking conditions for missing opening delimiters
            else if(line[i] == ')' || line[i] == '}' || line[i] == ']') {
              if(stack->empty()) {
                cout << "Missing opening parameter for delimiter at line " << numline << endl;
                return false;
              }
//Chechking for missing opening parameters
              if(stack->peek() == '(' && line[i] != ')') {
                cout << "Missing ) at line " << numline << endl;
                return false;
              }
              else if(stack->peek() == '{' && line[i] != '}') {
                cout << "Missing } at line " << numline << endl;
                return false;
              }
              else if(stack->peek() == '[' && line[i] != ']') {
                cout << "Missing ] at line " << numline << endl;
                return false;
              }
              stack->pop();
            }
          }
        }
        numline++;
      }
      if(stack->empty()) {

        cout << "There are no delimiter errors in your code.  GOOD JOB" << endl;
      }
 //Cheking for end of the file errors
      else {
        if(stack->peek() == '(') {
          cout << "Reached end of file: missing )" << endl;
        }
        else if(stack->peek() == '{') {
          cout << "Reached end of file: missing }" << endl;
        }
        else if(stack->peek() == '[') {
          cout << "Reached end of file: missing ]" << endl;
        }

      }
      file.close();
    }

};
