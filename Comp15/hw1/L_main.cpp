#include <iostream>
#include "sequenceL.h"
using namespace std;

int main()
{
	SequenceL* s4;	

	SequenceL s1;
	s1.print();
	SequenceL s2('a');
	s2.print();
	SequenceL s3('b');
	s3.print();
	s2.concatenate(&s3);
	s2.print();
	cout << "Here comes rest" << endl;
	s4 = s2.rest();
	s4->print();
	cout << "Here comes first" << endl;
	char tempa = s2.first();
	cout << tempa << endl; 
	return 0;
}
