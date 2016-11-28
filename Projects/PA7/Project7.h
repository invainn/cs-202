#include <iostream>

using namespace std;

class Polynomial {

	public:
		Polynomial();
		Polynomial(int, int*);
		Polynomial(const Polynomial&);
		~Polynomial();

		int solve(int);

		Polynomial& operator=(const Polynomial&);
		bool operator==(const Polynomial&) const;
		bool operator!=(const Polynomial&) const;
		Polynomial& operator*(const Polynomial&);
		Polynomial& operator*(int);
		Polynomial& operator+(const Polynomial&);
		Polynomial& operator-(const Polynomial&);

		friend ostream& operator<<(ostream&, const Polynomial&);
		friend istream& operator>>(istream&, const Polynomial&);

	private:
		int* coeffs;
		int maxDeg;
};