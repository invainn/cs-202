#include <iostream>

#include "listnode.h"

using namespace std;

int main() {

	ListNode list1;

	list1.insertAfter(1500);
	list1.insertAfter(5000);
	list1.insertAfter(50000);
	list1.insertAfter(50003);

	cout << list1;

	int c;

	list1.get(c);

	cout << c << endl;

	ListNode list2(list1);

	cout << list2;

	list2.get(c);

	cout << c << endl;
	
	list2.get(c);

	cout << c << endl;

	cout << list2;

	return 0;
}