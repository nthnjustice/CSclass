/***************************************************
filename: sequenceA.h
date: 9/16/2013
description: header file for a program that 
		concatenates dynamic array
		sequences
****************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElementType; //Input type

//Class for dynamic array sequence
class SequenceA{
	public:
		SequenceA(); //Default constructor 
		SequenceA(ElementType input); //Input constructor
		bool isEmpty(); //Checks to see if array is empty
		int size(); //Determines size of the array
		void concatenate(SequenceA* nInstance); //Combines sequences
		ElementType first(); //Returns the first value in a sequence
		SequenceA* rest(); //Returns everything but the first value in
				  //a sequence
		void print(); //Prints the sequence
	private: 
		ElementType* p_array; //Start of the dynamic array
		int array_size; //Tracks the number of array elements with data
		int capacity; //Tracks the total capacity of the array
		void expand(); //When the array size reaches capacity, 
			       //capacity is doubled
};
