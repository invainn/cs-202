#include <iostream>
using namespace std;


class ListA
{         
 public:               
   ListA(int);               
   ListA(const ListA&);               
   ~ListA();              
   bool goToBeginning();   
   bool goToEnd();   
   bool goToNext();
   bool goToPrior();                             
   bool insertBefore(int);   
   bool insertAfter(int); 
   int getAtCursor() const;              
   bool remove();                             
   bool isEmpty() const;               
   bool isFull() const;               
   void clear();
   ListA& operator=(const ListA&);
   friend ostream& operator<<(ostream&, const ListA&);           
 private:               
   int size;
   int actual;               
   int cursor;               
   int *data; 
};
     