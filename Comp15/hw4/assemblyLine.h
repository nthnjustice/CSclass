#include <iostream> 
#include "packQ.h"
using namespace std;

struct Worker{
	//Rate that a worker processes units 
	double packRate;
};

class AssemblyLine{
public:
	//Constructor - builds a dynamic array of workers 
	AssemblyLine();

	//Destructor - destroys the dynamic array of workers 
	//	~~~Commented out because it crashes my program~~~
	//~AssemblyLine();

	//The worker that belongs to an assembly-line
	Worker worker;

	//Pulls the package queue for the assembly-line from private data
	PackQ* getAssQ();

	//Returns true if the package being working on by assembly-line is finished
	bool complete();

	//Adds the number of units of the packages in the queue
	double numUnitsInQueue();

private:
	//Pointer to a linked-list queue of packages for the assembly-line to work
	//	on
	PackQ* assQ;
};
