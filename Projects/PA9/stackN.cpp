#include <iostream>
#include "stackN.h"

using namespace std;

NodeS::NodeS(int na, NodeS* nxt) {
	this->data = na;
	this->next = nxt;
}

stackN::stackN() {
	this->top = NULL;
}

stackN::stackN(const stackN& src) {
	// check if other stack is empty
	if(src.top == NULL) {
		this->top = NULL;
	} else {
		// if not, make these nodes
		NodeS* newNode;
		NodeS* current;
		NodeS* last;

		//set current to point to the stack to be copied
		current = src.top;

		// create a new top and copy the info from src top
		this->top = new NodeS(current->data, NULL);

		// set last to point to the node
		last = this->top;

		// set current to point to the next node
		current = current->next;

		// now that the loop is prepped for top, copy remaining stack
		while(current != NULL) {
			newNode = new NodeS(current->data, NULL);
			last->next = newNode;
			last = newNode;
			current = current->next;
		}
	}
}

stackN::~stackN() {
	this->clear();
}

stackN& stackN::operator=(const stackN& src) {
	if(this != &src) {
		if(!this->empty()) {
			this->clear();
		}

		if(src.top == NULL) {
			this->top = NULL;
		} else {
			// if not, make these nodes
			NodeS* newNode;
			NodeS* current;
			NodeS* last;

			//set current to point to the stack to be copied
			current = src.top;

			// create a new top and copy the info from src top
			this->top = new NodeS(current->data, NULL);

			// set last to point to the node
			last = this->top;

			// set current to point to the next node
			current = current->next;

			// now that the loop is prepped for top, copy remaining stack
			while(current != NULL) {
				newNode = new NodeS(current->data, NULL);
				last->next = newNode;
				last = newNode;
				current = current->next;
			}
		}
	}

	return *this;
}

bool stackN::push(int src) {

	// if it's not full, make a new node that has the src data and points to top
	// then set this->top to the new node and return true
	if(!this->full()) {
		NodeS* newNode = new NodeS(src, this->top);
		this->top = newNode;

		return true;
	} else {
		return false;
	}
}

bool stackN::pop() {
	if(!this->empty()) {
		NodeS* temp = this->top;
		this->top = temp->next;
		delete temp;

		return true;
	} else {
		return false;
	}
}

int stackN::getTop() {
	NodeS* rtn = this->top;
	return rtn->data;
}

bool stackN::empty() const {
	if(this->top == NULL) {
		return true;
	} else {
		return false;
	}
}

bool stackN::full() const {
	return false;
}

bool stackN::clear() {
	if(!this->empty()) {
		NodeS* temp = this->top;
		NodeS* current = this->top;
		this->top = NULL;

		while(temp != NULL) {
			temp = temp->next;
			delete current;
			current = temp;
		}

		return true;
	} else {
		return false;
	}
}

bool stackN::operator==(const stackN& src) const {
	NodeS* temp = this->top;
	NodeS* temp2 = src.top;

	while(temp != NULL || temp2 != NULL) {
		cout << "run successful" << endl;
		if(temp->data != temp2->data) {
			return false;
		}

		temp = temp->next;
		temp2 = temp2->next;

	}

	return true;
}

ostream& operator<<(ostream& os, const stackN& src) {
	NodeS* current = src.top;

	while(current != NULL) {
		cout << current->data << " ";
		current = current->next;
	} 

	cout << endl;
	return os;
}