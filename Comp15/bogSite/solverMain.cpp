//
// this must be in a file called solverMain.cpp
//
#include "bbsolver.h"

int main()
{
	BogSolver solver;

	solver.readDict();
	solver.readBoard();

	//solver.solve();
	//solver.printWords();
	return 0;
}
