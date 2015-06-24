/***************************************************
filename: sequenceL.h
date: 9/16/2013
description: header file for a program that 
	     concatenates linked-lists
	     sequences
****************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElementType; //The input type

//Node type used in the linked-list
struct Node{
	ElementType data;
	Node* next;
};

//Class for linked-list sequences
class SequenceL{
	public:	
		SequenceL(); //Default constructor
		SequenceL(ElementType input); //Input constructor
		bool isEmpty(); //Checks to see if list is empty
		int size(); //Determines size of linked-list 
		void concatenate(SequenceL* nInstance); //Combines sequences
		ElementType first(); //Returns the first value in a sequence
		SequenceL* rest(); //Returns everything but the first value in a
				 //  sequence
		void print(); //Prints the sequence
	private:
		Node* sequence; //The head of the sequence
		int seq_size; //The size of the sequence
		void conCaseOne(SequenceL* nInstance); //Special concatenate case
		void conCaseTwo(SequenceL* nInstance); //Special concatenate case
	
};


