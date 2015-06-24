#include <iostream>
#include "TOT.h"
using namespace std;

int main()
{
	//Two classes
	Node* comp15 = new Node;
	Node* comp20 = new Node;
	
	//Information for the classes
	Subject comp15S;
	Subject comp20S;
	comp15S.courseID = "COMP15";
	comp20S.courseID = "COMP20";
	comp15S.grade = "A+";
	comp20S.grade = "B+";
	comp15->subject = comp15S;
	comp20->subject = comp20S;
	
	//Building a semester
	Semester s1("Fall", 2013, comp15);
	cout << s1.classes->subject.courseID << endl;
	cout << s1.classes->subject.grade << endl;
	s1.addCourse(comp20S);

	//temp for printing purposes
	Node* temp = s1.classes;

	//Print showing the functionality of the linked-list
	while(temp != NULL){
		cout << temp->subject.courseID << endl;
		cout << temp->subject.grade << endl;
		temp = temp->next;
		if(temp == NULL)
			cout << "Temp is NULL, end of list" << endl;
	}
	
	//Demontrates the functionality of size()
	cout << "SIZE: " << s1.size(s1.classes) << endl;

	//Building a third class
	Subject comp40S;
	comp40S.courseID = "COMP40";
	comp40S.grade = "C+";
	s1.addCourse(comp40S);
	
	//Demonstrates the functionality of addCourse()
	temp = s1.classes;
	while(temp != NULL){
		cout << temp->subject.courseID << endl;
		cout << temp->subject.grade << endl;
		temp = temp->next;
		if(temp == NULL)
			cout << "Temp is NULL" << endl;
	}
	
	//Demonstrates the functionlity of size() again
	cout << "SIZE: " << s1.size(s1.classes) << endl;
	
	//Starts a new linked-list with a new class 
	Node* comp10 = new Node;
	Subject comp10S;
	comp10S.courseID = "COMP10";
	comp10S.grade = "A+";
	comp10->subject = comp10S;
	
	//Builds another semester with a new linked-list
	Semester s2("Spring", 2013, comp10);
	
	//Demonstrates the successful build of another semester
	Node* temp2 = s2.classes;
	while(temp2 != NULL){
		cout << temp2->subject.courseID << endl;
		cout << temp2->subject.grade << endl;
		temp2 = temp2->next;
	}
	
	//Builds two Transcripts with the two semesters 
	Transcript t1("007", 2, &s1);
	Transcript t2("008", 3, &s2);
	
	//Builds a new TOT and adds the two transcripts
	TOT* DaTOT = new TOT [INIT_SIZE];
	DaTOT->addTranscript(&t1);
	DaTOT->addTranscript(&t2);
	
	//Calls the lookUp() of TOT
	Transcript* looky;
	looky = DaTOT->lookUp("007");
	cout << looky->semList->classes->subject.courseID << endl;
}
