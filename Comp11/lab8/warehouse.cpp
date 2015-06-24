#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
//
// implementation of an Warehouse class
//

#include "warehouse.h"

//
// A constructor that initializes all quantities to zero
//
Warehouse::Warehouse()
{
	// your code here
	for(int i = 0; i < NUM_PRODUCTS; i++){
	    counts[i] = 0;
	}
}

//
// A constructor that initializes all quantities to the specified amt
//
Warehouse::Warehouse(int init_qty)
{
	// your code here
	for(int i = 0; i < NUM_PRODUCTS; i++){
	    counts[i] = init_qty;
	}

}

// Two restock methods, the first adds 'additional'
// units for all products
void Warehouse::restock(int additional)
{
	// your code here
	for(int i = 0; i < NUM_PRODUCTS; i++){
	    counts[i] = counts[i] + additional;
	}
}
// A restock for a particular product
// this restock method adds an amount to a
// particular product.
void Warehouse::restock(int product, int additional)
{
	// your code here
	for(int i = 0; i < NUM_PRODUCTS; i++){
	    if(counts[i] == product){
		counts[i] = counts[i] + additional;
	    }
	}
	
}

// Check if a particular product is in stock
bool Warehouse::is_instock(int product)
{
	// your code here
	if(counts[product] > 0){
	    return true;
	}

	    return false;
}

// ask how many are on hand
int Warehouse::on_hand(int product)
{
	// your code here
	
}

//
// sell some amt of some product, return a bool if enough for sale
//
bool Warehouse::remove(int product, int amt)
{
	// your code here
}

//
// returns the maximum valid product id
//
int Warehouse::maxid()
{
	return NUM_PRODUCTS - 1;
}
//
// Which products need to be restocked?
// Pass in a restock level,
// the function fills in a bool array where
// true in position 0 => product 0 is below that level
// true in position 1 => product 1 is below that level
// ...
// return value is number of products that need restock
int Warehouse::need_restock(int minimum, bool isLow[])
{
	// your code here
}

//
// used internally - determine if the arg is a valid product id
//
bool valid_id(int product)
{
	// your code here
}

