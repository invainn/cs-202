#include <iostream>
#include <math.h>

#include "Project7.h"

using namespace std;

Polynomial::Polynomial() {
	this->maxDeg = 3;
	this->coeffs = NULL;
}

Polynomial::Polynomial(int deg, int* max) {
	this->maxDeg = deg;
	
	this->coeffs = new int[this->maxDeg+1];
	
	for(int i = 0; i < this->maxDeg+1; i++) {
		this->coeffs[i] = max[i];
	}

}

Polynomial::Polynomial(const Polynomial& src) {
	int* tempDest = this->coeffs;
	int* tempSrc = src.coeffs;

	this->maxDeg = src.maxDeg;

	this->coeffs = new int[this->maxDeg];

	for(int i = 0; i < src.maxDeg; i++) {
		*tempDest = *tempSrc;
		tempDest++;
		tempSrc++;
	}

	tempDest = NULL;
	tempSrc = NULL;
}

Polynomial::~Polynomial() {
	if(this->coeffs != NULL) {
		delete [] this->coeffs;
	}
}


// fix this, this->coeffs is reversed
int Polynomial::solve(int x) {
	int result = 0;
	int pwr = this->maxDeg;

	for(int i = 0; i < this->maxDeg+1; i++) {
		if(pow == 0) {
			result += this->coeffs[i];
		} else {
			result += (this->coeffs[i]*pow(x, pwr));
			pwr--;
		}
	}

	return result;
}

Polynomial& Polynomial::operator=(const Polynomial& src) {
	this->maxDeg = src.maxDeg;
	for(int i = 0; i < this->maxDeg; i++) {
		this->coeffs[i] = src.coeffs[i];
	}
}

bool Polynomial::operator==(const Polynomial& src) const {
	if(this->maxDeg != src.maxDeg) {
		return false;
	}

	for(int i = 0; i < this->maxDeg; i++) {
		if(this->coeffs[i] != src.coeffs[i]) {
			return false;
		}
	}

	return true;
}

bool Polynomial::operator!=(const Polynomial& src) const {
	if(this->maxDeg != src.maxDeg) {
		return true;
	}

	for(int i = 0; i< this->maxDeg; i++) {
		if(this->coeffs[i] != src.coeffs[i]) {
			return true;
		}
	}

	return false;
}

Polynomial& Polynomial::operator*(const Polynomial& src) const {
	int* newCoeff = new int[this->maxDeg + src.maxDeg +1];

	for(int i = 0; i < this->maxDeg; i++) {
		for(int j = 0; j < src.maxDeg; i++) {
			newCoeff[i+j] += this->coeffs[i] * src.coeffs[j];
		}
	}

	Polynomial result(this->maxDeg + src.maxDeg, newCoeff);

	delete [] newCoeff;
	newCoeff = NULL;
}

Polynomial& Polynomial::operator*(int src) {
	for(int i = 0; i < this->maxDeg+1; i++) {
		this->coeffs[i] *= src;
	}
}

Polynomial& Polynomial::operator+(const Polynomial& src) {
	if(this->maxDeg == src.maxDeg) {
		for(int i = 0; i < this->maxDeg+1; i++) {
			this->coeffs[i] += src.coeffs[i];
		}
	} else if(this->maxDeg > src.maxDeg) {
		for(int i = 0; i < src.maxDeg+1; i++) {
			this->coeffs[i+(this->maxDeg-src.maxDeg)] += src.coeffs[i];
		}
	} else if(this->maxDeg < src.maxDeg) {
		for(int i = 0; i < this->maxDeg+1; i++) {
			this->coeffs[i] += src.coeffs[i+(this->maxDeg-src.maxDeg)];
		}
	}
}

Polynomial& Polynomial:: operator-(const Polynomial& src) {
	if(this->maxDeg == src.maxDeg) {
		for(int i = 0; i < this->maxDeg+1; i++) {
			this->coeffs[i] -= src.coeffs[i];
		}
	} else if(this->maxDeg > src.maxDeg) {
		for(int i = 0; i < src.maxDeg+1; i++) {
			this->coeffs[i+(this->maxDeg-src.maxDeg)] -= src.coeffs[i];
		}
	} else if(this->maxDeg < src.maxDeg) {
		for(int i = 0; i < this->maxDeg+1; i++) {
			this->coeffs[i] -= src.coeffs[i+(this->maxDeg-src.maxDeg)];
		}
	}
}

ostream& operator<<(ostream& os, const Polynomial& src) {
	for(int i = 0; i < src.maxDeg+1; i++) {
		cout << src.coeffs[i] << " ";
	}
	
	cout << endl;
	
	return os;
}

istream& operator>>(istream& dataFile, Polynomial& src) {
	dataFile >> src.maxDeg;
	
	for(int i = 0; i < src.maxDeg+1; i++) {
		dataFile >>src.coeffs[i];
	}
	
	return dataFile;
}


// when writing stream in function, use max degree to count how many coefficients
// should be n+1