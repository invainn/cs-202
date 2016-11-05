#include <iostream>
#include <fstream>

using namespace std;

void strCpy(char*, char*);
int strCmp(char*, char*);
void bubbleSort(char[][20], int);
void swap(char*, char*);

int main() {

	ifstream DataFile;
	ofstream outFile;

	int CharSize = 20;

	char inputName[20];
	char outputName[20];

	char nameList[10][20];

	//grabs the input and output file names for later use
	cout << "What is the name of the input file?" << endl;

	cin >> inputName;

	cout << "What is the name of the output file?" << endl;

	cin >> outputName;
	cout << endl;

	// opens the data file and reads it into the 2d array nameList
	DataFile.open(inputName);

	for(int i = 0; i < 10; i++) {
		DataFile >> nameList[i];
	}

	DataFile.close();

	// output unsorted list
	cout << "Unsorted List" << endl;
	cout << "-------------\n" << endl;

	for(int i = 0; i < 10; i++) {
		cout << nameList[i] << endl;
	}

	cout << endl;

	// sorts the list alphabetically using bubble sort
	bubbleSort(nameList, 10);

	// output sorted list
	cout << "Sorted List" << endl;
	cout << "-----------\n" << endl;

	for(int i = 0; i < 10; i++) {
		cout << nameList[i] << endl;
	}

	cout << endl;

	// writes nameList to the specified output file
	outFile.open(outputName);

	for(int i = 0; i < 10; i++) {
		outFile << nameList[i] << "\n";
	}

	outFile.close();

	return 0;
}

void strCpy(char* dest, char* input) {

	// strCpy inserts characters from the input
	// into the destination until the destination's
	// position in the array is on a null character
	int pos = 0;

	while(input[pos] != '\0') {
		dest[pos] = input[pos];
		pos++;
	}

	dest[pos] = input[pos];
}

int strCmp(char* inp1, char* inp2) {
	// compares the two c-strings and returns either
	// a negative, positive, or 0 if the first input's
	// character is lesser, greater or equal to the
	// second input's character
	int pos = 0;

	while(inp1[pos] != '\0' || inp2[pos] != '\0') {
		if(inp1[pos] > inp2[pos]) {
			return 1;
		}

		if(inp1[pos] < inp2[pos]) {
			return -1;
		}

		pos++;
	}

	return 0;
}

void bubbleSort(char input[][20], int arrSize) {

	// looks at first two elements, then compares them
	// if the first element is greater or higher
	// value letter (ex. Letter Z > Letter A)
	// then it is swapped and increments the pos
	// to look at the next two.
	// sort is completed after no swaps are done	
	// in a run
	bool hasSwapped = true;

	int pos = 0;
	int result = 0;

	while(hasSwapped) {
		hasSwapped = false;
		for(int i = 0; i < arrSize-1; i++) {
			result = strCmp(input[pos], input[pos+1]);
			if(result == 1) {
				swap(input[pos], input[pos+1]);
				hasSwapped = true;
			}
			pos++;
		}
		pos = 0;
	}
}

void swap(char* inp1, char* inp2) {
	char tempName[20];

	strCpy(tempName, inp1);
	strCpy(inp1, inp2);
	strCpy(inp2, tempName);
}