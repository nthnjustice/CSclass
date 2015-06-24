#include <iostream>
using namespace std;

struct Package{
	string orderNum;
	double units;
	int arrivalTime;
};

struct Node{
	Package pkg;
	Node* next;
};

class PackQ{
	public:
		//Constructor - builds the linked-list queue
		PackQ();
		//Destructor - destroys the linked-list queue
		~PackQ();

		//Checks to see if the queue is empty
		bool isEmpty();
		//Inserts a package to the back of the linked-list queue
		void insert(Package pkg_in);
		//Removes the first package of the linked-list queue
		void remove();

		//Gets the first node from the linked-list queue
		Node* getFront();
		//Gets the number of nodes in the linked-list queue from private variable
		int getCount();

	private:
		//Pointer to the front of the linked-list queue
		Node* front;
		//Pointer to the back of the linked-list queue
		Node* back;
		//Counts the number of nodes in the linked-list queue
		int count;
};
