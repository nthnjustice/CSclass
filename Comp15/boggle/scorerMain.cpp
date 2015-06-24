#include "BogScorer.h"

int main()
{
	BogScorer scorer;

	string s;
	//builds the head of the linked-list
	Node* head = new Node;
	//used to traverse the linked-list
	Node* iter = head;
	//initializes the linked-list to NULL
	head->next = NULL;

	//reads in a list of words and their validity
	while (cin >> s){
		scorer.assignment(s, iter);
	}
	
	//print function
	scorer.output(head);

	return 0;
}
