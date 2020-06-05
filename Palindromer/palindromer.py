# palindrome program in Python

import sys

def isPalindrome(myWord, lower, upper):
    isPal = True

    if myWord[lower] != myWord[upper]:
        isPal = False
    lower += 1
    upper -= 1

    if(isPal and upper >= lower):       # python uses words for conditionals, not symbols
        isPalindrome(myWord, lower, upper)
    return(isPal)

print("Enter a word for the program to check for palindromicity. To exit, return a blank line.")
upper = lower = 0                       # initialize upper and lower bound variables

while True:                             # run forever
    myWord = input("Enter word: ")      # accept user input
    if myWord == "":
        sys.exit(0)                     # exit on blank input - it's that easy in Python
    upper = len(myWord) - 1             # get length of new input word

    if isPalindrome(myWord.lower(), lower, upper):
        print(myWord + " is a palindrome!")
    else:
        print(myWord + " is NOT a palindrome!")
