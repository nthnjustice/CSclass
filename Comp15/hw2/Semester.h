#include <iostream>
using namespace std;

//Represents a class a student enrolls in, contains data values for the
//	course ID and the grade received
struct Subject{
	string courseID;
	string grade;
};

//Node that holds a struct that represents a class a student enrolls in, also
//	contains a pointer to another Node to build a linked-list
struct Node{
	Subject subject;
	Node* next;
};

class Semester
{
	public:
		//Initializes a Semester with empty values
		Semester();
		//Builds a Semester with term and year information, and a pointer
		//	to a new Node that has data for the class a student enrolls in
		Semester(string seas, int yr, Node* cList);
		//Destroys the linked-list of classes
		//~Semester();
		//Takes in a semester and makes a copy of itself
		Semester(const Semester &semCopy);
		//Takes in a semester, makes a copy of itself, and returns a 
		//	pointer to itself
		Semester& operator=(const Semester &semCopy);
		//Adds a new class a student enrolls in to the linked-list of classes
		//	for that semester
		void addCourse(Subject newCourse);
		//Calculates the number of nodes in a linked-list of classes
		int size(Node* cList);
		
	private:
		//Term for the Semester
		string season;
		//Year for the Semester
		int year;
		//Number of courses in the Semester 
		int numCourses;
		//A pointer to a linked-list of classes
		Node* classes;
		//A pointer to the end of the linked-list of classes
		Node* tail;
};
	
