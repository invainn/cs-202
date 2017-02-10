#include <iostream>

using namespace std;

class stackA{
        public:
                stackA(int = 10);
                stackA(const stackA&);
                ~stackA();
                stackA& operator=(const stackA&);
                bool push(int);
                bool pop();
                int getTop();
                bool empty() const;
                bool full() const;
                bool clear();
				bool operator==(const stackA&) const;
                friend ostream& operator<<(ostream&, const stackA&);
        private:
                int max;
                int top;
                int* data;
};

