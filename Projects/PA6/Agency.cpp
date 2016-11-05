#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Agency.h"

using namespace std;

void strCpy(char*, const char*);

// Car object constructor
Car::Car() {
	this->make = "Make";
	this->model = "Model";
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
	cout << this->make << " " 
		 << this->model << " " 
		 << this->year << " $" 
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
	this->name = "Name";
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

	charPtr1 = tempString;
	intPtr1 = this->zipcode;

	for(int i = 0; i < 5; i++) {
		*intPtr1++ = *tempString++ - '0';
	}

	delete [] tempString;
	tempString = new char[100];

	delete [] this->inventory;
	this->inventory = new Car[100];
	carPtr1 = this->inventory;

	for(int i = 0; i < 15; i++) {
		DataFile >> tempString;
		carPtr1->setMake(tempString);

		DataFile >> tempString;
		carPtr1->setModel(tempString);

		DataFile >> tempString;
		carPtr1->setYear(atoi(tempString));

		DataFile >> tempString;
		carPtr1->setPrice(atof(tempString));

		DataFile >> tempString;
		if(tempString == "false") {
			tempBool = false;
			carPtr1->setAvailable(tempBool);
		} else {
			tempBool = true;
			carPtr1->setAvailable(tempBool);
		}

		carPtr1++;
	}
}

void Agency::print() const {

	Car* carPtr1 = this->inventory;

	cout << this->name << " "  << this-> zipcode << endl;
	for(int i = 0; i < 15; i++) {
		carPtr1->print();
		carPtr1++;
	}
}

void Agency::printAvailableCars() const {
	Car* carPtr1 = this->inventory;

	for(int i = 0; i < 15; i++) {
		if(carPtr1->getAvailable() == true) {
			carPtr1->print();
		}
		carPtr1++;
	}
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
}

float Agency::estimateCost(int carNumber, int numOfDays) const {
	float tempCost = 0.0;

	Car* carPtr1 = this->inventory;
	carPtr1 += carNumber;

	tempCost = carPtr1->getPrice();
	tempCost *= numOfDays;

	return tempCost;
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