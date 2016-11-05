#include <iostream>
#include <fstream>

using namespace std;


// struct
struct RentalCar {
	char make[20] = "make";
	char model[20] = "model";

	int year = 0;
	float price = 0.0;
	bool available = false;
};

struct Agency {
	char name[20] = "name";
	int zipcode[5];
	RentalCar inventory[5];
};

// function prototypes
void readCar(RentalCar&, ifstream&);
void printCar(RentalCar&);
void estimateCost(RentalCar&, int);
void findExpCar(Agency*);
void availCars(Agency*);
int strCmp(char*, char*);

int main() {

	ifstream DataFile;

	int menuChoice = 0;

	Agency a1[3];

	// menu
	cout << "Car Rental Menu" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Read data from file" << endl;
	cout << "2. Print out list of cars" << endl;
	cout << "3. Estimate car rental cost" << endl;
	cout << "4. Find the most expensive car" << endl;
	cout << "5. Print out all available cars" << endl;
	cout << "6. Exit\n" << endl;
	cout << "> ";

	// Loops until case 6
	while(true) {
		cin >> menuChoice;
		cout << endl;

		switch(menuChoice) {
			case 1:
			{
				char temp[20];
				char* tempPtr;

				Agency* agencyPtr = a1;
				RentalCar* rentPtr = (*agencyPtr).inventory;
				int* zipPtr = (*agencyPtr).zipcode;

				char fileName[50];
				cout << "Input file name" << endl;
				cin >> fileName;

				DataFile.open(fileName);


				for(int i = 0; i < 3; i++) {
					DataFile >> (*agencyPtr++).name;
					DataFile >> temp;
					tempPtr = temp;

					// subtracting ascii values to get actual number from char
					for(int x = 0; x < 5; x++) {
						(*zipPtr++) = (*tempPtr++) - '0';
					}

					for(int x = 0; x < 5; x++) {
						readCar((*rentPtr++), DataFile);
					}
					zipPtr = (*agencyPtr).zipcode;
					rentPtr = (*agencyPtr).inventory;
				}

				DataFile.close();

				tempPtr = NULL;
				agencyPtr = NULL;
				zipPtr = NULL;
				rentPtr = NULL;

				cout << "Succesfully read data" << endl;
				cout << "> ";
				break;
			}
			case 2:
			{
				Agency* agencyPtr = a1;
				RentalCar* rentPtr = (*agencyPtr).inventory;
				int* zipPtr = (*agencyPtr).zipcode;

				for(int i = 0; i < 3; i++) {
					cout << (*agencyPtr++).name << " ";
					for(int x = 0; x < 5; x++) {
						cout << (*zipPtr++);
					}
					cout << endl;

					for(int x = 0; x < 5; x++) {
						printCar(*rentPtr++);
					}
					cout << endl;

					zipPtr = (*agencyPtr).zipcode;
					rentPtr = (*agencyPtr).inventory;
				}

				agencyPtr = NULL;
				zipPtr = NULL;
				rentPtr = NULL;

				cout << endl;
				cout << "> ";
				break;
			}
			case 3:
			{
				int carNum = 0;
				int days = 0;
				char agencyName[20];

				Agency* agencyPtr = a1;
				RentalCar* rentPtr = (*agencyPtr).inventory;

				cout << "Enter Agency Name" << endl;
				cin >> agencyName;
				cout << endl;

				cout << "Enter car number" << endl;
				cin >> carNum;
				cout << endl;

				cout << "Enter number of days" << endl;
				cin >> days;
				cout << endl;

				carNum--;

				for(int i = 0; i < 3; i++) {
					if(strCmp(agencyName, (*agencyPtr++).name) == 0) {
						estimateCost(*(rentPtr+carNum), days);

						cout << "> ";
						break;
					}
					rentPtr = (*agencyPtr).inventory;
				}

				rentPtr = NULL;
				agencyPtr = NULL;

				break;
			}
			case 4:
			{
				findExpCar(a1);

				cout << "> ";
				break;
			}
			case 5:
			{
				availCars(a1);

				cout << "> ";
				break;
			}
			case 6:
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

// Reads in a car object's values from the input file
void readCar(RentalCar &dest, ifstream &file) {

	int temp = 0;

	file >> dest.year;
	file >> dest.make;
	file >> dest.model;
	file >> dest.price;

	file >> temp;

	if(temp == 1) {
		dest.available = true;
	} else {
		dest.available = false;
	}

}

// Prints a car's attributes in a proper format
void printCar(RentalCar &car) {

	cout << car.year << " " 
		 << car.make << " " 
		 << car.model << " " 
		 << car.price << " " 
		 << "Available: ";

	if(car.available == true) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

// Estimates the cost to rent by multiplying the price and days to rent
void estimateCost(RentalCar &car, int days) {

	float tempCost = 0.0;

	tempCost = car.price * days;

	cout << "Estimated cost of renting is: " << tempCost << endl;
}

// Finds the most expensive car by finding the max value
// of price in each car object
void findExpCar(Agency *input) {

	float max = 0.0;
	RentalCar* maxCar;

	Agency* inpPtr = input;
	RentalCar* invPtr = (*inpPtr).inventory;

	for(int i = 0; i < 5; i++) {
		for(int x = 0; x < 5; x++) {
			if((*invPtr).price > max) {
				maxCar = invPtr;

				max = (*invPtr).price;
			}
			invPtr++;
		}
		inpPtr++;
		invPtr = (*inpPtr).inventory;
	}

	cout << "Most expensive car: " 
		 << (*maxCar).year <<  " " 
		 << (*maxCar).make << " " 
		 << (*maxCar).model << endl;

	inpPtr = NULL;
	invPtr = NULL;
	maxCar = NULL;
}

// Prints out list of available cars or cars that have bool available set to true
void availCars(Agency *input) {

	Agency* inpPtr = input;
	RentalCar* invPtr = (*inpPtr).inventory;

	for(int i = 0; i < 3; i++) {
		for(int x = 0; x < 5; x++) {
			if((*invPtr).available == true) {
				printCar(*invPtr);
			}
			invPtr++;
		}
		inpPtr++;
		invPtr = (*inpPtr).inventory;
	}

	inpPtr = NULL;
	invPtr = NULL;
}

int strCmp(char* inp1, char* inp2) {

	// compares the two c-strings and return either
	// a negative, positive, or 0 if the first input's
	// character is lesser, greater or equal to the
	// second input's character
	char* inp1Ptr = inp1;
	char* inp2Ptr = inp2;

	while(*inp1Ptr != '\0' || *inp2Ptr != '\0') {
		if(*inp1Ptr > *inp2Ptr) {
			return 1;
		}

		if(*inp1Ptr < *inp2Ptr) {
			return -1;
		}

		inp1Ptr++;
		inp2Ptr++;
	}

	inp1Ptr = NULL;
	inp2Ptr = NULL;

	return 0;
}
