import java.util.Scanner;

public class Palindromer {
  static boolean isPalindrome(String myWord, int lower, int upper) {
    boolean isPal = true;
    // if the start and end characters are unequal, the string is not a palindrome
    if(myWord.charAt(lower) != myWord.charAt(upper)) isPal = false;
    lower++;  // iterate and decrement position counters
    upper--;
    // if the string still may be a palindrome and the position counters have not intersected, call isPalindrome recursively
    if(isPal && upper >= lower) isPalindrome(myWord, lower, upper);
    return isPal;
  }

  public static void main(String[] args) {
    String myWord;
    Scanner myScanner = new Scanner(System.in);
    System.out.println("Enter a word and to be checked for palindromicity. Return an empty line to exit.");

    while(true) {
      System.out.print("Enter word: "); // prompt user for input
      myWord = myScanner.nextLine();
      if(myWord.equals("")) break;      // break if user returns empty line
      // call isPalindrome function with 0 and word length for args, declare palindromicity based on function output
      if(isPalindrome(myWord.toLowerCase(), 0, myWord.length() - 1)) System.out.println(myWord + " is a palindrome!");
      else System.out.println(myWord + " is NOT a palindrome!");
    }
  }
}
