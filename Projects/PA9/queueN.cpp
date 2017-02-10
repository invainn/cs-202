#include <iostream>
#include "queueN.h"

using namespace std;

NodeQ::NodeQ(int na, NodeQ* nxt) {
	this->data = na;
	this->next = nxt;
}

queueN::queueN() {
	this->front = NULL;
	this->rear = NULL;
}

queueN::queueN(const queueN& src) {
	if(src.front == NULL) {
		this->front = NULL;
		this->rear = NULL;
	} else {
		NodeQ* newNode;
		NodeQ* current;
		NodeQ* last;

		current = src.front;

		this->front = new NodeQ(current->data, NULL);

		last = this->front;

		current = current->next;

		while(current != NULL) {
			newNode = new NodeQ(current->data, NULL);
			last->next = newNode;
			last = newNode;
			current = current->next;
		}
	}
}

queueN::~queueN() {
	while(!this->empty()) {
		this->dequeue();
	}
}

queueN& queueN::operator=(const queueN& src) {
	if(this != &src) {
		if(!this->empty()) {
			this->clear();
		}

		if(src.front == NULL) {
			this->front = NULL;
			this->rear = NULL;
		} else {
			NodeQ* newNode;
			NodeQ* current;
			NodeQ* last;

			current = src.front;

			this->front = new NodeQ(current->data, NULL);

			last = this->front;

			current = current->next;

			while(current != NULL) {
				newNode = new NodeQ(current->data, NULL);
				last->next = newNode;
				last = newNode;
				current = current->next;
			}
		}
	}

	return *this;
}

bool queueN::enqueue(int src) {
	NodeQ* newPtr = new NodeQ(src, NULL);

	if(this->empty()) {
		this->front = newPtr;
	} else {
		NodeQ* tempPtr = this->rear;
		tempPtr->next = newPtr;
	}

	this->rear = newPtr;

	return true;
}

bool queueN::dequeue() {
	if(this->empty()) {
		return false;
	} else {
		NodeQ* tempPtr = this->front;

		if(this->front == this->rear) {
			this->front = NULL;
			this->rear = NULL;
		} else {
			NodeQ* tempPtr2 = this->front;
			this->front = tempPtr2->next;
		}

		tempPtr->next = NULL;
		delete tempPtr;

		return true;
	}
}

int queueN::getFront() {
	int temp = 0; 
	NodeQ* tempPtr = this->front;

	temp = tempPtr->data;

	tempPtr = NULL;
	return temp;
}

bool queueN::empty() const {
	return this->rear == NULL;
}

bool queueN::full() const {
	return false;
}

bool queueN::clear() {
	while(!this->empty()) {
		this->dequeue();
	}

	return true;
}

bool queueN::operator==(const queueN& src) const {
	NodeQ* temp = this->front;
	NodeQ* temp2 = src.front;

	if(temp->data != temp2->data) {
		return false;
	}

	while(temp != NULL) {
		if(temp->data != temp2->data) {
			return false;
		}

		temp = temp->next;
		temp2 = temp2->next;
	}

	return true;
}

ostream& operator<<(ostream& os, const queueN& src) {
	NodeQ* current = src.front;

	while(current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
	return os;
}