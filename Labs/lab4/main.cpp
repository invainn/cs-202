#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
  bool test = false;
  Stack s;

  test = s.push(2);

  if(test) {
    cout << "First push successful!" << endl;
  } else {
    cout << "First push failed." << endl;
  }

  for(int i = 0; i < 8; i++) {
    test = s.push(i);
    if(!test) {
      cout << 1 << endl;
    }
  }

  test = s.push(10);

  if(test) {
    cout << "Second push successful!" << endl;
  } else {
    cout << "Second push failed." << endl;
  }

  int pop_value;

  while(s.pop(pop_value)) {
    cout << "Popped: " << pop_value << endl;
  }

  return 0;
}
