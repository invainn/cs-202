#include <iostream>
#include <cstdlib>
#include "String.h"

using namespace std;

void String::initialize(char* src) {

	// counts the number of letters and sets them
	// to the buffer's wordLength
	int counter = 0;
	char* srcPos = src;
	char* destPos;

	while(*srcPos != '\0') {
		srcPos++;
		counter++;
	}

	this->wordLength = counter;

	// allocates memory in the size of src and copies 
	// src's characters into the object's buffer
	this->buffer = new char[counter+1];
	destPos = this->buffer;

	srcPos = src;

	while(*srcPos != '\0') {
		*destPos++ = *srcPos++;
	}

	*destPos = '\0';
	
	srcPos = NULL;
	destPos = NULL;
}

void String::deallocate() {

	// deallocates the buffer
	delete [] this->buffer;
	this->buffer = NULL;
}

void String::copy(const String& src) {
	
	// if the src's buffer is greater than the object's buffer
	// then resize the object's buffer to fit the src's buffer
	// exactly
	if(src.wordLength > this->wordLength) {
		delete [] this->buffer;
		this->buffer = new char[src.wordLength+1];
	}

	// copies the source's characters into the destination
	char* destPos = this->buffer;
	char* srcPos = src.buffer;

	while(*srcPos != '\0') {
		*destPos++ = *srcPos++;
	}

	*destPos = '\0';

	destPos = NULL;
	srcPos = NULL;

}

int String::length() const {
	return this->wordLength;
}

void String::concat(const String& source) {

	//get word length of both(already have 1)
	int l = source.length();

	//allocate memory for new word
	char* temp = new char[l + this->wordLength + 1];
	char* temp_home = temp;

	// copy word one into new memory
	char* home_ptr_one = this->buffer;
	for(int i = 0; i < this->wordLength; i++) {
		*temp = *buffer;
		temp++;
		this->buffer++;
	}
	buffer = home_ptr_one;

	// copy word two into new memory
	char* home_ptr_two = source.buffer;
	for(int i = 0; i < l + 1; i++) {
		*temp = *home_ptr_two;
		temp++;
		home_ptr_two++;
	}
	temp = temp_home;

	// deallocate old memory
	delete [] this->buffer;

	// set buffer poitner equal to new memory
	this->wordLength = l + wordLength;
	this->buffer = temp;

	temp = NULL;
	temp_home = NULL;

	home_ptr_one = NULL;
	home_ptr_two = NULL;
}

int String::compare(const String& src) {
	// compares the two c-strings and return either
	// a negative, positive, or 0 if the first input's
	// character is lesser, greater or equal to the
	// second input's character
	char* inp1Ptr = this->buffer;
	char* inp2Ptr = src.buffer;

	while(*inp1Ptr != '\0' || *inp2Ptr != '\0') {
		if(*inp1Ptr > *inp2Ptr) {
			inp1Ptr = NULL;
			inp2Ptr = NULL;

			return 1;
		}

		if(*inp1Ptr < *inp2Ptr) {
			inp1Ptr = NULL;
			inp2Ptr = NULL;
			
			return -1;
		}

		inp1Ptr++;
		inp2Ptr++;
	}

	inp1Ptr = NULL;
	inp2Ptr = NULL;

	return 0;
}

void String::print() {

	// prints the buffer
	cout << this->buffer << endl;
}