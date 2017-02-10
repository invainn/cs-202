#include <iostream>

using namespace std;

class queueA{
        public:
                queueA(int = 10);
                queueA(const queueA&);
                ~queueA();
                queueA& operator=(const queueA&);
                bool enqueue(int);
                bool dequeue();
                int getFront();
                bool empty() const;
                bool full() const;
                bool clear();
                bool operator==(const queueA&) const;
                friend ostream& operator<<(ostream&, const queueA&);
        private:
                int max;
                int front;
                int rear;
                int *data;
};

