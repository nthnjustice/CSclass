//
// This must be in a class file called BogSolver.h
//
#include <iostream>
#include <string>
#include <cctype>
#include "BogWordList.h"
#include "dictionary.h"
using namespace std;

struct Tile{
	string letter;
	bool visited;
};

class BogSolver{
	public:
		BogSolver();
		~BogSolver();
		bool readDict();
		bool readBoard();
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

		Tile** bogBoard;
		BogWordList wordList;
		int boardSize;
		int wordListCapacity;

		void fillBoard();
		void traverse(string tempWord, int row, int col);
		void store(string tempWord);
		void expand();
		
};

