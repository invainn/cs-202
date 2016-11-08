#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Agency.h"

using namespace std;

void strCpy(char*, const char*);
int strCmp(char*, char*);

// Car object constructor
Car::Car() {
	this->make = new char[100];
	this->model = new char[100];
	this->year = -1;
	this->price = -1.0;
	this->available = false;
}

// takes the parameters and sets them into a new car's values
Car::Car(char* make, char* model, int year, float price, bool available) {
	this->make = new char[100];
	strCpy(this->make, make);

	this->model = new char[100];
	strCpy(this->model, model);

	this->year = year;
	this->price = price;
	this->available = available;
}

// copies another car's values into a new car object
Car::Car(const Car &inp) {
	this->make = new char[100];
	strCpy(this->make, inp.make);

	this->model = new char[100];
	strCpy(this->model, inp.model);

	this->year = inp.year;
	this->price = inp.price;
	this->available = inp.available;
}

// deallocates and sets the car's values to intial values
Car::~Car() {
	delete [] this->make;
	delete [] this->model;

	this->make = NULL;
	this->model = NULL;
	this->year = -1;
	this->price = -1.0;
	this->available = false;
}

// copies another car's values into a car object
void Car::copy(Car inp) {
	delete [] this->make;
	this->make = new char[100];
	strCpy(this->make, inp.make);

	delete [] this->model;
	this->model = new char[100];
	strCpy(this->model, inp.model);

	this->year = inp.year;
	this->price = inp.price;
	this->available = inp.available;
}

// prints the car's values
void Car::print() const {
	cout << this->year << " " 
		 << this->make << " " 
		 << this->model << " $" 
		 << this->price << " Per Day Available:" 
		 << this->available
		 << endl;
}

// getters
char* Car::getMake() const {
	return this->make;
}

char* Car::getModel() const {
	return this->model;
}

int Car::getYear() const {
	return this->year;
}

float Car::getPrice() const {
	return this->price;
}

bool Car::getAvailable() const {
	return this->available;
}

// setters
void Car::setMake(char* inp) {
	delete [] this->make;
	this->make = new char[100];
	strCpy(this->make, inp);
}

void Car::setModel(char* inp) {
	delete [] this->model;
	this->model = new char[100];
	strCpy(this->model, inp);
}

void Car::setYear(int inp) {
	this->year = inp;
}

void Car::setPrice(float inp) {
	this->price = inp;
}

void Car::setAvailable(bool inp) {
	this->available = inp;
}

// Agency class
// Agency constructor
Agency::Agency() {
	this->name = new char[100];
	this->zipcode = new int[100];
	this->inventory = new Car[100];
}

Agency::Agency(const Agency &inp) {
	int* tempPtr1 = inp.zipcode;
	int* tempPtr2;

	Car* carPtr1 = inp.inventory;
	Car* carPtr2;

	this->name = new char[100];
	strCpy(this->name, inp.name);

	this->zipcode = new int[100];
	tempPtr2 = this->zipcode;
	for(int i = 0; i < 5; i++) {
		*tempPtr2++ = *tempPtr1++;
	}

	this->inventory = new Car[100];
	carPtr2 = this->inventory;
	for(int i = 0; i < 15; i++) {
		*carPtr2++ = *carPtr1++;
	}

	tempPtr1 = NULL;
	tempPtr2 = NULL;

	carPtr1 = NULL;
	carPtr2 = NULL;
}

Agency::~Agency() {
	delete [] this->name;
	delete [] this->zipcode;
	delete [] this->inventory;

	this->name = NULL;
	this->zipcode = NULL;
	this->inventory = NULL;
}

void Agency::readInData(char* fileName) {
	char* tempString = new char[100];

	int* intPtr1;
	char* charPtr1;
	Car* carPtr1;
	bool tempBool;

	ifstream DataFile;
	DataFile.open(fileName);

	delete [] this->name;
	this->name = new char[100];
	DataFile >> this->name;

	delete [] this->zipcode;
	this->zipcode = new int[100];
	DataFile >> tempString;

	cout << tempString << endl;

	charPtr1 = tempString;
	intPtr1 = this->zipcode;

	for(int i = 0; i < 5; i++) {
		*intPtr1++ = *charPtr1++ - '0';
	}

	delete [] tempString;
	tempString = new char[100];

	delete [] this->inventory;
	this->inventory = new Car[100];
	carPtr1 = this->inventory;

	for(int i = 0; i < 15; i++) {
		DataFile >> tempString;
		carPtr1->setYear(atoi(tempString));

		DataFile >> tempString;
		carPtr1->setMake(tempString);

		DataFile >> tempString;
		carPtr1->setModel(tempString);

		DataFile >> tempString;
		carPtr1->setPrice(atof(tempString));

		DataFile >> tempString;

		cout << boolalpha;

		if(*tempString == '0') {
			tempBool = false;
			carPtr1->setAvailable(tempBool);
		} else {
			tempBool = true;
			carPtr1->setAvailable(tempBool);
		}

		carPtr1++;
	}

	delete [] tempString;

	intPtr1 = NULL;
	charPtr1 = NULL;
	carPtr1 = NULL;
}

