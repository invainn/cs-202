#include <iostream>
#include <fstream>
#include "Project7.h"

using namespace std;

int main() {

	Polynomial* ex1;

	ifstream DataFile;

	int menuchoice = 0;
	int numOfPoly = 0;

	cout << "Polynomial Menu" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Read data from file" << endl;
	cout << "2. Print Polynomials" << endl;


	while(true) {
		cin >> menuchoice;
		cout << endl;
		cout << numOfPoly;

		switch(menuchoice) {
			case 1:
			{
				cout << numOfPoly;
				DataFile.open("datafile");

				cout << numOfPoly;

				DataFile >> numOfPoly;

				cout << numOfPoly;

				ex1 = new Polynomial[numOfPoly];

				for(int i = 0; i < numOfPoly; i++) {
					DataFile >> ex1[i];
				}

				DataFile.close();
				break;
			}
			case 2:
			{
				for(int i = 0; i < numOfPoly; i++) {
					cout << ex1[i];
				}

				break;
			}
			default:
			{
				cout << "Not a valid option" << endl;
				cout << "> ";
				break;
			}
		}
	}




	return 0;
}
