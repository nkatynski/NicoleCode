#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool isPalindrome(string str, int lower, int upper)
{
    bool isPal = true;
    if (tolower(str[lower]) != tolower(str[upper])) isPal = false;

    upper--;
    lower++;

    if (isPal && (upper >= lower)) isPal = isPalindrome(str, lower, upper);
    return(isPal);
}

int main()
{
    string myWord;

    //user prompt
    cout << "Enter a word in lowercase and I will determine if it is a palindrome" << endl;
    cout << "Return an empty line to exit\n" << endl;

    //default values for lower and upper are beginning/end of string
    int upper = 0;
    int lower = 0;

    //loop to poll user and analyze input
    while(1)
    {
        //take user input
        cout << "Enter word: ";
        getline(cin, myWord);
        upper = myWord.length() - 1; //upper and lower default to the beginning and end of the user input

        //if the line is empty, break
        if(myWord.empty()) break;

        //call function to determine if palindrome
        if (isPalindrome(myWord, lower, upper)) cout << myWord << " IS a palindrome" << endl << endl;
        else cout << myWord << " is NOT a palindrome" << endl << endl;
    }

    return 0;
}
