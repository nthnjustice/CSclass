#include "factory.h"

/*****************************************************************************
Precondition: Constructor - no precondition 
Postconition: Builds a dynamic array of assembly-lines and sets the capacity
	to 1, starts the clock at 0
*****************************************************************************/
Factory::Factory()
{
	assemblyLinesCapacity = 1;
	assemblyLines = new AssemblyLine [assemblyLinesCapacity];
	clock = 0;
}

/****************************************************************************
Precondition: Destructor - dynamic array of assembly-lines
Postconition: Destroys the dynamic array of assembly-lines
*****************************************************************************/
Factory::~Factory()
{
	delete [] assemblyLines;
}

/****************************************************************************
Precondition:Function called by main where parameters are sent into the 
	program
Postcondition: Sets the size of the dynamic array of workers and assigns the
	correct worker packing-rate, calls the function that parses the input for
	important information, calls the function that processes the packages
*****************************************************************************/
int Factory::run(int numWorkers, double* workerRates)
{
	assemblyLines->assignmenting(numWorkers, workerRates);

	buffer();	
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

	while(cin >> junk){
		switch(lineSpot){
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
				theQueue.insert(tempPkg);
			case 12:
				lineSpot = 0;
				break;
		}
		lineSpot++;
	}

}

/****************************************************************************
Precondition: There is a dynamic array of assembly-lines in private data
Postconition: The private assembly-line pointer is pulled and brought to 
	public domain
*****************************************************************************/
AssemblyLine* Factory::getAssemblyLines()
{
	return assemblyLines;

}

/****************************************************************************
Precondition: There is a variable for the capacity of the dynamic array of
	assembly-lines in private data
Postconition: The capacity for the dynamic array is pulled and brought to 
	public domain
*****************************************************************************/
int Factory::getAssemblyLinesCapacity()
{
	int temp = assemblyLinesCapacity;

	return temp;
}

/****************************************************************************
Precondition: There is a variable for the run-time of the simulation in 
	private data
Postconition: The run-time of the simulation is pulled and brought to public
	domain
*****************************************************************************/
int Factory::getTime()
{
	return clock;
}

/****************************************************************************
Precondition: There is a dynamic array of workers
Postconition: Returns a pointer to the first worker in the dynamic array of
	workers
*****************************************************************************/
Worker Factory::pullWorker()
{
	//Fetches the first worker in the dynamic array of workers
	Worker temp = assemblyLines->getWorkers(); 
	return temp;
}

/****************************************************************************
Precondition: There exists a linked-list queue, a dynamic array of 
	assembly-lines, and adynamic array of workers
Postconition: Processes each package in the queue and sends the processing
	information to a print function
*****************************************************************************/
int Factory::doWork()
{
	//Gets the first worker in the dynamic array of workers
	Worker guy = pullWorker();
	//Gets the first package in the linked-list queue
	Package packageInWorking = theQueue.getFront()->pkg;
	double unitTemp = 0;
	
	//Loop runs until there are no more Nodes in the linked-list queue
	while(theQueue.getCount() > 0){
		//Tracks the units of the package before it is processed
		unitTemp = packageInWorking.units;
		if(packageInWorking.arrivalTime > clock){
			//The clock is jumped forward if a package arrives at a time later than the
			//	current time
			clock = packageInWorking.arrivalTime;
		}
		//Handles when packages have 0 units
		if(packageInWorking.units == 0){
			clock++;
		}
		//Loops run while units in the package are still present
		while(packageInWorking.units > 0){
			//Per unit time, the units of the package are removed at the rate of the
			//	worker packing-rate
			packageInWorking.units = packageInWorking.units - guy.packRate;
			//Time move forward because an action is done
			clock++;
		}
		//Calls the print function
		output(packageInWorking, unitTemp);
		//After the first package in the queue is processed, it is removed 
		theQueue.remove();
		//If the queue is empty of packages, end the processing function
		if(theQueue.isEmpty()){
			return 0;
		}
		//If the queue is not empty, grab the first package in the queue to process
		packageInWorking = theQueue.getFront()->pkg;
	}
	return 0;
} 

/****************************************************************************
Precondition: A package has been processed over time, subtracting an
	appropriate number of units per unit time according to the worker's packing-
	rate
Postconition: Prints the output statements with the processing information for
	each package
*****************************************************************************/
void Factory::output(Package packageInWorking, double unitTemp)
{
	cout << "Package order number " << packageInWorking.orderNum;
	cout << " with " << unitTemp;
	cout << " units arrived at time " << packageInWorking.arrivalTime;
	cout << " and left at time " << clock << endl;
}
