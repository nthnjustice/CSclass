#include "PackQ.h"

/****************************************************************************
Precondition: Constructor - no precondition
Postconition: The front and back pointers of the linked-list queue are set to
	Null and the count for the number of nodes in the linked-list is set to 0
*****************************************************************************/
PackQ::PackQ()
{
	front = NULL;
	back = NULL;
	count = 0;
}

/****************************************************************************
Precondition: Destructor - linked-list
Postconition: Destroys the linked-list that makes up the queue of packages
*****************************************************************************/
PackQ::~PackQ()
{
	//Temporary Node to walk the list
	Node* temp = front;
	
	while(front != NULL){
		//Front goes ahead
		front = front->next;
		//Old front is deleted
		delete temp;
		//Temp follows
		temp = front;
	}
	delete front;
	delete temp;
	delete back;
}

/****************************************************************************
Precondition: There is a linked-list queue
Postconition: Returns true if the linked-list queue is empty and false if 
	there is a package in the linked-list
*****************************************************************************/
bool PackQ::isEmpty()
{
	if(front == NULL){
		return true;
	}
	else{
		return false;
	}
}

/****************************************************************************
Precondition: There is a linked-list queue of packages and information for a
	package is sent in from main
Postconition: A new Node with the new package information is inserted into the
	front of the Queue
*****************************************************************************/
void PackQ::insert(Package pkg_in)
{
	//If the queue is empty a Node is added to the equivalent of the back of the
	//	queue, both front and back point to the single Node
	if(isEmpty()){
		back = new Node;
		back->pkg = pkg_in;
		back->next = NULL;
		front = back;
	}
	//If the queue is not empty, a new Node is added to the back of the queue
	else{
		back->next = new Node;
		back = back->next;
		back->next = NULL;
		back->pkg = pkg_in;
	}

	//The number of Nodes in the lined list is incremented
	count++;
}

/****************************************************************************
Precondition: There is a linked-list queue of packages
Postconition: Removes the first Node in the linked-list queue and decrements
	the count of the Nodes in the linked-list by 1
*****************************************************************************/
void PackQ::remove()
{
	front = front->next;
	count--;
}

/****************************************************************************
Precondition: There is a linked-list queue of packages
Postconition: Pulls a copy of the first Node of the linked-list queue and 
	returns it
*****************************************************************************/
Node* PackQ::getFront()
{
		return front;
}

/****************************************************************************
Precondition: There is a counter for the number of Nodes in the linked-list
	queue in private data
Postconition: Pulls the counter for the number of Nodes in the linked-list
	queue from private to the public domain
*****************************************************************************/
int PackQ::getCount()
{
	return count;
}
