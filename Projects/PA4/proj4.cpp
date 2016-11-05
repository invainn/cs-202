#include <iostream>
#include <fstream>

using namespace std;

struct Pieces {
	char* word;
	int jump;
};

void readPieces(Pieces&, ifstream&);
void readKeys(int&, ifstream&);
void initPieces(Pieces&);
void strCpy(char*, const char*);
void strCat(char*, char*);
int strLen(char*);
void decode(Pieces*, int*, char*, int, int);

int main() {

	int numOfWords = 0;
	int numOfKeys = 0;

	char* tempArr = new char[20];

	int* keyArr;
	Pieces* pieceArr;
	char* decodedMess = new char[250];

	int* keyArrPtr;
	Pieces* pieceArrPtr;

	ifstream DataFile;

	cout << "Enter file name: " << endl;
	cin >> tempArr;
	cout << endl;
	cout << "\nDecoded Message: " << endl;

	// opens the file, initializes the arrays,
	// then reads the data into the arrays
	DataFile.open(tempArr);

	DataFile >> numOfWords;
	DataFile >> numOfKeys;

	pieceArr = new Pieces[numOfWords];
	keyArr = new int[numOfKeys];

	keyArrPtr = keyArr;
	pieceArrPtr = pieceArr;

	for(int i = 0; i < numOfWords; i++) {
		initPieces(*pieceArrPtr++);
	}

	pieceArrPtr = pieceArr;

	for(int i = 0; i < numOfWords; i++) {
		readPieces(*pieceArrPtr++, DataFile);
	}

	for(int i = 0; i < numOfKeys; i++) {
		readKeys(*keyArrPtr++, DataFile);
	}

	pieceArrPtr = pieceArr;
	keyArrPtr = keyArr;

	DataFile.close();

	decode(pieceArr, keyArr, decodedMess, numOfWords, numOfKeys);

	// deallocates the memory within the arrays,
	// then deallocates itself and sets all pointers
	// to NULL
	for(int i = 0; i < numOfWords; i++) {
		delete [] pieceArrPtr->word;

		pieceArrPtr++;
	}

	delete [] tempArr;
	delete [] keyArr;
	delete [] pieceArr;
	delete [] decodedMess;

	tempArr = NULL;
	keyArr = NULL;
	pieceArr = NULL;
	decodedMess = NULL;
	keyArrPtr = NULL;
	pieceArrPtr = NULL;

	return 0;
}

void readPieces(Pieces &piece, ifstream& data) {

	// reads in the file in the order of 
	// word then jump
	delete [] piece.word;

	char* tempStr = new char[25];

	data >> tempStr;
	piece.word = new char[strLen(tempStr)];
	strCpy(piece.word, tempStr);

	data >> piece.jump;

	delete [] tempStr;
	tempStr = NULL;

}

void readKeys(int &dest, ifstream& data) {

	// reads in the keys
	data >> dest;

}

void initPieces(Pieces &piece) {

	// initializes the struct's data members

	piece.word = new char[5];
	strCpy(piece.word, "word");

	piece.jump = 0;
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

void strCat(char* dest, char* source) {

	// appends the source's characters at
	// the destination's null character position
	char* destPos = dest;
	char* sourcePos = source;

	while(*destPos != '\0') {
		destPos++;
	}

	while(*sourcePos != '\0') {
		*destPos++ = *sourcePos++;
	}

	*destPos++ = ' ';
	*destPos = '\0';

	destPos = NULL;
	sourcePos = NULL;
}

int strLen(char* inp) {

	// loops through the c-string and counts
	// the characters, including the null
	// character
	int counter = 0;
	char* inpPtr = inp;

	while(*inpPtr != '\0') {
		counter++;
		inpPtr++;
	}

	counter++;
	inpPtr = NULL;

	return counter;
}

void decode(Pieces* pieceArr, int* keyArr, char* decodedMess, int wordNum, int keyNum) {

	// decodes the message by incrementing the piece ptr, reads the jump value
	// that it's on, if it is not 0, then increment by the jump value
	// and repeat until it has a jump value 0, then concats to the decodedMess
	// Exits and prints the decoded message when it has added the number of key
	// value words.
	int counter = 0;
	int tempJump = 0;

	Pieces* piecePtr = pieceArr;
	int* keyPtr = keyArr;

	while(true) {

		for(int i = 0; i < *keyPtr; i++) {
			piecePtr++;
		}

		while(counter != keyNum) {
			if(piecePtr->jump == 0) {
				strCat(decodedMess, piecePtr->word);
				piecePtr = pieceArr;
				counter++;
				break;
			} else {
				if((piecePtr->jump+*keyPtr) > wordNum){
					piecePtr = pieceArr;
				}
				tempJump = piecePtr->jump;
				for(int i = 0; i < tempJump; i++) {
					piecePtr++;
				}
			}
		}
		if(counter == keyNum) {
			break;
		}
		keyPtr++;
	}

	cout << decodedMess << endl;
	cout << endl;

	piecePtr = NULL;
	keyPtr = NULL;
}