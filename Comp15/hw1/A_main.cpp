#include <iostream>
#include <cstdlib>
#include "sequenceA.h"

int main()
{
	SequenceA* s5;
	SequenceA s1;
	s1.print();
	SequenceA s2('a');
	s2.print();
	SequenceA s3('b');
	s3.print();
	s2.concatenate(&s3);
	s2.print();
	SequenceA s4('c');
	s2.concatenate(&s4);
	s2.print();
	cout << "Here comes rest" << endl;
	s5 = s2.rest();
	s5->print();
	cout << "Here comes first" << endl;
	char j = s2.first();
	cout << j << endl;
	return 0;
}
