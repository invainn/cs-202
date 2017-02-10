#include <iostream>
#include "stackA.h"

stackA::stackA(int maxTemp) {
	this->max = maxTemp;
	this->top = -1;
	this->data = new int[this->max];
}

stackA::stackA(const stackA& src) {
	this->max = src.max;
	this->top = src.top;

	this->data = new int[src.max];

	for(int i = 0; i < this->top+1; i++) {
		this->data[i] = src.data[i];
	}
}

stackA::~stackA() {
	delete [] this->data;
	this->data = NULL;
}

stackA& stackA::operator=(const stackA& src) {
	this->max = src.max;
	this->top = src.top;

	delete [] this->data;
	this->data = NULL;

	this->data = new int[src.max];

	for(int i = 0; i < src.top+1; i++) {
		this->data[i] = src.data[i];
	}

	return *this;
}

bool stackA::push(int src) {
	if(!this->full()) {
		this->top++;

		this->data[top] = src;

		return true;
	} else {
		return false;
	}
}

bool stackA::pop() {
	if(!this->empty()) {
		this->top--;

		return true;
	} else {
		return false;
	}
}

int stackA::getTop() {
	return this->data[top];
}

bool stackA::empty() const {
	if(this->top == -1) {
		return true;
	} else {
		return false;
	}
}

bool stackA::full() const {
	if(this->top == this->max-1) {
		return true;
	} else {
		return false;
	}
}


bool stackA::clear() {
	if(!this->empty()) {
		this->top = -1;

		delete [] this->data;
		this->data = new int[this->max];

		return true;
	} else {
		return false;
	}
}

bool stackA::operator==(const stackA& src) const {
	if(this->top != src.top) {
		return false;
	}

	if(this->max != src.max) {
		return false;
	}

	for(int i = 0; i < src.top+1; i++) {
		if(this->data[i] != src.data[i]) {
			return false;
		}
	}

	return true;
}

ostream& operator<<(ostream& os, const stackA& inp) {
	for(int i = inp.top; i > -1; i--) {
		cout << inp.data[i] << " ";
	}

	cout << endl;
	return os;
}
