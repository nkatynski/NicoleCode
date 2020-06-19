// Program to confirm proper bracket/brace/parenthesis delimiting in a string

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool balanceCheck(string userInput)
{
  bool isBalanced = true;
  int stringLength = userInput.length();
  stack <char> delimStack;  // stack for storing delimiting characters

  for(int i = 0; i < stringLength; i++) {
      // push opening delimiting characters into the stack
      if(userInput[i] == '[' || userInput[i] == '{' || userInput[i] == '(') delimStack.push(userInput[i]);

      // detect closing delimiting characters and evaluate balance
      else if(userInput[i] == ']' || userInput[i] == '}' || userInput[i] == ')') {
        if(delimStack.empty()) isBalanced = false;  // a closing delimiting character with no complement in the stack is an automatic failure

      // remove matching delimiting characters
        else if((delimStack.top() == '[' && userInput[i] == ']') || (delimStack.top() == '{' && userInput[i] == '}') || (delimStack.top() == '(' && userInput[i] == ')')) delimStack.pop();
      }
  }

  // if there are still elements in the stack after removing all matching delimiting characters, the string is improperly delimited
  if(!(delimStack.empty())) isBalanced = false;

  return isBalanced;
}

int main()
{
  string userInput;

  // poll user for input
  cout << "Enter a string delimited by brackets, parentheses or braces." << endl;
  cin >> userInput;
  if(balanceCheck(userInput)) cout << "This string is properly delimited." << endl;
  else cout << "This string is NOT properly delimited." << endl;

  return 0;
}
