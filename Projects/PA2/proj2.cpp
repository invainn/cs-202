#include <iostream>
#include <fstream>

using namespace std;


// struct
struct RentalCar {
	char make[20] = "make";
	char model[20] = "model";

	int year = 0;
	float price = 0;
	bool available = false;
};

// function prototypes
void readCar(RentalCar&, ifstream&);
void printCar(RentalCar&);
void estimateCost(RentalCar&, int);
void findExpCar(RentalCar[]);
void availCars(RentalCar[]);

int main() {

	ifstream DataFile;

	int menuChoice = 0;

	RentalCar cars[10];

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
				DataFile.open("carData");

				for(int i = 0; i < 10; i++) {
					readCar(cars[i], DataFile);
				}

				DataFile.close();

				cout << "Succesfully read data" << endl;
				cout << "> ";
				break;
			}
			case 2:
			{
				for(int i = 0; i < 10; i++) {
					printCar(cars[i]);
				}

				cout << endl;
				cout << "> ";
				break;
			}
			case 3:
			{
				int carNum = 0;
				int days = 0;

				cout << "Enter car number" << endl;
				cin >> carNum;
				cout << endl;

				cout << "Enter number of days" << endl;
				cin >> days;
				cout << endl;

				carNum--;

				estimateCost(cars[carNum], days);

				cout << "> ";
				break;
			}
			case 4:
			{
				findExpCar(cars);

				cout << "> ";
				break;
			}
			case 5:
			{
				availCars(cars);

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
void findExpCar(RentalCar cars[]) {

	float max = 0.0;
	int maxCar = 0;

	for(int i = 0; i < 10; i++) {
		if(cars[i].price > max) {
			max = cars[i].price;
			maxCar = i;
		}
	}

	cout << "Most expensive car: " 
		 << cars[maxCar].year <<  " " 
		 << cars[maxCar].make << " " 
		 << cars[maxCar].model << endl;
}

// Prints out list of available cars or cars that have bool available set to true
void availCars(RentalCar cars[]) {

	for(int i = 0; i < 10; i++) {
		if(cars[i].available == true) {
			printCar(cars[i]);
		}
	}
}