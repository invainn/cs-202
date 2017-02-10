class Stack {
	public:
		Stack();
		~Stack();

		bool push(int);
		bool pop(int&);

	private:
		int data[10]; // stored integers
		int top; // location of "top" stack (indicates # of stored values)
};