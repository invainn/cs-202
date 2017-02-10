#include <iostream>

#include "listA.h"

using namespace std;

List::List(int sizeArr) {
	this->data = new int[sizeArr];
	this->actual = 0;
	this->cursor = -1;
	this->size = sizeArr;
}

List::List(const List& src) {
	this->data = new int[src.size];

	for(int i = 0; i < src.actual; i++) {
		this->data[i] = src.data[i];
	}
	this->actual = src.actual;
	this->cursor = src.cursor;
	this->size = src.size;
}

List::~List() {
	delete [] this->data;
	this->data = NULL;
}

bool List::goToBeginning() {
	if(!this->isEmpty() && this->cursor != 0) {
		this->cursor = 0;
		return true;
	} else {
		return false;
	}
}

bool List::goToEnd() {
	if(!this->isEmpty() && this->cursor != this->actual-1) {
		this->cursor = this->actual-1;
		return true;
	} else {
		return false;
	}
}

bool List::goToNext() {
	if(!this->isEmpty() && this->cursor != this->actual-1) {
		this->cursor++;
		return true;
	} else {
		return false;
	}
}

bool List::goToPrior() {
	if(!this->isEmpty() && this->cursor != 0) {
		this->cursor--;
		return true;
	} else {
		return false;
	}
}

bool List::insertBefore(int src) {
	if(!this->isFull()) {
		if(this->isEmpty()) {
			this->actual++;
			this->cursor++;
			this->data[cursor] = src;

			return true;
		} else {
			int temp = 0;

			// prep loop
			this->data[this->actual] = temp;
			for(int i = this->actual; i > this->cursor; i--) {
				temp = this->data[i];
				this->data[i] = this->data[i-1];
				this->data[i-1] = temp;
			}
			this->actual++;
			this->data[cursor] = src;

			return true;
		}
	} else {
		return false;
	}
}

bool List::insertAfter(int src) {
	if(!this->isFull()) {
		if(this->isEmpty()) {
			this->actual++;
			this->cursor++;
			this->data[cursor] = src;

			return true;
		} else {
			int temp = 0;

			//prep loop
			this->data[this->actual] = temp;
			for(int i = this->actual; i > (this->cursor+1); i--) {
				temp = this->data[i];
				this->data[i] = this->data[i-1];
				this->data[i-1] = temp;
			}
			this->actual++;
			this->cursor++;

			this->data[this->cursor] = src;

			return true;
		}
	} else {
		return false;
	}
}

bool List::remove() {
	if(!this->isEmpty()) {
		if(this->cursor == this->size-1) {
			this->cursor = 0;
			this->actual--;
			return true;
		} else {
			for(int i = this->cursor; i < this->size-1; i++) {
				this->data[i] = this->data[i+1];
			}
			this->actual--;
			return true;
		}
	} else {
		return false;
	}
}

bool List::isEmpty() const {
	if(this->cursor == -1) {
		return true;
	} else {
		return false;
	}
}

bool List::isFull() const {
	if(this->actual == this->size) {
		return true;
	} else {
		return false;
	}
}

void List::clear() {
	if(!this->isEmpty()) {
		delete [] this->data;
		this->data = new int[this->size];
		this->actual = 0;
		this->cursor = -1;
	} 
}

List& List::operator=(const List& src) {
	if(this != &src) {
		if(this->isEmpty()) {
			this->cursor = src.cursor;
			this->actual = src.actual;
			this->size = src.size;

			this->data = new int[src.size];

			for(int i = 0; i < src.actual; i++) {
				this->data[i] = src.data[i];
			}

			return *this;
		} else {
			this->cursor = src.cursor;
			this->actual = src.actual;
			this->size = src.size;

			delete [] this->data;
			this->data = new int[src.size];

			for(int i = 0; i < src.actual; i++) {
				this->data[i] = src.data[i];
			}

			return *this;
		}
	} else {
		return *this;
	}
}

ostream& operator<<(ostream& os, const List& src) {
	for(int i = 0; i < src.actual; i++) {
		if(src.cursor == i) {
			cout << "[" << src.data[i] << "] ";
		} else {
			cout << src.data[i] << " ";
		}
	}

	cout << endl;
	return os;
}