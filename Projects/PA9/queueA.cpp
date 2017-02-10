#include <iostream>
#include "queueA.h"

using namespace std;

queueA::queueA(int maxTemp) {
	this->max = maxTemp;
	this->front = 0;
	this->rear = 0;
	this->data = new int[maxTemp];
}

queueA::queueA(const queueA& src) {
	this->max = src.max;
	this->front = src.front;
	this->rear = src.rear;
	this->data = new int[src.max];

	for(int i = 0; i < this->rear; i++) {
		this->data[i] = src.data[i];
	}
}

queueA::~queueA() {
	delete [] this->data;
	this->data = NULL;
}

queueA& queueA::operator=(const queueA& src) {
	this->max = src.max;
	this->front = src.front;
	this->rear = src.rear;
	if(!this->empty()) {
		delete [] this->data;
	}
	this->data = new int[src.max];

	for(int i = 0; i < this->rear; i++) {
		this->data[i] = src.data[i];
	}

	return *this;
}

bool queueA::enqueue(int src) {
	if(!this->full()) {
		this->data[this->rear] = src;
		this->rear++;

		return true;
	} else {
		return false;
	}
}

bool queueA::dequeue() {
	if(!this->empty()) {
		int temp = 0;

		for(int i = 0; i < this->rear; i++) {
			temp = this->data[i];
			this->data[i] = this->data[i+1];
			this->data[i+1] = temp;
		}

		this->rear--;

		return true;
	} else {
		return false;
	}
}

int queueA::getFront() {
	return this->data[this->front];
}

bool queueA::empty() const {
	if(this->rear == this->front) {
		return true;
	} else {
		return false;
	}
}

bool queueA::full() const {
	if(this->rear == this->max) {
		return true;
	} else {
		return false;
	}
}

bool queueA::clear() {
	delete [] this->data;
	this->front = 0;
	this->rear = 0;

	this->data = new int[this->max];

	return true;
}

bool queueA::operator==(const queueA& src) const {
	if(this->front != src.front) {
		return false;
	}

	if(this->rear != src.rear) {
		return false;
	}

	if(this->max !=src.max) {
		return false;
	}

	for(int i = 0; i < this->rear; i++) {
		if(this->data[i] != src.data[i]) {
			return false;
		}
	}

	return true;
}

ostream& operator<<(ostream& os, const queueA& src) {
	for(int i = 0; i < src.rear; i++) {
		cout << src.data[i] << " ";
	}

	cout << endl;

	return os;
}