#include <iostream>
#include <string>
using namespace std;

int charDetector(string sentence, char searchLetter)
{
  int sentenceLength = sentence.length();
  int letterInstances = 0;

  for(int i = 0; i < sentenceLength; i++){
    if(char(sentence[i]) == searchLetter) letterInstances++;
  }

  return letterInstances;
}

int main()
{
  string sentence = "I am the very model of a modern major general.";
  char searchLetter = 'e';

  cout << "Starting sentence: " << sentence << endl;
  int letterInstances = charDetector(sentence, searchLetter);
  cout << searchLetter << " is featured " << letterInstances << " times." << endl;

  return 0;
}
