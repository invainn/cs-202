#include <iostream>

#include "listN.h"

using namespace std;

Node::Node(int na, Node* nxt) {
	this->data = na;
	this->next = nxt;
}

ListN::ListN() {
	this->head = NULL;
	this->cursor = NULL;
}

ListN::ListN(const ListN& src) {
	Node* hTemp = src.head;
	Node* temp = new Node(hTemp->data, NULL);
	Node* thsTemp = temp;

	if(src.cursor == hTemp) {
		this->cursor = hTemp;
	}

	this->head = temp;
	hTemp = hTemp->next;

	while(hTemp->next != NULL) {
		temp = new Node(hTemp->data, NULL);
		thsTemp->next = temp;


		if(src.cursor == hTemp) {
			this->cursor = temp;
		}

		hTemp = hTemp->next;
		thsTemp = thsTemp->next;
	}

	temp = new Node(hTemp->data, NULL);
	thsTemp->next = temp;

	if(src.cursor == hTemp) {
		this->cursor = temp;
	}

	temp = NULL;
	hTemp = NULL;
	thsTemp = NULL;
}

ListN::~ListN() {
	this->clear();
}

bool ListN::goToBeginning() {
	if(!this->isEmpty() && this->cursor != this->head) {
		this->cursor = this->head;

		return true;
	} else {
		return false;
	}
}

bool ListN::goToEnd() {
	if(!this->isEmpty() && this->cursor->next != NULL) {
		while(this->cursor->next != NULL) {
			this->cursor = this->cursor->next;
		}

		return true;
	} else {
		return false;
	}
}

bool ListN::goToNext() {
	if(!this->isEmpty() && this->cursor->next != NULL) {
		this->cursor = this->cursor->next;

		return true;
	} else {
		return false;
	}
}

bool ListN::goToPrior() {
	if(!this->isEmpty() && this->cursor != this->head) {
		Node* cTemp = this->head;

		while(cTemp->next != this->cursor) {
			cTemp = cTemp->next;
		}

		this->cursor = cTemp;

		cTemp = NULL;

		return true;
	} else {
		return false;
	}
}

bool ListN::insertAfter(int src) {
	if(this->isEmpty()) {
		Node* temp = new Node(src, NULL);

		this->cursor = temp;
		this->head = temp;

		temp = NULL;

		return true;
	} else {
		Node* temp = new Node(src, this->cursor->next);

		this->cursor->next = temp;
		this->cursor = temp;

		temp = NULL;

		return true;
	}
} 

bool ListN::insertBefore(int src) {
	if(this->isEmpty()) {
		Node* temp = new Node(src, NULL);

		this->cursor = temp;
		this->head = temp;

		temp = NULL;

		return true;

	} else {
		if(this->cursor == this->head) {
			Node* temp = new Node(src, this->head);

			this->head = temp;
			this->cursor = temp;

			temp = NULL;

			return true;
		} else {
			Node* cTemp = this->head;

			while(cTemp->next != this->cursor) {
				cTemp = cTemp->next;
			}

			Node* temp = new Node(src, cTemp->next);

			cTemp->next = temp;

			this->cursor = cTemp->next;

			cTemp = NULL;
			temp = NULL;

			return true;
		}
	}
}

int ListN::getAtCursor() const {
	Node* temp = this->cursor;
	int tempInt = temp->data;

	temp = NULL;
	return tempInt;
}

bool ListN::remove() {
	if(!this->isEmpty()) {
		if(this->head == this->cursor) {

			Node* cTemp = this->cursor;

			if(this->head = cTemp) {
				this->head = cTemp->next;
			}
			if(cTemp->next != NULL) {
				this->cursor = this->cursor->next;
			}
			delete [] cTemp;

			cTemp = NULL;

			return true;
		} else {
			Node* hTemp;
			Node* cTemp = this->cursor;

			this->goToPrior();

			hTemp = this->cursor;

			this->cursor->next = cTemp->next;
			this->cursor = cTemp->next;
			delete [] cTemp;

			hTemp = NULL;
			cTemp = NULL;

			return true;
		}

	} else {
		return false;
	}
}

bool ListN::isEmpty() const {
	if(this->cursor == NULL && this->head == NULL) {
		return true;
	} else {
		return false;
	}
}

bool ListN::isFull() const {
	return false;
}

void ListN::clear() {
	if(!this->isEmpty()) {
		Node* temp;
		Node* hTemp = this->head;

		// moves hTemp to end
		while(hTemp->next != NULL) {
			hTemp = hTemp->next;
		}
		// moves temp to next node, delete head, then moves head to temp
		while(this->head->next != NULL) {
			temp = this->head->next;
			delete [] this->head;

			this->head = temp;
		}

		// delete last node
		delete [] this->head;

		this->head = NULL;
		this->cursor = NULL;

		temp = NULL;
		hTemp = NULL;
	}
}

ListN& ListN::operator=(const ListN& src) {
	if(!this->isEmpty()) {
		this->clear();

		Node* hTemp = src.head;
		Node* temp = new Node(hTemp->data, NULL);
		Node* thsTemp = temp;

		this->head = temp;
		hTemp = hTemp->next;

		while(hTemp->next != NULL) {
			temp = new Node(hTemp->data, NULL);
			thsTemp->next = temp;

			if(src.cursor == hTemp) {
				this->cursor = temp;
			}

			hTemp = hTemp->next;
			thsTemp = thsTemp->next;
		}

		temp = new Node(hTemp->data, NULL);
		thsTemp->next = temp;

		if(src.cursor == hTemp) {
			this->cursor = temp;
		}

		hTemp = NULL;
		temp = NULL;
		thsTemp = NULL;

		return *this;
	} else {
		Node* hTemp = src.head;
		Node* temp = new Node(hTemp->data, NULL);
		Node* thsTemp = temp;

		this->head = temp;
		hTemp = hTemp->next;

		while(hTemp->next != NULL) {
			temp = new Node(hTemp->data, NULL);
			thsTemp->next = temp;

			if(src.cursor == hTemp) {
				this->cursor = temp;
			}

			hTemp = hTemp->next;
			thsTemp = thsTemp->next;
		}

		temp = new Node(hTemp->data, NULL);
		thsTemp->next = temp;

		if(src.cursor == hTemp) {
			this->cursor = temp;
		}

		hTemp = NULL;
		temp = NULL;
		thsTemp = NULL;

		return *this;
	}
}

ostream& operator<<(ostream& os, const ListN& src) {
	Node* hTemp = src.head;

	if(!src.isEmpty()) {
		while(hTemp->next != NULL) {
			if(src.cursor == hTemp) {
				cout << "[" << hTemp->data << "] ";
				hTemp = hTemp->next;
			} else {
				cout << hTemp->data << " ";
				hTemp = hTemp->next;
			}
		}

		if(src.cursor == hTemp) {
			cout << "[" << hTemp->data << "]" << endl;
		} else {
			cout << hTemp->data << endl;
		}
	}

	hTemp = NULL;

	return os;
}