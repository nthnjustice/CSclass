//
// this must be in a file called checkerMain.cpp
//
#include "BogValidator.h"

int main()
{
	BogValidator v;
	v.readDict();
	v.readBoard();
	v.checkWords();
	return 0;
}
