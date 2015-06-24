#include <iostream>
#include "Semester.h"
using namespace std;

/**************************************************************************
PRECONDITION: Constructor, no precondition
POSTCONDITION: Initializes an instance of the class Semester with empty
	values
**************************************************************************/
Semester::Semester()
{
	season = "";
  year = 0;
	numCourses = 0;
	classes = NULL; 
}

/**************************************************************************
PRECONDITION: Constructor, no precondition
POSTCONDITION: Creates a new instance of the class Semester with input from
	main - term, year, and a pointer to a list of courses
**************************************************************************/
Semester::Semester(string seas, int yr, Node* cList)
{
	season = seas;
	year = yr;
	classes = cList;
	tail = classes;
	numCourses = size(cList);
	
	Node* temp = cList;
	Node* classes = new Node;
	Node* temp2 = classes;

	while(temp != NULL){
		temp2->subject = temp->subject;
		if(temp->next != NULL){
			temp2->next = new Node;
		}
		temp = temp->next;
	}

}

/**************************************************************************
PRECONDITION: An instance of the class Semester exists
POSTCONDITION: The instance of the Class Semester is destroyed
**************************************************************************/
/*Semester::~Semester()
{
	delete classes;
}*/

/**************************************************************************
PRECONDITION: There exists an instance of the class Semester
POSTCONDITION: Takes in a semester and makes a copy of itself
**************************************************************************/
Semester::Semester(const Semester &semCopy)
{
	season = semCopy.season;
	year = semCopy.year;
	classes = semCopy.classes;
	numCourses = semCopy.numCourses;
	classes = semCopy.classes;
}

/**************************************************************************
PRECONDITION: There exists an instance of the class Semester
POSTCONDITION: Takes in a semester, makes a copy of itself, and returns a 
	pointer to itself
**************************************************************************/
Semester& Semester::operator=(const Semester &semCopy)
{
	if(this != &semCopy){
		season = semCopy.season;
		year = semCopy.year;
		classes = semCopy.classes;
		numCourses = semCopy.numCourses;
		classes = semCopy.classes;
	}
	
	return *this;
}

/**************************************************************************
PRECONDITION: There exists a linked-list of courses 
POSTCONDITION: A new course with the Subject data sent in is added to the 
	linked-list of courses
**************************************************************************/
void Semester::addCourse(Subject newCourse)
{
	if(classes == NULL){
		classes = new Node;
		classes->subject = newCourse;
		tail = classes;
		classes->next = NULL;
		return;
	}
	tail->next = new Node;
	tail = tail->next;
	tail->subject = newCourse;
	tail->next = NULL;
}

/**************************************************************************
PRECONDITION: There exists a linked-list of courses
POSTCONDITION: Returns the number of courses present in the linked-list
**************************************************************************/
int Semester::size(Node* cList)
{
	if(cList == NULL){
		return 0;
	}
	
	return 1 + size(cList->next);
	
}
