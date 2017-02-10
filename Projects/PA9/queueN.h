#include <iostream>

using namespace std;

class queueN;

class NodeQ{
	private:
		NodeQ(int, NodeQ*);
		int data;
		NodeQ* next;
		friend class queueN;
		friend ostream& operator<<(ostream&, const queueN&);
};

class queueN{
		public:
				queueN();
				queueN(const queueN&);
  				~queueN();
				queueN& operator=(const queueN&);
				bool enqueue(int);
				bool dequeue();
				int getFront();
				bool empty() const;
				bool full() const;
				bool clear();
				bool operator==(const queueN&) const;
				friend ostream& operator<<(ostream&, const queueN&);
		private:
				NodeQ* front;
				NodeQ* rear;
};