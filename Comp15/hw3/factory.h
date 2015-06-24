#include <iostream>
#include <string>
#include <stdlib.h>
#include "AssemblyLine.h"
#include "PackQ.h"
using namespace std;

class Factory{
	public:
		//Constructor - builds a dynamic array of assembly-lines
		Factory();
		//Destructor - destroys the dynamic array of assembly-lines
		~Factory();
		 
		//Called by main to start the program
		int run(int numWorkers, double* workerRates);
		//Takes in input from a file and holds the important information
		void buffer();

		//Pulls the first assembly-line in the dynamic array from private variable
		AssemblyLine* getAssemblyLines();
		//Pulls the assembly-line capacity from private variable
		int getAssemblyLinesCapacity();
		//Pulls the time from private variable
		int getTime();

		//Pulls the first worker in the dynamic array from private variable
		Worker pullWorker();
	
		//Runs the simulation, proceses the packages in the Queue
		int doWork();
		//Prints the output messages
		void output(Package packageInWorking, double unitTemp);

	private:
		//The queue full of packages to be processed
		PackQ theQueue;
		//Pointer to a dynamic array of assembly-lines
		AssemblyLine* assemblyLines;
		//Number of assembly-lines in the dynamic array
		int assemblyLinesCapacity;	
		//Keeps track of the simulation time
		int clock;
};
