#include <iostream>
#include "TOT.h"
using namespace std;

/**************************************************************************
PRECONDITION: Constructor, no precondition
POSTCONDITION: Initializes an instance of the class TOT with empty
	values, including a new array of pointers to Transcripts
**************************************************************************/
TOT::TOT()
{
	//Builds an array of pointers to transcripts
	transcripts = new Transcript* [INIT_SIZE]; 
	
	//Initializes the array to NULL
	for(int i = 0; i < INIT_SIZE; i++){
		transcripts[i] = NULL;
	}
	
	currentCapacity = INIT_SIZE;
	currentCount = 0;
}

/**************************************************************************
PRECONDITION: Constructor, no precondition
POSTCONDITION: Creates a new instance of the class TOT with input 
	from main - a pointer to an array of pointers to Transcripts, the number 
	of Transcrips in the dynamic array
**************************************************************************/
TOT::TOT(Transcript* transcriptList, int listSize)
{
	//Builds an array of pointers to transcripts
	transcripts = new Transcript* [listSize];
	
	//Temporary pointer to a transcript
	Transcript* transToAdd;
	
	currentCapacity = INIT_SIZE;
	currentCount = 0;
	
	for(int i = 0; i < listSize; i++){
		//Catches the input from main
		 transToAdd = &transcriptList[i];
		//Adds the caught transcript to the array
		 if(addTranscript(transToAdd)){
		 		currentCount++;
		 	}
	}
}

/**************************************************************************
PRECONDITION: There exists a pointer to a dynamic array of pointers to 
	Transcripts
POSTCONDITION: A pointer to the transcript for the studentID that is sent
	into the function 
**************************************************************************/	
Transcript* TOT::getTranscriptCopy(string studentID)
{
	Transcript* transCopy;
	
	//Creats a copy of the requested transcript
	 transCopy = lookUp(studentID);
	 
	 return transCopy;
}

/**************************************************************************
PRECONDITION: There exists a pointer to a dynamic array of pointers to 
	Transcripts
POSTCONDITION: Adds a new pointer to a new Transcript to the dynamic array
	of pointers and returns true when completed;
**************************************************************************/	
bool TOT::addTranscript(Transcript* t)
{
	while(currentCount >= currentCapacity){
		expand();
	}
	
	transcripts[currentCount] = t;
	currentCount++;
	
	return true;
}

/**************************************************************************
PRECONDITION: The dynamic array of pointers to Transcripts has reached its
	array capacity
POSTCONDITION: The size of the dynamic array of pointers to Transcripts is
	doubled
**************************************************************************/	
void TOT::expand()
{
	//Doubles currentCapactiy of the array
	currentCapacity = currentCapacity * RESIZE_FACTOR;
	
	//Builds a new array of pointers with the new currentCapacity
	Transcript** temp = new Transcript*[currentCapacity];
	
	//Fills the temp with old data
	for(int i = 0; i < currentCount; i++){
		temp[i] = transcripts[i];
	}
	
	//Deletes old array of pointers
	delete [] transcripts;
	
	//Reassigns data from old array of pointers to new array
	transcripts = temp;
}

/**************************************************************************
PRECONDITION: There exists a pointer to a dynamic array of pointers to 
	Transcripts
POSTCONDITION: A pointer to the transcript for the studentID that is sent
	into the function 
**************************************************************************/
Transcript* TOT::lookUp(string sID)
{
	//Searches the array for the correct transcript
	for(int i = 0; i < currentCount; i++){
		if(transcripts[i]->getID() == sID){
			return transcripts[i];
		}
	}
	
	cout << "ERROR: Student ID doesn't exist" << endl;
	return NULL;
}


