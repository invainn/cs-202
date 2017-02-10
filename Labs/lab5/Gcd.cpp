#include <iostream>
#include "Gcd.h"

Gcd::Gcd() {
  
}

Gcd::~Gcd() {
  
}

// euclidean algorithm
int Gcd::gcdCalculate(int n1, int n2) {
	if(n1 >= n2) {
		if((n1%n2) == 0) {
			return n2;
		} else {
			return gcdCalculate(n2, n1%n2);
		}
	} else {
		if((n2%n1) == 0) {
			return n1;
		} else {
			return gcdCalculate(n1, n2%n1);
		}
	}
}


