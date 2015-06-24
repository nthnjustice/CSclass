#include <iostream>
#include <string>
#include <cctype>
#include "BogWordList.h"
using namespace std;

//object that represents a node/tile of the boggle board
struct Tile{
	string letter;
	bool visited; //if the node has been visited = true
};

class BogSolver{
	public:
		BogSolver(); //constructor
		~BogSolver(); //destructor
		bool readDict(); //read in a dictionary
		bool readBoard(); //read in a board
		bool solve(); // search board for words in dict
		int numWords(); // returns number of words found
		int numWords(int len); // number of words of length len
		BogWordList* getWords(); // returns all words found
		BogWordList* getWords(int len); // returns words of len len
		void printWords(); // print all words in HBF
		void printWords(int len); // print len-length words in HBF
		void listWords(); // print just the text, no coords
		void listWords(int len); // just the text, no coords
	private:
		Dictionary dict; // must use a Dictionary
		// other private methods or data may appear here

		Tile** bogBoard; //boggle board
		BogWordList wordList; //list of words found by the program
		int boardSize; //size of the board
		int wordListCapacity; //number of words in the program list

		void fillBoard(); //builds the boggle board
		void traverse(string tempWord, int row, int col); //searches the board
		void store(string tempWord); //stores a found word in the list
		void expand(); //expands the size of the list for new words
};

