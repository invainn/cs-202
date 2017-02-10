#include <iostream>
#include "Stack.h"

Stack::Stack() {
	top = -1;
}

Stack::~Stack() {
	top = -1;
}

bool Stack::push(int added_integer) {
	if(this->top != 9) {
		top++;
		this->data[top] = added_integer;

		return true;
	} else {
		return false;
	}
}

bool Stack::pop(int &removed_integer) {
	if(this->top != -1) {
		removed_integer = this->data[top];
		top--;

		return true;
	} else {
		return false;
	}
	
}