#include <iostream>
#include <cstring>

#include "stack.h"

using namespace std;

template<typename T>
Stack<T>::Stack(int maxTemp) {
	this->max = maxTemp;
	this->top = -1;
	this->data = new T[max];
}

template<typename T>
Stack<T>::Stack(const Stack& src) {
	this->max = src.max;
	this->top = src.top;

	this->data = new T[src.max];

	for(int i = 0; i < src.top+1; i++) {
		this->data[i] = src.data[i];
	}
}

template<typename T>
Stack<T>::~Stack() {
	delete [] this->data;
	this->data = NULL;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& src) {
	this->max = src.max;
	this->top = src.top;

	delete [] this->data;
	this->data = NULL;

	this->data = new T[src.max];

	for(int i = 0; i < src.top+1; i++) {
		this->data[i] = src.data[i];
	}
}

template<typename T>
bool Stack<T>::push(T src) {
	if(!this->full()) {
		this->top++;

		this->data[top] = src;

		return true;
	} else {
		return false;
	}
}

template<typename T>
bool Stack<T>::pop(T& src) {
	if(!this->empty()) {
		src = this->data[top];
		this->data[top] = 0;

		this->top--;

		return true;
	} else {
		return false;
	}
}

template<typename T>
bool Stack<T>::empty() const {
	if(this->top == -1) {
		return true;
	} else {
		return false;
	}
}

template<typename T>
bool Stack<T>::full() const {
	if(this->top == this->max) {
		return true;
	} else {
		return false;
	}
}

template<typename T>
bool Stack<T>::clear() {
	if(!this->empty()) {
		while(this->top != -1) {
			this->data[top] = 0;
			this->top--;
		}

		return true;
	} else {
		return false;
	}
}