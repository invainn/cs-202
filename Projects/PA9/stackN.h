#include <iostream>

using namespace std;

class stackN;

class NodeS{
	private:
		NodeS(int, NodeS*);
		int data;
		NodeS* next;
		friend class stackN;
        friend ostream& operator<<(ostream&, const stackN&);
};

class stackN{
        public:
                stackN();
                stackN(const stackN&);
                ~stackN();
                stackN& operator=(const stackN&);
                bool push(int);
                bool pop();
                int getTop();
                bool empty() const;
                bool full() const;
                bool clear();
				bool operator==(const stackN&) const;
                friend ostream& operator<<(ostream&, const stackN&);
        private:
				NodeS* top;
};
