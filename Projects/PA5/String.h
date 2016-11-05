
class String{

public:
	void initialize(char *);
	void deallocate();

	void copy(const String&);
	int length() const;
	void concat(const String&);
	int compare(const String&);

	void print();

private:
	char * buffer;
	int wordLength;
};
