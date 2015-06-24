#include <iostream>
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
		~AssemblyLine();

		//Gets the first worker in the dynamic array from private variable
		Worker getWorkers();

		//Helps set the capacity for the dynamic array of workers
		void assignWorkersCapacity_public(int newWorkersCapacity);
		//Gets the worker array capacity from private variable
		int getWorkersCapacity();
		
		//Assigns the number of workers and the worker rates to the dynamic array
		// workers
		void assignmenting(int numWorkers, double* workerRates);

	private:
		//Pointer to the beginning of a dynamic array of workers
		Worker* workers;
		//Size of the dynmic array of workers
		int workersCapacity;

		//Sets the capacity for the dynamic array of workers
		void assignWorkersCapacity_private(int newWorkersCapacity);
};
