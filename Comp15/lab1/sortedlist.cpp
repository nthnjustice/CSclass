
#include "sortedlist.h"


SortedList::SortedList()
{
	head = NULL;
    size = 0;
}

SortedList::SortedList(int x, int y, int z)

{
    //BTW --- this function too long
    //should be broken into two pieces
    

	// 6 cases hard coded
	//This is not good code
	//We have two choices,
	
    //We could *not* honor the invariant
	//that the list is ordered, but
	//that is a bad idea.
    
    //We could instead
	//call the insert function from the
	//constructor, but we wanted to have
	//this so you could test your code
	
    //First create the three nodes
    //start with all next pointers
    //set to NULL
    
    Node* nodeX = new Node;
    nodeX->value = x;
    nodeX->next = NULL;
    
    Node* nodeY = new Node;
    nodeY->value = y;
    nodeY->next = NULL;
    
    Node* nodeZ = new Node;
    nodeZ->value = z;
    nodeZ->next = NULL;
    
    //The 6 possible orders are:
	// x, y, z
	// x, z, y
	// y, x, z
	// y, z, x
	// z, x, y
	// z, y, x
	
    //There are other ways to do
    //this, this way is not the sexiest,
    //but it is clear and explicit
    
	if(x <= y && y <= z)
    {
        //x is first so head points
        //to the x node
        head = nodeX;
        
        nodeX->next = nodeY; //y is next after x
        nodeY->next = nodeZ; //z is next after y
        nodeZ->next = NULL;  //not needed but clear, z is last
    }
    
    else if(x <= z && z <= y)
    {
        head = nodeX;
        nodeX->next = nodeZ;
        nodeZ->next = nodeY;
        nodeY->next = NULL;
        
    }
	else if(y <= x && x <= z)
    {
        head = nodeY;
        nodeY->next = nodeX;
        nodeX->next = nodeZ;
        nodeZ->next = NULL;
        
        
    }
    else if(y <= z && z <= x)
    {
        head = nodeY;
        nodeY->next = nodeZ;
        nodeZ->next = nodeX;
        nodeX->next = NULL;
        
    }
    else if(z <= x && x <= y)
    {
        head = nodeZ;
        nodeZ->next = nodeX;
        nodeX->next = nodeY;
        nodeY->next = NULL;
    }
    else // z, y, x
	{
        head = nodeZ;
        nodeZ->next = nodeY;
        nodeY->next = nodeX;
        nodeX->next = NULL;
        
    }
    size = 3;
}

void SortedList::print()
{

    Node* iter;
    
    iter = head;
    
    while(iter != NULL){
      cout << iter->value << " ";
      iter = iter->next;
    }
    
    cout << endl;
}

bool SortedList::isEmpty()
{
	if(head == NULL)
	{
		return true;
	}
	
	else
	{
		return false;

	}
}

int SortedList::getSize()
{
	return size;
}



void SortedList::insert(int v)
{
  Node* temp;
  Node* iter = head;
  temp = new Node;
  temp->value = v;
  temp->next = NULL;
  
  if(isEmpty()){
    head = temp;
  }
	else if(head->value >= v){
		temp->next = head;
		head = temp;
	}
  else{
    while(iter->next != NULL){
      if(iter->next->value >= v){
	temp->next = iter->next;
	iter->next = temp;
	return;
      }	
      iter = iter->next;
    }
	if(iter->next == NULL){
		iter->next = temp;
		temp->next = NULL;
	}
  }
  size++;
    //YOUR CODE HERE
}









