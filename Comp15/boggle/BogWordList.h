#include "dictionary.h"

//a boggle letter
struct BogLett {
	char c;
	int row, col; //coordinates in the board
};

//a boggle word
struct BogWord {
	int numLetts;
	BogLett* letts; //pointer to an array of characters
};

//a list of boggle words
struct BogWordList {
	int numWords;
	BogWord* words; //pointer to an array of words
};


