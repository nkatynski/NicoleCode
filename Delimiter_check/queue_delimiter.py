# Program to confirm proper bracket/brace/parenthesis delimiting in a stringLength

# Queue implemented using collections module
from collections import deque

def balanceCheck(userInput):
    counter = 0
    isBalanced = True
    delimQueue = deque()                                    # our queue is technically a deque, but whatever

    for i in userInput:                                     # iterate through user input string
        if userInput[counter] == ('[' or '{' or '('):       # detect opening delimiting character
            delimQueue.append(userInput[counter])           # enqueue opening delimiting character to stack
        elif userInput[counter] == (']' or '}' or ')'):     # detect closing delimiting character
            if not delimQueue:
                isBalanced = False                          # a closing bracket with an empty stack means automatic failure
            # remove matching delimiting characters - there has got to be a more graceful way to do that
            elif ((delimQueue[-1] == '[') and (userInput[counter] == ']')) or (delimQueue[-1] == '{') and (userInput[counter] == '}') or (delimQueue[-1] == '(') and (userInput[counter] == ')'):
                delimQueue.popleft()
        counter += 1

    if delimQueue:                                          # any elements remaining after matching/dequeueing is finished indicates failure
        isBalanced = False
    return isBalanced

# poll user for phrase to check
userInput = input("Enter a string delimited by brackets, parentheses, or braces: ")

if(balanceCheck(userInput)):    # run balance check function
    print("This string is properly delimited.")
else:
    print("This string is NOT properly delimited.")
