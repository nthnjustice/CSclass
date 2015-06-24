#include "BogSolver.h"

BogSolver::BogSolver()
{
	bogBoard = NULL;
	wordList.words = NULL;
	wordListCapacity = 10;
}


BogSolver::~BogSolver()
{
	delete bogBoard;

	for (int i = 0; i < wordList.numWords; i++){
		delete wordList.words[i].letts;
	}

	delete [] wordList.words;
}


bool BogSolver::readDict()
{
	string s;
	int i = 0;

	while (cin >> s){
		if (s == "."){
			break;
		}

		while (s.length() > 0){
			s[i] = toupper(s[i]);
			i++;
		}

		dict.insert(s);
	}

	return true;
}

bool BogSolver::readBoard()
{
	int junk = 0;

	cin >> boardSize;
	cin >> junk;

	bogBoard = new Tile*[boardSize];

	for (int i = 0; i < boardSize; i++){
		bogBoard[i] = new Tile[boardSize];
	}

	fillBoard();

	return true;
}

void BogSolver::fillBoard()
{
	char x;

	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			cin >> x;
			x = toupper(x);
			bogBoard[i][j].letter = x;
		}
	}
}

bool BogSolver::solve()
{
	string tempWord;
	tempWord = "";

	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			tempWord+= bogBoard[i][j].letter;
			traverse(tempWord, i, j);
			tempWord = "";
		}
	}

	return true;
}

void BogSolver::traverse(string tempWord, int row, int col)
{
	if (!dict.isPrefix(tempWord)){
		return;
	}

	if (bogBoard[row][col].visited == true){
		return;
	}

	if (dict.isWord(tempWord)){
		store(tempWord);
	}

	for (int i = row - 1; i < row + 1; i++){
		for (int j = col - 1; j < col + 1; j++){
			if ((i > 0) && (j > 0) && (j <= boardSize)){
				traverse(tempWord, row, col);
			}
		}
	}
}

void BogSolver::store(string tempWord)
{
	int intTemp = tempWord.length();

	if (wordList.words == NULL){
		wordList.words = new BogWord[wordListCapacity];
		for (int i = 0; i < intTemp; i++){
			wordList.words[0].letts[i].c = tempWord[i];
			wordList.words[0].numLetts = tempWord.length();
			wordList.numWords = 1;
		}
	}

	if (wordList.numWords >= wordListCapacity){
		expand();
	}

	for (int i = 0; i < intTemp; i++){
		wordList.words[wordList.numWords + 1].letts[i].c = tempWord[i];
		wordList.words[wordList.numWords + 1].numLetts = tempWord.length();
		wordList.numWords++;
	}
}

void BogSolver::expand()
{
	wordListCapacity = wordListCapacity * 2;
}

int BogSolver::numWords()
{
	return wordList.numWords;
}

int BogSolver::numWords(int len)
{
	int desired = 0;

	for (int i = 0; i < wordList.numWords; i++){
		if (wordList.words->numLetts == len){
			desired++;
		}
	}

	return desired;
}

BogWordList* BogSolver::getWords()
{
	BogWordList* tempList = new BogWordList;

	for (int i = 0; i < wordList.numWords; i++){
		tempList->words[i] = wordList.words[i];
	}

	return tempList;
}

BogWordList* BogSolver::getWords(int len)
{
	BogWordList* tempList = new BogWordList;

	for (int i = 0; i < wordList.numWords; i++){
		if (wordList.words->numLetts == len){
			tempList->words[i] = wordList.words[i];
		}
	}

	return tempList;
}

void BogSolver::printWords()
{

	for (int i = 0; i < wordList.numWords; i++){
		cout << "< ";
		for (int j = 0; j < wordList.words[i].numLetts; j++){
			cout << wordList.words[i].letts[j].c << " ";
			cout << wordList.words[i].letts[j].row << " ";
			cout << wordList.words[i].letts[j].col << " ";
		}
		cout << ">" << endl;
	}
}

void BogSolver::printWords(int len)
{
	for (int i = 0; i < wordList.numWords; i++){
		if (wordList.words[i].numLetts == len){
			cout << "< ";
			for (int j = 0; j < wordList.words[i].numLetts; j++){
				cout << wordList.words[i].letts[j].c << " ";
				cout << wordList.words[i].letts[j].row << " ";
				cout << wordList.words[i].letts[j].col << " ";
			}
			cout << ">" << endl;
		}
	}
}

void BogSolver::listWords()
{
	for (int i = 0; i < wordList.numWords; i++){
		for (int j = 0; j < wordList.words->numLetts; j++){
			cout << wordList.words[i].letts[j].c;
		}
	}
}
void BogSolver::listWords(int len)
{
	for (int i = 0; i < wordList.numWords; i++){
		if (wordList.words[i].numLetts == len){
			for (int j = 0; j < wordList.words->numLetts; j++){
				cout << wordList.words[i].letts[j].c;
			}
		}
	}
}
