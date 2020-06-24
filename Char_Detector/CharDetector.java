// This is the java implementation of the CharDetector program.

import java.lang.*;

public class CharDetector {
  static int charDetector(String sentence, char searchLetter) {
    int letterInstances = 0;
    for(int i = 0; i < sentence.length(); i++) {
      if(Character.toLowerCase(sentence.charAt(i)) == Character.toLowerCase(searchLetter)) letterInstances++;
    }
    return letterInstances;
  }

  public static void main(String[] args) {
    String sentence = "I am the very model of a modern major general.";
    char searchLetter = 'e';

    System.out.println("Starting sentence: " + sentence);
    int letterInstances = charDetector(sentence, searchLetter);
    System.out.println(searchLetter + " is featured " + letterInstances + " times.");
  }
}
