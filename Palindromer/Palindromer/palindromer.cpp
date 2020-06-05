#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    string user_intake = "hello";

    while(1){
        cout << "Enter a word: ";
        getline(cin, user_intake);
        cout << user_intake << endl;

        if(user_intake.empty()) break;
    }

    return 0;
}
