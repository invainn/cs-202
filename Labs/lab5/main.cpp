#include <iostream>
#include "Gcd.h"
using namespace std;

int main() {
  int n1, n2;
  Gcd g;

   cout << "Enter two positive integers: ";
   cin >> n1 >> n2;

   cout << "G.C.D of " << n1 << " & " <<  n2 << " is: " << g.gcdCalculate(n1, n2) << endl;

   return 0;
}


