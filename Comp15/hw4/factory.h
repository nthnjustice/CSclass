#include <string>
#include <stdlib.h> 
#include "dispatcher.h"
using namespace std;

class Factory{
public:

	//Constructor - builds a dynamic array of assembly-lines 
	Factory();

	//Overloading constructor - builds a dynamic array of assembly-lines 
	//	of size numWorkers and assigns their rates from the dynamic array
	//		of double (workerRates) 
	Factory(int numWorkers, double* workerRates);

	//Destructor - destroys the dynamic array of assembly-lines 
	~Factory();

	//Called by main to start the program 
	int run();

	//Takes in input from a file and holds the important information 
	void buffer();
	
	//Pulls the assembly-line capacity from private variable 
	int getAssemblyLinesCapacity();

	//Runs the simulation, proceses the packages in the factory queue 
	int doWork();

	//Returns true if there are no more packages in the factory queue nor in
	//	any assembly-line queue to be processed
	bool programEnd();

	//Prints the output messages 
	void output(Node* packageInWorking, AssemblyLine assemblyLine, 
					int clock, int i);

	//Determines which assembly-line a package from the factory queue goes into
	int dispatcher();

private:
	//A pointer to the factory queue that will hold packages to be processed 
	PackQ* theQueue;

	//Pointer to a dynamic array of assembly-lines 
	AssemblyLine* assemblyLines;

	//Number of assembly-lines in the dynamic array 
	int assemblyLinesCapacity;
};
