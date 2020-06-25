// Java version of the stack delimiter program
import java.util.*;

public class StackDelimiter {
  static boolean balanceCheck(String userInput) {
    Stack<Character> delimStack = new Stack<>();
    boolean isBalanced = true;
    int stringLength = userInput.length();

    for(int i = 0; i < stringLength; i++) {
      // push opening delimting characters into the Stack
      if((userInput.charAt(i) == '[') || (userInput.charAt(i) == '{') || (userInput.charAt(i) == '(')) delimStack.push(userInput.charAt(i));

      // detect closing delimiting characters and evaluate balance
      else if((userInput.charAt(i) == ']') || (userInput.charAt(i) == '}') || (userInput.charAt(i) == ')')) {
        if(delimStack.empty()) isBalanced = false;  // a closing delimitng character with no complement is an automatic failure
        // remove delimiting characters
        else if((delimStack.peek() == '[' && userInput.charAt(i) == ']') || (delimStack.peek() == '{' && userInput.charAt(i) == '}') || (delimStack.peek() == '(' && userInput.charAt(i) == ')')) delimStack.pop();
      }
    }

    if(!(delimStack.empty())) isBalanced = false;

    return isBalanced;
  }

  public static void main(String[] args) {
    Scanner myScanner = new Scanner(System.in);
    // poll user for input
    System.out.println("Enter a string delimited by brackets, parentheses, or braces.");
    String userInput = myScanner.nextLine();
    if(balanceCheck(userInput)) System.out.println("This string is properly delimited.");
    else System.out.println("This string is NOT properly delimited.");
  }
}
