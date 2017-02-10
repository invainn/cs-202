#include <iostream>
#include <string.h>

#include "stackA.h"
#include "stackN.h"
#include "queueA.h"
#include "queueN.h"

using namespace std;

#define TEST_STACK_A    1
#define TEST_STACK_N    2
#define TEST_QUEUE_A    3
#define TEST_QUEUE_N    4
#define QUIT            5

int prompt();
bool testStackA();
bool testStackN();
bool testQueueA();
bool testQueueN();

int main(int argc, char const *argv[])
{
   int menuSelection;

   do
   {
      menuSelection = prompt();

      switch (menuSelection)
      {
         case TEST_STACK_A:

            cout << endl;
            if (!testStackA())
            {
               cout << "array based stack: ";
               cout << "errors detected" << endl;
            }
            else
            {
               cout << "array based stack: ";
               cout << "tests passed, visually inspect outputs" << endl << endl;
            }

            break;

         case TEST_STACK_N:

            cout << endl;
            if (!testStackN())
            {
               cout << "node based stack: ";
               cout << "errors detected" << endl;
            }
            else
            {
               cout << "node based stack: ";
               cout << "tests passed, visually inspect outputs" << endl << endl;
            }

            break;

         case TEST_QUEUE_A:

            cout << endl;
            if (!testQueueA())
            {
               cout << "array based queue: ";
               cout << "errors detected" << endl;
            }
            else
            {
               cout << "array based queue: ";
               cout << "tests passed, visually inspect outputs" << endl << endl;
            }

            break;

         case TEST_QUEUE_N:

            cout << endl;
            if (!testQueueN())
            {
               cout << "node based queue: ";
               cout << "errors detected" << endl;
            }
            else
            {
               cout << "node based queue: ";
               cout << "tests passed, visually inspect outputs" << endl << endl;
            }

            break;

         case QUIT:
            break;

         default:
            cout << "invalid option" << endl << endl;
            break;
      }

   }
   while (menuSelection != QUIT);



   return 0;
}

int prompt()
{
   static int selection;

   cout << "Stack/Queue Test Program Main Menu:" << endl;
   cout << "1. Run array based stack test." << endl;
   cout << "2. Run node based stack test." << endl;
   cout << "3. Run array based queue test." << endl;
   cout << "4. Run node based queue test." << endl;
   cout << "5. Quit." << endl;

   cin >> selection;

   return selection;
}

