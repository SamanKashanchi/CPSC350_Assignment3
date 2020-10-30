#include <iostream>
#include "Genstack.h"
#include "SyntaxCheck.cpp"
using namespace std;

int main(int argc, char** argv) {
char choice = 'n';
if(argc > 1) {
//A do while loop for reprompting the user if they want to input new file
  do{
    string UserInput = argv[1];
//Insiating stack baced
    SyntaxCheck checker(UserInput);
//Calling DelimiterCheck to see if syntax is correct
    checker.DelimiterCheck();
    while(true){
      cout << "Type 'c' to continue with a new txt file or press anykey to quit." << endl;
      cin >> choice;
//Reprompts the user for new file name
      if(choice == 'c'){
        cout << "Enter a new file name: ";
        cin >> argv[1];
        break;
      }
      else{
        cout << "Quiting Syntax Checker ..........." << endl;
        break;
      }
    }
  }while(choice == 'c');
  }
//error checking if user dosnt input command line inout
else {
  cout << "You have enterd no file name." << endl;
  }
}
