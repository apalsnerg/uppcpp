#include <iostream>
using namespace std;

int main(){

  int a;
  int b = 12;
  a = 0;

  cout << "a = " << a << "\n";
  cout << a+b << "\n" << "a-b = " << a-b << "\n";

  double c;
  cout << "Enter a number..." << "\n" << ">> ";
  cin >> c;
  cout << "c + b = " << c + b << "\n";
  cout << "c - b = " << c - b << "\n";
  cout << "c * b = " << c * b << "\n";
  cout << "c / b = " << c / b << "\n";

  return 0;
}