bool testStackA()
{
   bool passed = true;

   stackA s1(3), s2;

   s1.push(1);
   cout << "Stack 1: push 1..." << endl;
   cout << s1;

   s1.push(2);
   cout << "Stack 1: push 2..." << endl;
   cout << s1;

   s1.push(3);
   cout << "Stack 1: push 3..." << endl;
   cout << s1;

   stackA s3(s1);

   cout << "Print stack 1 and stack 3, should be: 3 2 1" << endl;

   cout << "Stack 1: " << s1;

   cout << "Stack 3: " << s3;

   cout << "full(): ";
   if (s1.full())
   {
      cout << "passed" << endl;
   }
   else
   {
      cout << "failed" << endl;
      passed = false;
   }

   cout << "empty(): ";
   if (s2.empty())
   {
      cout << "passed" << endl;
   }
   else
   {
      cout << "failed" << endl;
      passed = false;
   }

   cout << "detect full stack: ";
   if (s1.push(0))
   {
      cout << "failed" << endl;
      passed = false;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "equality operator: ";
   if (!(s1 == s3) || s1 == s2)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "assignment operator: ";
   s2 = s1;
   if (s1 == s2)
   {
      cout << "passed" << endl;
   }
   else
   {
      passed = false;
      cout << "failed" << endl;
   }

   cout << "getTop(): ";
   if (s2.getTop() != 3)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "clear: ";
   if (!s1.clear())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   s3.pop();
   cout << "Stack 3: pop 3" << endl;
   cout << "Stack 3: " << s3;

   s3.pop();
   cout << "Stack 3: pop 2" << endl;
   cout << "Stack 3: " << s3;

   s3.pop();
   cout << "Stack 3: pop 1" << endl;
   cout << "Stack 3: " << s3;

   cout << "detect empty stack: ";
   if (s3.pop())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   return passed;
}

bool testStackN()
{
   bool passed = true;

   stackN s1, s2;

   s1.push(1);
   cout << "Stack 1: push 1..." << endl;
   cout << s1;

   s1.push(2);
   cout << "Stack 1: push 2..." << endl;
   cout << s1;

   s1.push(3);
   cout << "Stack 1: push 3..." << endl;
   cout << s1;

   stackN s3(s1);

   cout << "Print stack 1 and stack 3, should be: 3 2 1" << endl;

   cout << "Stack 1: " << s1;

   cout << "Stack 3: " << s3;

   cout << "empty(): ";
   if (s2.empty())
   {
      cout << "passed" << endl;
   }
   else
   {
      cout << "failed" << endl;
      passed = false;
   }

   cout << "equality operator: ";
   if (!(s1 == s3) || s1 == s2)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "assignment operator: ";
   s2 = s1;
   if (s1 == s2)
   {
      cout << "passed" << endl;
   }
   else
   {
      passed = false;
      cout << "failed" << endl;
   }

   cout << "getTop(): ";
   if (s2.getTop() != 3)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "clear: ";
   if (!s1.clear())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   s3.pop();
   cout << "Stack 3: pop 3" << endl;
   cout << "Stack 3: " << s3;

   s3.pop();
   cout << "Stack 3: pop 2" << endl;
   cout << "Stack 3: " << s3;

   s3.pop();
   cout << "Stack 3: pop 1" << endl;
   cout << "Stack 3: " << s3;

   cout << "detect empty stack: ";
   if (s3.pop())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   return passed;
}

bool testQueueA()
{
   bool passed = true;

   queueA q1(3), q2;

   q1.enqueue(1);
   cout << "Queue 1: enqueue 1..." << endl;
   cout << q1;

   q1.enqueue(2);
   cout << "Queue 1: enqueue 2..." << endl;
   cout << q1;

   q1.enqueue(3);
   cout << "Queue 1: enqueue 3..." << endl;
   cout << q1;

   queueA q3(q1);

   cout << "Print Queue 1 and Queue 3, should be: 1 2 3" << endl;

   cout << "Queue 1: " << q1;

   cout << "Queue 3: " << q3;

   cout << "full(): ";
   if (q1.full())
   {
      cout << "passed" << endl;
   }
   else
   {
      cout << "failed" << endl;
      passed = false;
   }

   cout << "empty(): ";
   if (q2.empty())
   {
      cout << "passed" << endl;
   }
   else
   {
      cout << "failed" << endl;
      passed = false;
   }

   cout << "detect full Queue: ";
   if (q1.enqueue(0))
   {
      cout << "failed" << endl;
      passed = false;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "equality operator: ";
   if (!(q1 == q3) || q1 == q2)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "assignment operator: ";
   q2 = q1;
   if (q1 == q2)
   {
      cout << "passed" << endl;
   }
   else
   {
      passed = false;
      cout << "failed" << endl;
   }

   cout << "getTop(): ";
   if (q2.getFront() != 1)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "clear: ";
   if (!q1.clear())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   q3.dequeue();
   cout << "Queue 3: dequeue 1" << endl;
   cout << "Queue 3: " << q3;

   q3.dequeue();
   cout << "Queue 3: dequeue 2" << endl;
   cout << "Queue 3: " << q3;

   q3.dequeue();
   cout << "Queue 3: dequeue 3" << endl;
   cout << "Queue 3: " << q3;

   cout << "detect empty Queue: ";
   if (q3.dequeue())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   return passed;
}

bool testQueueN()
{
   bool passed = true;

   queueN q1, q2;

   q1.enqueue(1);
   cout << "Queue 1: enqueue 1..." << endl;
   cout << q1;

   q1.enqueue(2);
   cout << "Queue 1: enqueue 2..." << endl;
   cout << q1;

   q1.enqueue(3);
   cout << "Queue 1: enqueue 3..." << endl;
   cout << q1;

   queueN q3(q1);

   cout << "Print Queue 1 and Queue 3, should be: 1 2 3" << endl;

   cout << "Queue 1: " << q1;

   cout << "Queue 3: " << q3;

   cout << "empty(): ";
   if (q2.empty())
   {
      cout << "passed" << endl;
   }
   else
   {
      cout << "failed" << endl;
      passed = false;
   }

   cout << "equality operator: ";
   if (!(q1 == q3))
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "assignment operator: ";
   q2 = q1;
   if (q1 == q2)
   {
      cout << "passed" << endl;
   }
   else
   {
      passed = false;
      cout << "failed" << endl;
   }

   cout << "getTop(): ";
   if (q2.getFront() != 1)
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   cout << "clear: ";
   if (!q1.clear())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   q3.dequeue();
   cout << "Queue 3: dequeue 1" << endl;
   cout << "Queue 3: " << q3;

   q3.dequeue();
   cout << "Queue 3: dequeue 2" << endl;
   cout << "Queue 3: " << q3;

   q3.dequeue();
   cout << "Queue 3: dequeue 3" << endl;
   cout << "Queue 3: " << q3;

   cout << "test" << endl;

   cout << "detect empty Queue: " << endl;
   if (q3.dequeue())
   {
      passed = false;
      cout << "failed" << endl;
   }
   else
   {
      cout << "passed" << endl;
   }

   return passed;
}