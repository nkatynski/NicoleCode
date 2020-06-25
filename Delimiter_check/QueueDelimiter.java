// Java version of the queue delimiter program
import java.util.*;

public class QueueDelimiter {
  static boolean balanceCheck(String userInput) {
    Queue<Character> delimQueue = new PriorityQueue<>();
    boolean isBalanced = true;
    int stringLength = userInput.length();

    for(int i = 0; i < stringLength; i++) {
      // add opening delimting characters to the Queue
      if((userInput.charAt(i) == '[') || (userInput.charAt(i) == '{') || (userInput.charAt(i) == '(')) delimQueue.add(userInput.charAt(i));

      // detect closing delimiting characters and evaluate balance
      else if((userInput.charAt(i) == ']') || (userInput.charAt(i) == '}') || (userInput.charAt(i) == ')')) {
        if(delimQueue.isEmpty()) isBalanced = false;  // a closing delimitng character with no complement is an automatic failure
        // remove delimiting characters
        else if((delimQueue.peek() == '[' && userInput.charAt(i) == ']') || (delimQueue.peek() == '{' && userInput.charAt(i) == '}') || (delimQueue.peek() == '(' && userInput.charAt(i) == ')')) delimQueue.remove();
      }
    }

    if(!(delimQueue.isEmpty())) isBalanced = false;

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
