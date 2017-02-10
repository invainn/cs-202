#include <iostream>
#include <cstring>

using namespace std;

template<typename T>

class Stack {
        public:
                Stack(int maxTemp) {
                        this->max = maxTemp;
                        this->top = -1;
                        this->data = new T[max];
                }
                Stack(const Stack& src) {
                        this->max = src.max;
                        this->top = src.top;

                        this->data = new T[src.max];

                        for(int i = 0; i < src.top+1; i++) {
                                this->data[i] = src.data[i];
                        }
                }
                ~Stack() {
                        delete [] this->data;
                        this->data = NULL;
                }
                Stack<T>& operator=(const Stack& src){
                        this->max = src.max;
                        this->top = src.top;

                        delete [] this->data;
                        this->data = NULL;

                        this->data = new T[src.max];

                        for(int i = 0; i < src.top+1; i++) {
                                this->data[i] = src.data[i];
                        }
                }
                bool push(T src) {
                        if(!this->full()) {
                                this->top++;

                                this->data[top] = src;

                                return true;
                        } else {
                                return false;
                        }
                }
                bool pop(T& src){
                        if(!this->empty()) {
                                src = this->data[top];

                                this->top--;

                                return true;
                        } else {
                                return false;
                        }
                }
                bool empty() const {
                        if(this->top == -1) {
                                return true;
                        } else {
                                return false;
                        }
                }
                bool full() const {
                        if(this->top == this->max) {
                                return true;
                        } else {
                                return false;
                        }
                }
                bool clear() {
                        if(!this->empty()) {
                                while(this->top != -1) {
                                        this->top--;
                                }

                                return true;
                        } else {
                                return false;
                        }
                }
		bool operator==(const Stack& src) const {
                        int tempTop = src.top;

                        while(tempTop != -1) {
                                if(this->data[top] != src.data[src.top]) {
                                        return false;
                                }
                        }

                        return true;
                }

                friend ostream& operator<<(ostream& os, const Stack<T>& inp) {
                        int tempTop = inp.top;

                        while(tempTop != -1) {
                                cout << inp.data[tempTop] << " ";
                                tempTop--;
                        }

                        return os;
                }
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                T* data;
};

