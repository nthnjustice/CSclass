#include "factory.h" 

/*****************************************************************************
Precondition: Constructor - no precondition
Postconition: Builds a dynamic array of assembly-lines and sets the capacity
to 1, sets the queue pointer to a new instance of a queue
~~~Not utilized with this implementation of main~~~
*****************************************************************************/
Factory::Factory()
{
	assemblyLinesCapacity = 1;
	assemblyLines = new AssemblyLine [assemblyLinesCapacity];
	theQueue = new PackQ;
}

/*****************************************************************************
Precondition: Overloader constructor - no precondition
Postcondition: Builds a dynamic array of assembly-lines with a capacity taken
	from main and sets the worker rate for each assembly-line
	also sent in by main, sets the queue pointer to a new instance of a queue
*****************************************************************************/
Factory::Factory(int numWorkers, double* workerRates)
{
	assemblyLinesCapacity = numWorkers;
	assemblyLines = new AssemblyLine [assemblyLinesCapacity];
	for (int i = 0; i < assemblyLinesCapacity; i++){
		assemblyLines[i].worker.packRate = workerRates[i];
	}

	theQueue = new PackQ;
}

/****************************************************************************
Precondition: Destructor - dynamic array of assembly-lines
Postconition: Destroys the dynamic array of assembly-lines
*****************************************************************************/
Factory::~Factory()
{
	delete[] assemblyLines;
}

/****************************************************************************
Precondition: Function called by main
Postcondition: Calls the function that parses the input for impotant 
	information, calls the function that processes the packages
*****************************************************************************/
int Factory::run()
{	
	//Function parses input
	buffer();
	//Function processes packages
	doWork();

	return 0;
}

/****************************************************************************
Precondition: There is a text file with information for the packages that
need to be loaded into the queue and processed
Postcondition: Packages are built with important information from the text
file and loads the packages into the queue
*****************************************************************************/
void Factory::buffer()
{
	string junk;
	string tempOrderNum;
	int tempUnits;
	int tempArrivalTime;
	int lineSpot = 1;
	Package tempPkg;

	while (cin >> junk){
		switch (lineSpot){
		case 4:
			tempOrderNum = junk;
			break;
		case 6:
			tempUnits = atoi(junk.c_str());
			break;
		case 11:
			tempArrivalTime = atoi(junk.c_str());
			tempPkg.arrivalTime = tempArrivalTime;
			tempPkg.orderNum = tempOrderNum;
			tempPkg.units = tempUnits;
			tempPkg.originalUnits = tempUnits;
			theQueue->insert(tempPkg);
		case 12:
			lineSpot = 0;
			break;
		}
		lineSpot++;
	}

}

/****************************************************************************
Precondition: There is a variable for the capacity of the dynamic array of
	assembly-lines in private data
Postconition: The capacity for the dynamic array is pulled and brought to
	public domain
*****************************************************************************/
int Factory::getAssemblyLinesCapacity()
{
	return assemblyLinesCapacity;
}


/****************************************************************************
Precondition: There exists a linked-list queue of packages, and a dynamic
	array of assembly-lines
Postconition: Processes each package in all assembly-lines queues to 
	completion and sends the processing information to a print function, manages 
	the factory clock
*****************************************************************************/
int Factory::doWork()
{
	//Factory clock
	int clock = 0;

	//Loop runs until there are no more Nodes in any linked-list queue (factory queue and for each assembly-line)
	while (!programEnd()){
		if (!theQueue->isEmpty()){
			assemblyLines[dispatcher()].getAssQ()->insert(theQueue->getFront()->pkg);
			theQueue->remove();
		}
		clock++;

		for (int i = 0; i < assemblyLinesCapacity; i++){
			if (!assemblyLines[i].getAssQ()->isEmpty()){
				//Does work on each assembly-line at the rate of the worker
				assemblyLines[i].getAssQ()->getFront()->pkg.units = assemblyLines[i].getAssQ()->getFront()->pkg.units - assemblyLines[i].worker.packRate;
				//Checks to see if the package being worked on has been completed
				if (assemblyLines[i].complete()){
					//If the package has been completed, the information is printed
					output(assemblyLines[i].getAssQ()->getFront(), assemblyLines[i], clock, i);
					assemblyLines[i].getAssQ()->remove();
				}
			}
		}

	}

	return 0;
}

bool Factory::programEnd()
{
	//Check to see if the factory queue is empty
	if (theQueue->isEmpty()){
		for (int i = 0; i < assemblyLinesCapacity; i++){
			//Checks to see if the queue of each assembly-line is finshed
			if (!assemblyLines[i].getAssQ()->isEmpty()){
				//Returns false if there is a package in an assembly-line queue
				return false;
			}
		}
		//Returns true if all queues are empty
		return true;
	}
	//Returns false if there is a package in the factory queue
	return false;
}

/****************************************************************************
Precondition: A package has been processed over time, subtracting an
appropriate number of units per unit time according to the worker's packing-
rate
Postconition: Prints the output statements with the processing information for
each package
*****************************************************************************/
void Factory::output(Node* packageInWorking, AssemblyLine assemblyLine, int clock, int i)
{

	cout << "Package order number " << packageInWorking->pkg.orderNum;
	cout << " with " << assemblyLine.getAssQ()->getFront()->pkg.originalUnits;
	cout << " units arrived at time " << packageInWorking->pkg.arrivalTime;
	cout << " and left at time " << clock;
	cout << " from " << i + 1 << endl;
}

/****************************************************************************
Precondition: Packages exist on the 
Postcondition:
*****************************************************************************/
int Factory::dispatcher()
{
	return checkLines_PACKAGES(assemblyLines, assemblyLinesCapacity);
}
