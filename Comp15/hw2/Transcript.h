#include <iostream>
#include "Semester.h"
using namespace std;

//Initial size of dynamic array
const int INIT_SEMESTER = 14;
//Factor to increase the size of array, doubled every expand
const int RESIZE_FACTOR2 = 2;

class Transcript
{
	public:
		//Creates a dynamic array of size INIT_SEMESTER, sets pointers to NULL
		Transcript();
		//Takes in a new Transcript and adds it to the array, can expand array
		//	if necessary
		Transcript(string sID, int numSem, Semester* semL);
		//Destroys the array of Semesters
		//~Transcript();
		//Takes in a Transcript and makes a copy of itself
		Transcript(const Transcript &transCopy);
		//Takes in a Transcript, makes a copy of itself, and returns a 
		//	pointer to itself
		Transcript& operator=(const Transcript &transCopy);
		//Doubles the capacity of the array that holds Semesters
		void expandSemester();
		//Gains access to the private member variable and returns it
		string getID();
	
		
		
	private:
		//ID for the Transcript
		string studentID;
		//Number of Semesters on the Transcript
		int numSemester;
		//Number of Transcripts
		int numTrans;
		//Start of the dynamic array of Semesters
		Semester* semList;
		
};
