#include <iostream>
#include "Transcript.h"
using namespace std;

/**************************************************************************
PRECONDITION: Constructor, no precondition
POSTCONDITION: Initializes an instance of the class Transcript with empty
	values
**************************************************************************/
Transcript::Transcript()
{
	studentID = "";
	numSemester = 0;
	semList = NULL;
	numTrans = 0;
}

/**************************************************************************
PRECONDITION: Constructor, no precondition
POSTCONDITION: Creates a new instance of the class Transcript with input 
	from main - ID, number of semesters, and a pointer to a list of semesters
**************************************************************************/
Transcript::Transcript(string sID, int numSem, Semester* semL)
{
	studentID = sID;
	numSemester	= numSem;
	semList = new Semester[INIT_SEMESTER];
	if(numSemester > INIT_SEMESTER){
		expandSemester();
	}
	
	for(int i = 0; i < numTrans; i++){
		semList[i] = semL[i];
	}  
	
	numTrans++;
}

/**************************************************************************
PRECONDITION: An instance of the class Transcript exists
POSTCONDITION: The instance of the Class Transcript is destroyed
**************************************************************************/
/*Transcript::~Transcript()
{
	delete [] semList;
}*/

/**************************************************************************
PRECONDITION: There exists an instance of the class Transcript
POSTCONDITION: Takes in a Transcript and makes a copy of itself
**************************************************************************/
Transcript::Transcript(const Transcript &transCopy)
{
	studentID = transCopy.studentID;
	numSemester = transCopy.numSemester;
	semList = new Semester[transCopy.numSemester];
	for(int i = 0; i < transCopy.numSemester; i++){
		semList[i] = transCopy.semList[i];
	}
}

/**************************************************************************
PRECONDITION: There exists an instance of the class Transcript
POSTCONDITION: Takes in a Transcript, makes a copy of itself, and returns a 
	pointer to itself
**************************************************************************/
Transcript& Transcript::operator=(const Transcript &transCopy)
{
	if(this != &transCopy){
		studentID = transCopy.studentID;
		numSemester = transCopy.numSemester;
		semList = new Semester[transCopy.numSemester];
		for(int i = 0; i < transCopy.numSemester; i++){
			semList[i] = transCopy.semList[i];
		}
	}
	
	return *this;
}

/**************************************************************************
PRECONDITION: The number of semesters has exceeded the capacity of the 
	array
POSTCONDITION: The capacity of the array of semesters is doubled
**************************************************************************/
void Transcript::expandSemester()
{
	int tempSize = INIT_SEMESTER * RESIZE_FACTOR2;
	Semester* tempArray = new Semester[tempSize];
	
	for(int i = 0; i < INIT_SEMESTER; i++){
		tempArray[i] = semList[i];
	}
	
	semList = tempArray;                 
}

/**************************************************************************
PRECONDITION: The studentID for a Transcript is requested
POSTCONDITION: Gains access to the private member variable and returns it
**************************************************************************/
string Transcript::getID()
{
	return studentID;
}
