#include <iostream>
using namespace std; 


class ListN; 

class Node
{
 private:
   Node(int, Node*); 
   int data; 
   Node* next;
   friend class ListN;
   friend ostream& operator<<(ostream&, const ListN&); 
};
   
class ListN
{         
 public:               
   ListN();               
   ListN(const ListN&);               
   ~ListN();                 
   bool goToBeginning();
   bool goToEnd();   
   bool goToNext();               
   bool goToPrior();              
   bool insertBefore(int);   
   bool insertAfter(int);
   int getAtCursor() const;
   bool remove();                             
   bool isEmpty() const;               
   bool isFull() const; // Return False by default               
   void clear();
   ListN& operator=(const ListN&);               
   friend ostream& operator<<(ostream&, const ListN&);         
 private:
   Node* head;   
   Node* cursor;
};
     