#include "AssemblyLine.h"

/****************************************************************************
Precondition: Constructor - no precondition
Postconition: Sets the capacity of the dynamic array of workers to 1, it is
	specifically defined in this implementation because this program only 
	handles 1 worker
*****************************************************************************/
AssemblyLine::AssemblyLine()
{
	workersCapacity = 1;
	workers = NULL;
}

/****************************************************************************
Precondition: Destructor - dynamic array of workers
Postconition: Destroys the dynamic array of workers
*****************************************************************************/
AssemblyLine::~AssemblyLine()
{
	delete [] workers;
}

/****************************************************************************
Precondition: There is a dynamic array of workers in private data
Postconition: Pulls the first worker from the dynmic array of workers from 
	private data to public domain and returns it
*****************************************************************************/
Worker AssemblyLine::getWorkers()
{
	Worker temp = workers[0];
	return temp;
}

/****************************************************************************
Precondition: The capacity for the dynamic array of workers is sent in from 
	main
Postconition: Helper function that sends to a private function the capacity
	for the dynamic array of workers sent in from main
*****************************************************************************/
void AssemblyLine::assignWorkersCapacity_public(int newWorkersCapacity)
{
	assignWorkersCapacity_private(newWorkersCapacity);
}

/****************************************************************************
Precondition: The capacity for the dynamic array of workers is sent in from 
	main and handed down from a public function
Postconition: The capacity of the dynamic array of workers is set
*****************************************************************************/
void AssemblyLine::assignWorkersCapacity_private(int newWorkersCapacity)
{
	workersCapacity = newWorkersCapacity;

	workers = new Worker [workersCapacity];
}

/****************************************************************************
Precondition: There is a capacity for the dynamic array of workers in private
	data
Postconition: The capacity for the dynamic array of workers is pulled from 
	private to the public domain
*****************************************************************************/
int AssemblyLine::getWorkersCapacity()
{
	int temp = workersCapacity;

	return temp;
}

/***************************************************************************
Precondition: Takes in the number of workers and their respective rates
	for the simulation from main
Postcondition: Sets the size of the dynmic array of workers to the correct
	size and assigns the respective worker rates
***************************************************************************/
void AssemblyLine::assignmenting(int numWorkers, double* workerRates)
{
	assignWorkersCapacity_public(numWorkers);
	workers->packRate = workerRates[0];
}
