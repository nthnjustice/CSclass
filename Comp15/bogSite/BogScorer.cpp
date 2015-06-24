
/*
OK ROLE
OK MOVE
NO LAZY
NO MOVE

The third program is the simplest of the three. This program does not need to read in a dictionary or board. It just
reads in a checker report as shown above. And it prints out each line with a score printed at the left. At the end of
the output, the program will print the number of valid words and the total number of points. Check online for the
scoring rules for boggle. The output for the sample data shown above is:

1 OK ROLE
1 OK MOVE
0 NO LAZY
0 NO MOVE
...
12 words 18 points
*/

#include <iostream>
#include <string>
using namespace std;

struct Node{
	string validity;
	string word;
	int points;
	Node* next;
};

void assignment(string s, Node* iter);
void wordScore(Node* iter);
void output(Node* head);
void finalScore(Node* head);

int main()
{
	string s;
	Node* head = new Node;
	Node* iter = head;
	head->next = NULL;

	while (cin >> s){
		assignment(s, iter);
	}

	output(head);

	return 0;
}

void assignment(string s, Node* iter)
{
	Node* temp = iter;

	while (temp->next != NULL){
		temp = temp->next;
	}

	if ((s == "OK") || (s == "NO")){
		temp->validity = s;
	}
	else{
		temp->word = s;
		wordScore(iter);
	
		temp->next = new Node;
		temp = temp->next;
		temp->next = NULL;
	}
}

void wordScore(Node* iter)
{
	Node* temp = iter;

	while (temp->next != NULL){
		temp = temp->next;
	}

	if (temp->word.length() == 3){
		temp->points = 1;
	}
	if (temp->word.length() == 4){
		temp->points = 1;
	}
	if (temp->word.length() == 5){
		temp->points = 2;
	}
	if (temp->word.length() == 6){
		temp->points = 3;
	}
	if (temp->word.length() == 7){
		temp->points = 5;
	}
	if (temp->word.length() >= 8){
		temp->points = 11;
	}
	if (temp->validity == "NO"){
		temp->points = 0;
	}
}

void output(Node* head)
{
	Node* temp = head;

	while (temp != NULL){
		if (temp->word != ""){
			cout << temp->points << " ";
			cout << temp->validity << " ";
			cout << temp->word << endl;
		}
		temp = temp->next;
	}

	finalScore(head);
} 

void finalScore(Node* head)
{
	Node* temp = head;
	int total = 0;
	int numWords = 0;

	while (temp != NULL){
		if (temp->word != ""){
			total += temp->points;
		}
		if (temp->validity == "OK"){
			numWords++;
		}
		temp = temp->next;
	}

	cout << numWords << " words ";
	cout << total << " points" << endl;
}
