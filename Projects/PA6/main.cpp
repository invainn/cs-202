#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Agency.h"

using namespace std;

int main() {

	ifstream DataFile;

	int menuChoice = 0;

	Agency a1;

	// menu
	cout << "Car Rental Menu" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Read data from file" << endl;
	cout << "2. Print out list of cars" << endl;
	cout << "3. Estimate car rental cost" << endl;
	cout << "4. Find the most expensive car" << endl;
	cout << "5. Print out all available cars" << endl;
	cout << "6. Sort by Make" << endl;
	cout << "7. Sort by Price" << endl;
	cout << "8. Search by Make" << endl;
	cout << "9. Exit\n" << endl;
	cout << "> ";

	// Loops until case 6
	while(true) {
		cin >> menuChoice;
		cout << endl;

		switch(menuChoice) {
			case 1:
			{
				char fileName[50];
				cout << "Input file name" << endl;
				cin >> fileName;

				a1.readInData(fileName);

				cout << "Succesfully read data" << endl;
				cout << endl;
				cout << "> ";

				break;
			}
			case 2:
			{
				a1.print();

				cout << endl;
				cout << "> ";
				break;
			}
			case 3:
			{
				int carNum = 0;
				int days = 0;
				char agencyName[20];

				cout << "Enter car number" << endl;
				cin >> carNum;
				cout << endl;

				cout << "Enter number of days" << endl;
				cin >> days;
				cout << endl;

				carNum--;

				cout << "Cost of rental for " << days << " days is: " << a1.estimateCost(carNum, days) << endl;

				break;
			}
			case 4:
			{
				a1.findMostExpensive();

				cout << endl;
				cout << "> ";
				break;
			}
			case 5:
			{
				a1.printAvailableCars();

				cout << "> ";
				break;
			}
			case 6:
			{
				a1.sortByMake();

				cout << endl;
				cout << "> ";
				break;
			}
			case 7:
			{
				a1.sortByPrice();

				cout << endl;
				cout << "> ";
				break;
			}
			case 8:
			{
				char makeName[50];

				cout << "Enter Make name" << endl;
				cin >> makeName;

				a1.searchByMake(makeName);

				cout << endl;
				cout << "> ";
				break;
			}
			case 9:
			{
				return 0;
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