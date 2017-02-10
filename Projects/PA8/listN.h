#ifndef LIST_H 
#define LIST_H 
#include <iostream>
using namespace std; 

const bool NODE = true;

class List; 

class Node
{
 private:
   Node(int, Node*); 
   int data; 
   Node* next;
   friend class List;
   friend ostream& operator<<(ostream&, const List&); 
};
   
class List
{         
 public:               
   List(int = 0);               
   List(const List&);               
   ~List();                 
   bool goToBeginning();
   bool goToEnd();   
   bool goToNext();               
   bool goToPrior();              
   bool insertBefore(int);   
   bool insertAfter(int);
   bool remove();                             
   bool isEmpty() const;               
   bool isFull() const; // Return False by default               
   void clear();
   List& operator=(const List&);               
   friend ostream& operator<<(ostream&, const List&);         
 private:
   Node* head;   
   Node* cursor;
};
#endif
     