void Agency::print() const {

	Car* carPtr1 = this->inventory;
	int* intPtr1 = this->zipcode;

	cout << this->name << " ";
	for(int i = 0; i < 5; i++) {
		cout << *intPtr1++;
	}
	cout << endl;
	for(int i = 0; i < 15; i++) {
		carPtr1->print();
		carPtr1++;
	}

	carPtr1 = NULL;
	intPtr1 = NULL;
}

void Agency::printAvailableCars() const {
	Car* carPtr1 = this->inventory;

	for(int i = 0; i < 15; i++) {
		if(carPtr1->getAvailable() == true) {
			carPtr1->print();
		}
		carPtr1++;
	}

	carPtr1 = NULL;
}

void Agency::findMostExpensive() const {
	Car* carPtr1 = this->inventory;

	float max = 0.0;
	int maxCar = 0;

	for(int i = 0; i < 15; i++) {
		if(carPtr1->getPrice() > max) {
			max = carPtr1->getPrice();
			maxCar = i;
		}
		carPtr1++;
	}

	carPtr1 = this->inventory;
	carPtr1 += maxCar;

	carPtr1->print();

	carPtr1 = NULL;
}

float Agency::estimateCost(int carNumber, int numOfDays) const {
	float tempCost = 0.0;

	Car* carPtr1 = this->inventory;
	carPtr1 += carNumber;

	tempCost = carPtr1->getPrice();
	tempCost *= numOfDays;

	carPtr1 = NULL;

	return tempCost;
}

void Agency::sortByMake() {
	bool swapped = true;
	Car temp;

	Car* carPtr1 = this->inventory;
	Car* carPtr2 = this->inventory+1;


	while(swapped) {
		swapped = false;
		for(int i = 0; i < 14; i++) {
			int result = strCmp(carPtr1->getMake(), carPtr2->getMake());
			if(result == 1) {
				swapped = true;
				
				//could be shortened to 3 lines by overloading assignment operator
				temp.setMake(carPtr1->getMake());
				temp.setModel(carPtr1->getModel());
				temp.setYear(carPtr1->getYear());
				temp.setPrice(carPtr1->getPrice());
				temp.setAvailable(carPtr1->getAvailable());

				carPtr1->setMake(carPtr2->getMake());
				carPtr1->setModel(carPtr2->getModel());
				carPtr1->setYear(carPtr2->getYear());
				carPtr1->setPrice(carPtr2->getPrice());
				carPtr1->setAvailable(carPtr2->getAvailable());

				carPtr2->setMake(temp.getMake());
				carPtr2->setModel(temp.getModel());
				carPtr2->setYear(temp.getYear());
				carPtr2->setPrice(temp.getPrice());
				carPtr2->setAvailable(temp.getAvailable());
			}
			carPtr1++;
			carPtr2++;
		}
		carPtr1 = this->inventory;
		carPtr2 = this->inventory+1;
	}

	carPtr1 = NULL;
	carPtr2 = NULL;
}

void Agency::sortByPrice() {
	Car* carPtr1 = this->inventory;
	Car temp;

	for(int i = 1; i < 15; i++) {
		Car* curCar = carPtr1+i;

		temp.setMake(curCar->getMake());
		temp.setModel(curCar->getModel());
		temp.setYear(curCar->getYear());
		temp.setPrice(curCar->getPrice());
		temp.setAvailable(curCar->getAvailable());

		int pos = i;

		Car* carPos = carPtr1+pos;
		Car* carPosNeg = carPtr1+pos-1;

		while((pos > 0) && (carPosNeg->getPrice() < temp.getPrice())) {
			carPos->setMake(carPosNeg->getMake());
			carPos->setModel(carPosNeg->getModel());
			carPos->setYear(carPosNeg->getYear());
			carPos->setPrice(carPosNeg->getPrice());
			carPos->setAvailable(carPosNeg->getAvailable());

			pos--;

			carPos = carPtr1+pos;
			carPosNeg = carPtr1+pos-1;
		}


		carPos->setMake(temp.getMake());
		carPos->setModel(temp.getModel());
		carPos->setYear(temp.getYear());
		carPos->setPrice(temp.getPrice());
		carPos->setAvailable(temp.getAvailable());

		curCar = NULL;
		carPos = NULL;
		carPosNeg = NULL;
	}

	carPtr1 = NULL;
}

void Agency::searchByMake(char* inp) const {

	Car* carPtr1 = this->inventory;

	for(int i = 0; i < 15; i++) {
		if(strCmp(carPtr1->getMake(), inp) == 0) {
			carPtr1->print();
		}
		carPtr1++;
	}

	carPtr1 = NULL;
}

void strCpy(char* dest, const char* source) {

	// copies the source's characters into the destination
	char* destPos = dest;

	while(*source != '\0') {
		*destPos++ = *source++;
	}

	*destPos = '\0';

	destPos = NULL;
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