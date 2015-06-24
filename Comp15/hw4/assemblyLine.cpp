#include "assemblyLine.h" 

/****************************************************************************
Precondition: Constructor - no precondition
Postconition: Sets the capacity of the dynamic array of workers to 1, it is
specifically defined in this implementation because this program only
handles 1 worker
*****************************************************************************/
AssemblyLine::AssemblyLine()
{
	worker.packRate = 0;
	assQ = new PackQ;

}

/****************************************************************************
Precondition: Destructor - dynamic array of workers
Postconition: Destroys the dynamic array of workers
~~~Commented out because it crashes my program~~~
*****************************************************************************/
/*AssemblyLine::~AssemblyLine()
{
	delete assQ;
}*/

/****************************************************************************
Precondition: There is an assembly-line queue in private data
Postconition: Pulls the assembly-line queue from private data to public
	domain
*****************************************************************************/
PackQ* AssemblyLine::getAssQ()
{
	return assQ;
}

/****************************************************************************
Precondition: There are packages on the assembly-line queue being processed
Postconition: Returns true if the package on the assembly-line queue being
	processed is completed, false if not
*****************************************************************************/
bool AssemblyLine::complete()
{
	if (getAssQ()->getFront()->pkg.units <= 0){
		//Returns true if the package on the assembly-line has been completed
		return true;
	}

	return false;
}

/****************************************************************************
Precondition: There are packages on the assembly-line queue being processed
Postconition: Returns the number of units of all the packages in the assembly-
	line queue
*****************************************************************************/
double AssemblyLine::numUnitsInQueue()
{
	//Temporary storage for total units of the packages in the queue
	int totalUnits = 0;
	//Temporary pointer to traverse through the linked-list queue
	Node* tempFront = getAssQ()->getFront();

	for (int i = 0; i < getAssQ()->getCount(); i++){
		totalUnits = totalUnits + tempFront->pkg.units;
		tempFront = tempFront->next;
	}

	return totalUnits;

}
