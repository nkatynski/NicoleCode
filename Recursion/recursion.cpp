// recursive factoring function in C++

#include <iostream>
using namespace std;

int factor(int num, int div) //intake number and divisor (factor)
{
  int fac = 0;
  if((num % div) == 0) {
    fac = factor(num/div, div);
    fac++;
  }
  return(fac);
}

int main()
{
  int number, divisor, fac_count;
  cout << "Enter number to be factored: ";
  cin >> number;
  cout << "Enter factor: ";
  cin >> divisor;

  fac_count = factor(number,divisor);
  cout << divisor << " factors into " << number << " " << fac_count << " times." << endl;

  return(0);
}
