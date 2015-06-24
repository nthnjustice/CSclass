/***************************************************
filename: sequenceL.cpp
date: 9/16/2013
description: program that concatenates linked-lists
		sequences
****************************************************/
#include <iostream>
#include "sequenceL.h" 
#include <cstdlib>
using namespace std;

//Default constructor - called when there is no character input
SequenceL::SequenceL()
{
	sequence = NULL;
}

//Constructor called to take input and create a node for storage
SequenceL::SequenceL(ElementType input)
{
	sequence = new Node;
	sequence->data = input; //Input from main
	sequence->next = NULL;
}

//Checks to see if the sequence is currently empty
bool SequenceL::isEmpty()
{
	if(sequence == NULL)
		return true;
	else{
		return false;
	}
} 

//Calculates the size of the current sequence
int SequenceL::size()
{
	Node* temp = sequence;
	seq_size = 0;

	while(temp != NULL){
		seq_size++;
		temp = temp->next;
	}

	return seq_size;
}

//Attaches a sequence from a new instance of the class to the original sequence
void SequenceL::concatenate(SequenceL* nInstance)
{
//Nothing + Nothing = NULL
//Called if nothing is concatenated with nothing, yields nothing
	if((sequence == NULL) && (nInstance->sequence == NULL)){
		return;
	}

//Something + Nothing = Something
//Called if nothing is concatenated with something, yields original something
	if((sequence != NULL) && (nInstance->sequence == NULL)){
		return;
	}	

//Nothing + Something = Something
//Called if something is concatenated with nothing, yields a copy of the new 
//	something
	if((sequence == NULL) && (nInstance->sequence != NULL)){
		conCaseOne(nInstance);
		return;
	}

//Something + Something = Combination
//Called if something is concatenated with something, yields a copy of the 
//	first sequence and the second combined
	if((sequence != NULL) && (nInstance->sequence != NULL)){
		conCaseTwo(nInstance);
		return;
	}
}

//Executes something concatenated with nothing - takes in a new instance of 
//	the class with a new sequence
void SequenceL::conCaseOne(SequenceL* nInstance)
{
	Node* iter_temp = nInstance->sequence;
	Node* copy = new Node;
	Node* copy_iter = copy;

	while(iter_temp != NULL){
	  copy_iter->data = iter_temp->data; //Creates a copy of the sequence
	  iter_temp = iter_temp->next;
	  if(iter_temp != NULL){ //Continues until the sequence has ended
	    copy_iter->next = new Node;
       	    copy_iter = copy_iter->next; 
	  }
	}
	sequence = copy; //Points the sequence to the copy - concatenation

        return;
}

//Executes something concatenated with something - takes in a new instance of
// the class with a new sequence
void SequenceL::conCaseTwo(SequenceL* nInstance)
{
	Node* temp = sequence;
	Node* iter_temp = nInstance->sequence;
	Node* copy = new Node;
	Node* copy_iter = copy;

	while(temp->next != NULL){
		temp = temp->next; //Moves to the end of the sequence
	}
	while(iter_temp != NULL){
		copy_iter->data = iter_temp->data; //Creates a copy of the sequene
		iter_temp = iter_temp->next;
		if(temp->next != NULL){ //Continues until the sequence has ended
			copy_iter->next = new Node;
			copy_iter = copy_iter->next;
		}
	}
 
	temp->next = copy; //Combines the original and the new sequence
}

//Executes when main asks for the first value of the sequence
ElementType SequenceL::first()
{
	ElementType temp;
	
	temp = sequence->data; //Assigens temp the first value

	return temp; //Returns the first value
}

//Executes when main asks for the sequence, minus the first value
SequenceL* SequenceL::rest()
{
	Node* temp = sequence;
	Node* copy = new Node;
	Node* copy_iter = copy;
	SequenceL* rInstance = new SequenceL; //A new instance of the class

		if(isEmpty()){
		//Error statement
		cerr << "ERROR Calling rest on an empty sequence" << endl; 
		exit(1);
	}

	temp = temp->next; //Skips the first value since it is not needed

	while(temp != NULL){
		copy_iter->data = temp->data; //Creates a copy of the sequence
		if(temp->next != NULL){ //Continues until the sequence ends
			copy_iter->next = new Node;
			copy_iter = copy_iter->next;
		}
			temp = temp->next;
	} 
		
  rInstance->sequence = copy; //The sequence of the new class instance gets the
														// copy that is the rest of the sequence

	return rInstance; //The new intance that has the correct rest-sequence
}

//Prints the data in the linked-list
void SequenceL::print()
{
	Node* temp = sequence;

	while(temp != NULL){
		cout << temp->data << " "; //Prints the value
		temp = temp->next; //Travels through the list
	}

cout << endl;
}
