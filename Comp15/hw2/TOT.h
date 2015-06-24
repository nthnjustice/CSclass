#ifndef TOT_H
#define TOT_H
#include <iostream>
#include "Transcript.h"
using namespace std;

//Initial size of dynamic array
const int INIT_SIZE = 5;
//Factor to increase the size of array, doubled every expand
const int RESIZE_FACTOR = 2;

class TOT
{
	public:
		//Creates a dynamic array of size INIT_SIZE, sets pointers to NULL	
		TOT();
		//Takes in a dynamic array of Transcripts, calls an addTranscript function
		TOT(Transcript* transcriptList, int listSize);
		//Returns a pointer to a copy of student's transcripts
		Transcript* getTranscriptCopy(string studentID);
		//Function adds a single Transcript to the system, returns true if works
		bool addTranscript(Transcript* t);
		
		
		
	private:
		//Dynamic array of pointers to Transcripts
		Transcript** transcripts;
		//Function that searches through the dynamic array of pointers and returns
		// a pointer to the transcript with the corresponding ID
		Transcript* lookUp(string sID);
		//Expands dyanmic array when it is full
		void expand();
		//Count of how many Transcripts are currently stored
		int currentCount;
		//Capacity of the dynamic array
		int currentCapacity;
};

#endif
