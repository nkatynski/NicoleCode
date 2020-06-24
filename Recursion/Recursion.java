// The object of this program is to perform a recursive factoring operation to determine the degree of a given factor of an integer.
// The Scanner class does the legwork of managing user input.
import java.util.Scanner;

// Important that your .java file have a public class matching the filename.
public class Recursion {
  static int factor(int num, int div) {
    int fac = 0;
    if(num % div == 0) {
      fac = factor(num/div, div);
      fac++;
    }
    return fac;
  }

  public static void main(String[] args) {
    Scanner myScanner = new Scanner(System.in);

    System.out.print("Enter number to be factored: ");
    int number = myScanner.nextInt();
    System.out.print("Enter factor: ");
    int divisor = myScanner.nextInt();

    System.out.println(divisor + " factors into " + number + " " + factor(number, divisor) + " times.");
  }
}
