#include "dispatcher.h"

/*****************************************************************************
Precondition: No relevant precondition
Postcondition: This implementation of dispatcher checks each assemblyLine to 
	determine which has the least number of packages in its queue, a number
	for that particular assembly-line is then returned
******************************************************************************/
int checkLines_PACKAGES(AssemblyLine* assemblyLines, int assemblyLinesCapacity)
{
	//Temporary storage for a reference to the assembly-line with the least 
	//	number of packages in its queue
	int temp = 0;

	//Checks to see if all assembly-line queues are empty
	if(allEmpty(assemblyLines, assemblyLinesCapacity)){
		//Sets and returns a reference to the first assembly-line
		temp = 0;
		return temp;
	}

	for (int i = 0; i < assemblyLinesCapacity; i++){
		//Checks the number of packages in each assembly-line queue and assigns
		//	temp to that value
		if (assemblyLines[i].getAssQ()->getCount() < assemblyLines[temp]
				.getAssQ()->getCount()){
			temp = i;
		}
	}

	//Returns the assembly-line with the least number of packages in its queue
	return temp;
}

int checkLines_UNITS(AssemblyLine* assemblyLines, int assemblyLinesCapacity)
{
	//Temporary storage for a reference to the assembly-line with the least 
	//	number of packages in its queue
	int temp = 0;
	//Starts temp to the number of units in the first assembly-line
	double temp2 = assemblyLines[0].numUnitsInQueue();
	
	//Checks to see if all assembly-line queues are empty
	if (allEmpty(assemblyLines, assemblyLinesCapacity)){
		//Sets and returns a reference to the first assembly-line
		temp = 0;
		return temp;
	}

	for (int i = 0; i < assemblyLinesCapacity; i++){
		if (assemblyLines[i].numUnitsInQueue() <= temp2){
			temp2 = assemblyLines[i].numUnitsInQueue();
			temp = i;
		}
	}

	//Returns the assembly-line with the least number of packages in its queue
	return temp;
}

int checkLines_tUnitsOverRate(AssemblyLine* assemblyLines, int assemblyLinesCapacity)
{
	//Temporary storage for a reference to the assembly-line with the least 
	//	number of packages in its queue
	int temp = 0;
	//Starts temp to the number of units in the first assembly-line
	double temp2 = assemblyLines[0].numUnitsInQueue() / assemblyLines[0]
															.worker.packRate;

	//Checks to see if all assembly-line queues are empty
	if (allEmpty(assemblyLines, assemblyLinesCapacity)){
		//Sets and returns a reference to the first assembly-line
		temp = 0;
		return temp;
	}

	for (int i = 0; i < assemblyLinesCapacity; i++){
		if (assemblyLines[i].numUnitsInQueue() / assemblyLines[i]
													.worker.packRate <= temp2){
			temp2 = assemblyLines[i].numUnitsInQueue();
			temp = i;
		}
	}

	//Returns the assembly-line with the least number of packages in its queue
	return temp;
}


/*****************************************************************************
Precondition: Each assembly-line has a queue
Postcondition: Returns true if all assembly-line queues are empty, else returns
false
******************************************************************************/
bool allEmpty(AssemblyLine* assemblyLines, int assemblyLinesCapacity)
{
	//Temporary variable to hold if assembly-line queue is empty
	bool hold = true;

	for (int i = 0; i < assemblyLinesCapacity; i++){
		if (!assemblyLines[i].getAssQ()->isEmpty()){
			//False if the assembly-line queue is not empty
			hold = false;
		}
	}

	//Returns whether or not all assembly-line queues are empty
	return hold;
}
