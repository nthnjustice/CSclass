/* sandwichList.cpp
 * Comp 15 
 * Spring 2013 
 * Lab 3
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];

	back = 0;
	front = 1;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
	return (back - front + capacity) % capacity;
}

//function to pop
Order SandwichList::getNext()
{
	Order temp;		

	/*if(isEmpty()){
		cerr << "There is nobody here." << endl;
		exit(1);
	}*/
	
	temp = orders[front];

	front++;
	front = front % capacity; 

	
	return temp;
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::add(const Order& sw)
{
	Order temp = sw;
	
	if(front == back){
		expandList();
	}

	orders[back] = temp;
	back++;
	back = back % capacity;
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
	Order* temp = new Order[capacity * 2];

	temp = orders;	
	
	front = front % capacity;
	back = back % capacity;
	
}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



