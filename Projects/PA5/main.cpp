#include <iostream>
#include <cstdlib>
#include <fstream>

#include "String.h"

using namespace std;

void readString(String&, ifstream&);

int main() {
	
	ifstream DataFile;
	char* testFileName = new char[25];

	String inst1;
	String inst2;

	String* instArr = new String[10];
	String* instArrPtr = instArr;

	cout << "Enter the test file name" << endl;
	cin >> testFileName;
	cout << endl;

	// read in words from testFileName
	DataFile.open(testFileName);

	readString(inst1, DataFile);

	readString(inst2, DataFile);

	for(int i = 0; i < 10; i++) {
		readString(*instArrPtr++, DataFile);
	}
	instArrPtr = instArr;

	DataFile.close();

	inst1.print();
	inst2.print();

	// copying inst2 to inst1
	inst1.copy(inst2);

	inst1.print();

	cout << endl;

	// concat inst2 to inst1
	inst1.concat(inst2);
	inst1.print();

	cout << endl;

	// printing lengths of string array
	for(int i = 0; i < 10; i++) {
		cout << instArrPtr->length() << endl;
		instArrPtr++;
	}
	instArrPtr = instArr;
	cout << endl;

	// comparing inst1 to instArry and returning results
	for(int i = 0; i < 10; i++) {
		inst1.print();
		cout << "and ";
		instArrPtr->print();
		cout << inst1.compare(*instArrPtr++) << endl;
	}
	instArrPtr = instArr;

	// deallocation
	for(int i = 0; i < 10; i++) {
		instArrPtr->deallocate();
		instArrPtr++;
	}

	inst1.deallocate();
	inst2.deallocate();

	delete [] instArr;
	delete [] testFileName;

	instArr = NULL;
	instArrPtr = NULL;
	testFileName = NULL;

	return 0;
}

void readString(String &dest, ifstream &data) {

	char* tempStr = new char[25];
	data >> tempStr;

	dest.initialize(tempStr);

	delete [] tempStr;
	tempStr = NULL;
}