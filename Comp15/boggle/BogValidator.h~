#include "BogSolver.h"

//object represents a Node for the linked-list of user answers
struct ANode{
	string word;
	bool validity;//if the word is valid = true
	ANode* next;
};

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
	
	BogSolver solved; //uses an object of the solver program to compare with
	ANode* head; //pointer to the head of the linked-list of user's answers
	Tile** bogBoard; //boggle board
	int boardSize; //size of the boggle board
	int wordListCapacity; //number of approved words
	BogWordList wordList;	//list of user words

	void fillBoard(); //builds the boggle board
	void output(); //print function
	void takeInput(); //helper function for fillBoard(), helps build the board
};	
