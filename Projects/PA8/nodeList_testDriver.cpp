#include "listnode.h"
#include <iostream>

using namespace std;

bool NODE = true;

int main() 
{
	int size = 7;
	int c;	
	ListNode l(size);
	ListNode copy;
	int selection;

	do{
		cout << endl << endl;
		cout << "1. insert at the end" << endl;
		cout << "2. insert in the middle" << endl;
		cout << "3. remove" << endl;
		cout << "4. assignment operator" << endl;
		cout << "5. copy constructor" << endl;

		cout << "6. gotoBeginning" << endl;
		cout << "7. gotoNext" << endl;
		cout << "8. gotoPrior" << endl;
		cout << "9. gotoEnd" << endl;
		cout << "10. clear" << endl;
		cout << "11. quit" << endl << endl;

		cout << "Please select an option: ";
		cin >> selection;

		cout << endl << endl << "****************************************" << endl;

		switch(selection)
		{
			case 1:
			for(int i = 0; i < size-1; i++) 
			{
				if(!l.insertAfter(i)) 
				{
					cout << "inserting " << i;			
					cout << "Error in insertAfter" << endl;
				}
			}

			cout << "Print out the list (should be 0 1 2 3 4 [5]):" << endl;
			cout << l;
			cout << endl << endl;

			break;


			case 2:
			l.goToPrior();
			l.goToPrior();

			cout << "Inserting 777: " << endl;
			if(!l.insertBefore(777)) 
			{
				cout << "Error in inserting 777" << endl;
			}

			if(!NODE)
			{
				cout << "Try to insert when full (should not insert): " << endl;

				if(l.insertAfter(-1)) 
				{
					cout << "Error detecting overflow" << endl << endl;
				}
				else
				{
					cout << "Did not insert" << endl << endl;
				}
			}

			cout << "Print out the list (should be 0 1 2 [777] 3 4 5):" << endl;
			cout << l;
			cout << endl << endl;


			cout << "Removing 777: " << endl;
			if(!l.remove(c)) 
			{
				cout << "Error Remove " << endl;
			}

			cout << "Print out the list (should be 0 1 2 [3] 4 5):" << endl;
			cout << l;
			cout << endl << endl;
			break;

			case 3:
			cout << "remove 3" << endl;		
			if(!l.remove(c)) 
			{
				cout << "Error in remove" << endl;
			}

			cout << "Print out the list (should be 0 1 2 [4] 5):" << endl;
			cout << l;
			cout << endl << endl;
			break;


			case 4:
			copy = l;
			cout << "Print out original list (should be 0 1 2 [4] 5):" << endl;
			cout << l;
			cout << endl << endl;

			cout << "Print out copied list (should be 0 1 2 [4] 5):" << endl;
			cout << copy;
			cout << endl << endl;
			break;


			case 5:
			{
				ListNode copy2  = l;

				cout << "Print out original list (should be 0 1 2 [4] 5):" << endl;
				cout << l;
				cout << endl << endl;

				cout << "Print out copied list (should be 0 1 2 [4] 5):" << endl;
				cout << copy2;
				cout << endl << endl;
			}
			break;








			case 6:
			if(!l.goToBeginning()) 
			{
				cout << "Error in gotoBeginning" << endl;
			}

			cout << "Print out the list (should be [0] 1 2 4 5):" << endl;
			cout << l;
			cout << endl << endl;

			break;



			case 7:
			if(!l.goToNext()) 
			{
				cout << "Error in gotoNext" << endl;
			}
			cout << "Print out the list (should be 0 [1] 2 4 5):" << endl;
			cout << l;
			cout << endl << endl;
			break;

			case 8:
			if(!l.goToPrior()) 
			{
				cout << "Error in gotoPrior" << endl;
			}
			cout << "Print out the list (should be [0] 1 2 4 5):" << endl;
			cout << l;
			cout << endl << endl;
			break;

			case 9:
			if(!l.goToEnd()) 
			{
				cout << "Error in gotoEnd" << endl;
			}
			cout << "Print out the list (should be 0 1 2 4 [5]):" << endl;
			cout << l;
			cout << endl << endl;

			break;	

			case 10:
			l.clear();
			

			if(!l.isEmpty()) 
			{
				cout << "Error: says not empty when list should be empty" << endl;
			}
			cout << "Print out the list (should print nothing):" << endl;
			cout << l;
			cout << endl << endl;

			break;


			cout << endl << endl << "****************************************" << endl;
		}
	}
	while(selection != 11);
	


}
