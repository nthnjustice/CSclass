/*
 * main.cpp -- test the Sequence implementations
 *
 * IMPORTANT: This file is generic and will be converted into two versions
 *  one version called mainL.cpp and one called mainA.cpp
 *
 *  Those two can be compiled with the specific header files
 *  and then linked with the implementation files
 *
 *  The conversion is simple, use SequenceX for sequenceA or sequenceX 
 *  ==== do not delete this line
 */

#include <iostream>
#include "sequenceX.h"	
#define SEQUENCE_CLASS SequencA
//#define SEQUENCE_CLASS SequencL

using namespace std;

/* 
    Purpose: Test to see if we can print a single character. 
    Utilizes overloaded constructor.
    Pre-condition:
    Post-condition:
*/
void printTest1()
{
	cout << "test print for 1-item list" << endl;   // state purpose

	SequenceX s('a');				// make a sequence
	cout << "Expected: a returned: "; 		// what we want
	s.print();					// what we get
	cout << endl;
}

/* 
    Purpose: Test to see if we can concatenate with another 
	sequence N number of times
    Pre-condition:
    Post-condition:
*/
void expandTest1(int elements)
{
	cout << "test expand(concat another sequence n times" << endl;

	SequenceX* seq1 = new SequenceX('a');		// make a sequence
	SequenceX* seq2 = new SequenceX('b');		// and another

	for(int i = 0; i < elements; i++){		// add 'em on
		seq1->concatenate(seq2);
	}

	// report results
	cout << "expected: a followed by " << elements << " b's returned: "; 
	seq1->print();

	cout << endl;
}

void defaultConstructorTest()
{
    SequenceX* seqTemp = new SequenceX(); 
    cout << "First: " << seqTemp->first() << endl;
    cout << "Rest: " << seqTemp->rest() << endl;
}

void overloadConstructorTest()
{
  SequenceX* seqTemp = new SequenceX('a');
  cout << "First: " << seqTemp->first() << endl;
  cout << "Rest: " << seqTemp->rest() << endl;
}

void isEmptyTest()
{
 SequenceX* seqTemp = new SequenceX();
 SequenceX* seqTemp2 = new SequenceX('a');
 cout << "Empty sequence: " << seqTemp->isEmpty() << endl;
 cout << "Non-empty sequence: " << seqTemp2->isEmpty() << endl;
}

void printTest2()
{
  SequenceX* seqTemp = new SequenceX('a');
  SequenceX* seqTemp2 = new SequenceX('b');
  
  seqTemp->concatenate(seqTemp2);
  
  cout << "Print non-empty sequence: ";
  seqTemp->print();
  cout << endl;
  
}

void sizeTest()
{
  SequenceX* seqTemp = new SequenceX();
  SequenceX* seqTemp2 = new SequenceX('a');
  SequenceX* seqTemp3 = new SequenceX('b');
  seqTemp3->concatenate(seqTemp2);
  
  cout << "Size of empty: " << seqTemp->size() << endl;
  cout << "Size of one: " << seqTemp2->size() << endl;
  cout << "Size of more than two: " << seqTemp3->size() << endl;
}

int main(){

	cout << "==========v Constructor Tests v=======" << endl;
	  defaultConstructorTest();
	  overloadConstructorTest();
	cout << "==========^ Constructor Tests ^=======" << endl << endl;

	cout << "==========v isEmpty Tests v=======" << endl;
	  isEmptyTest();
	cout << "==========^ isEmpty Tests ^=======" << endl << endl;;

	cout << "==========v print() Tests v=======" << endl;
	  printTest1();
	  printTest2();
	cout << "==========^ print() Tests ^=======" << endl << endl;;
			
	cout << "==========v size() Tests v=======" << endl;
	  sizeTest();
	cout << "==========^ size() Tests ^=======" << endl << endl;;
	
	cout << "==========v first() Tests v=======" << endl;
	cout << "==========^ first() Tests ^=======" << endl;
	
	cout << "==========v rest() Tests v=======" << endl << endl;;
	cout << "==========^ rest() Tests ^=======" << endl << endl;

	cout << "==========v concatenate() Tests v=======" << endl;
	cout << "==========^ concatenate() Tests ^=======" << endl << endl;
		
	cout << "==========v expand Testsv=======" << endl;
		expandTest1(1000);
	cout << "==========^ expand Tests^=======" << endl << endl;;
	
	
	return 0;
}

//#endif