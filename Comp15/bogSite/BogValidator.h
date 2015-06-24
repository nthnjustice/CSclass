//
// this must be in a header file called BogValidator.h
//
class BogValidator
{
public:
	BogValidator(); //constructor
	~BogValidator(); //destructor
	bool readDict(); // read in a dictionary
	bool readBoard(); // read in a board
	bool isValid(string s); // validates one word
	void checkWords(); // validates cin

	private:
	Dictionary dict; // must use a Dictionary
	// other private methods or data may appear here
};	
