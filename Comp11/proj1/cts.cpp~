/*****************************************************************************
name: cts.cpp
purpose: "ticket-master", manages an auditorium based on specific input
usage: ./cts
input: command, customer ID, number of seats desired, location, and ticket 
    price preference
output: confirmation or rejection of order, price of order and identification
    of seats reserved, seating chart, revenue of venue,
    venue, 
note: User is able to make reservations, cancel reservations, print the 
    seating chart, and end the program. User can't make two reservations
    with the same name. User can't request less than 1 nor more than 12
    tickets. If reservation executes successfully, program prints a
    confirmation, the total price of the order, and the seats reserved. 
    When printing the seating chart, program prints total revenue for the
    venue. User can choose premium, general, or any seating. When the user 
    requests any seating, program seats in premium before general. If the 
    user's number of seats requested exceeds the number of seats available
    together in one row, the function splits the party and rewards a 10%
    price deduction for the total price of the tickets. 
by: Nathan Justice
modified: 3/12/13
*****************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int rows = 14;
const int cols = 20;
const double premium_price = 200.0;
const double general_price = 150.0;
const double deduction = .1;

void initializer(string seating[rows][cols],double pricing[rows][cols]);
void command(string seating[rows][cols],double pricing[rows][cols]);
void print_array(string seating[rows][cols],double pricing[rows][cols]);
void rejection(string custID);
void request_seat(string seating[rows][cols],double pricing[rows][cols]);
void cancel_seat(string seating[rows][cols],double pricing[rows][cols]);
void check_seating(string seating[rows][cols],double pricing[rows][cols],
        string price,int num_seat,string custID);
void fill_split_any(string seating[rows][cols],int num_seat,string custID,
        double pricing[rows][cols]);
void fill_seating(string seating[rows][cols],string custID,int num_seat,
       int row_num,int col_num,double pricing[rows][cols],double ticket_price);
void any_seating(string seating[rows][cols],string cust_ID,int num_seat,
        double pricing[rows][cols],string price);
int split_seating(string seating[rows][cols],string custID,int num_seat,
        string price,double pricing[rows][cols]);
void printing_split_confirmation(string custID,string seating[rows][cols],
        double pricing[rows][cols], int num_seat);

double revenue(double pricing[rows][cols]);

int search_hi_seating(string seating[rows][cols],string custID,int num_seat,
        double pricing[rows][cols],string price);
int search_lo_seating(string seating[rows][cols],string custID,int num_seat,
        double pricing[rows][cols],string price);
int check_split_hi(string seating[rows][cols],int num_seat,string custID,
        string price);
int fill_split_hi(string seating[rows][cols],int num_seat,string custID,
        double pricing[rows][cols]);
int check_split_all(string seating[rows][cols],int num_seat,string custID);
int fill_split_lo_left(string seating[rows][cols],int num_seat,string custID,
        double pricing[rows][cols]);
int fill_split_lo_right(string seating[rows][cols],int remaining_seats,
        string custID,double pricing[rows][cols]);
int fill_split_lo_bottom(string seating[rows][cols],int remaining_seats_two,
        string custID,double pricing[rows][cols]);
int check_split_any(string seating[rows][cols],int num_seat,string custID);

bool already_reserved(string seating[rows][cols],string custID);
bool bad_number(int num_seat,string custID);
bool occupied_hi_seating(string seating[rows][cols],int num_seat,int row_num,
        int col_num);
bool occupied_lo_seating_left(string seating[rows][cols],int num_seat,
        int row_num,int col_num);
bool occupied_lo_seating_right(string seating[rows][cols],int num_seat,
        int row_num,int col_num);
bool occupied_lo_seating_bottom(string seating[rows][cols],int num_seat,
        int row_num,int col_num);

/******************************************************************************
purpose: declares the seating and pricing charts thta are used
    throughout the entire program; also calls the initializer and command 
    functions
input: n/a
returns: declares seating and pricing arrays, returns 0
******************************************************************************/
int main()
{
    string seating[rows][cols];
    double pricing[rows][cols];
	
    initializer(seating, pricing);
    command(seating, pricing);
    	
    return 0;
}

/******************************************************************************
purpose: initializes the seating chart by setting the array elements
    to empty strings; initializes the pricing chart by setting the array
    elements to 0.0
input: seating array and pricing array
returns: void; modifies seating and pricing arrays
******************************************************************************/
void initializer(string seating[rows][cols],double pricing[rows][cols])
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            seating[i][j] = "---"; //all of seating chart gets empty string
            pricing[i][j] = 0.0; //all of pricing chart gets value 0.00
	}
    }
}

/******************************************************************************
purpose: takes in the desired command from the user; calls the functions
    that corresponds to the inputted command
input: seating and pricing array, desired command from the user
returns: n/a
******************************************************************************/
void command(string seating[rows][cols],double pricing[rows][cols])
{
    string com;
	
    do{
        cin >> com;
		
        if(com == "PR"){
            print_array(seating, pricing);
	}
	else if(com == "RQ"){
            request_seat(seating, pricing);
	}
	else if(com == "CA"){
            cancel_seat(seating, pricing);
	}
	}while(com != "QU"); //command repeats until user inputs "QU" to exit
}

/******************************************************************************
purpose: prints the running seating chart; also prints the running calculated
    revenue
input: seating and pricing array
returns: n/a
******************************************************************************/
void print_array(string seating[rows][cols],double pricing[rows][cols])
{

    cout << fixed << showpoint << setprecision(2); //sets decimal points
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << seating[i][j] << " ";	
	}
        cout << endl;
    }
	
    cout << "Revenue: " << revenue(pricing) << endl;
    cout << fixed << noshowpoint << setprecision(0); //sets decimal points
}

/******************************************************************************
purpose: calculates the running total revenue from the pricing array; 
input: pricing array
returns: the current total revenue
******************************************************************************/
double revenue(double pricing[rows][cols])
{
    double rev = 0.0;
	
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            rev = rev + pricing[i][j]; //adds up total presen in entire array
	}
    }
	
    return rev;
}

/******************************************************************************
purpose: error message that alerts the user that the inputted customer ID
    has already been used; a single customer ID can only be used once
input: seating array and customer ID
returns: false if the customer ID has already been used and the program
    ignores the command; true if the customer ID is novel and the program 
    continues with the command
******************************************************************************/
bool already_reserved(string seating[rows][cols],string custID)
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(custID == seating[i][j]){
                cout << "NO" << " " << custID << " " 
                    << "already-reserved" << endl;
            return false;
            }
        }
    }

    return true;
}

/******************************************************************************
purpose: checks to see if the number of tickets requested by the user is
    greater than or equal to 1 and less than or equal to 12; program only
    approves number of tickets that lie in that range
input: number of seats and the customer ID
returns: false if the number of tickets is invalid; true if the number of 
    tickets is approved and the program continues with the command
******************************************************************************/
bool bad_number(int num_seat,string custID)
{
    int min_num_seat = 1;
    int max_num_seat = 12;
	
    if((num_seat < min_num_seat) || (num_seat > max_num_seat)){
        cout << "NO" << " " << custID << " " << "bad-number" << endl;
		
        return false;
    }
	
    return true;
}

/******************************************************************************
purpose: warns the user that their desired seat request could not be processed
    because there are not enough available seats in the venue
input:  customer ID
returns: n/a
******************************************************************************/
void rejection(string custID)
{
    cout << "NO " << custID << " not-available" << endl;
}

/******************************************************************************
purpose: takes in the customer ID, the number of tickets, and the ticket-price
    from the user; calles the functions that check if customer ID has already 
    been used or if the number of tickets is a bad number; call sthe function
    that leads the checking for availability of seats
input: seating and pricing arrays, customer ID from the user, number of 
    seats from the user, desired ticket-price from the user
returns: n/a
******************************************************************************/
void request_seat(string seating[rows][cols],double pricing[rows][cols])
{
    string custID = " ";
    int num_seat = 0;
    string price = " ";
	
    cin >> custID;
    while(custID.size() < 3){ //maintains a 3 character maximum to the customer 
        custID += " ";           //to maintain an organized seating chart
    }

    cin >> num_seat;
    cin >> price;
	
    if((already_reserved(seating,custID)) && (bad_number(num_seat,custID))){
        check_seating(seating, pricing, price, num_seat, custID);
    }
}	

/******************************************************************************
purpose: cancells a previously made request and removes the alterations to the
    seating and pricing arrays
input: seating and pricing arrays, customer ID from the user
returns:void; alters the seating and pricing arrays
******************************************************************************/
void cancel_seat(string seating[rows][cols],double pricing[rows][cols])
{
    string custID;
    int counter = 0;
	
    cin >> custID;
    while(custID.size() < 3){
        custID += " ";
    }
	
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(seating[i][j] == custID){
		seating[i][j] = "---"; //sets seat back to empty string
		pricing[i][j] = 0.0; //sets seat back to value 0.00
		counter++;
            }
	}
    }
    if(counter != 0){
        cout << "OK " << custID << " cancelled" << endl;
    }
    else{ //if cancellation fails
        cout << "NO " << custID << " no-reservation" << endl; 
    }
}

/******************************************************************************
purpose: breaks down the search function into three seperate and callable 
    functions that correspond the the ticket prices
input: seating and pricing arrays, desired price, number of seats, customer
    ID
returns: void; calls the appropriate search function for the desired ticket
    price
******************************************************************************/
void check_seating(string seating[rows][cols],double pricing[rows][cols],
        string price,int num_seat,string custID)
{
    if(price == "hi"){
        search_hi_seating(seating,custID,num_seat,pricing,price);
    }
    if(price == "lo"){
        search_lo_seating(seating,custID,num_seat,pricing,price);
    }
    if(price == "any"){
        any_seating(seating,custID,num_seat,pricing,price);
    }
}

/******************************************************************************
purpose: searches through the high section of the seating array and call the
     function that checks to see if the particular index is already occupied, 
     if not the function calls another function that seats the customer ID 
     into the proper seats in a continues row; if the number of seats can't
     be seated in a single row, the function call another function that 
     splits of seats
input: seating and pricing arrays, customer ID, number of seats, desired
    ticket-price
returns: returns 0 if the function successfully seats the customer ID in
    the proper number of seats in a single row, also can return 0 if the
    split seating function is called, returns 1 if the function runs 
    unsuccessfully. 
******************************************************************************/
int search_hi_seating(string seating[rows][cols],string custID,int num_seat,
        double pricing[rows][cols],string price)
{
    double ticket_price = premium_price;
	
    for(int row_num = 0; row_num < 8; row_num++){
        for(int col_num = 4; col_num < 16; col_num++){
          //checks for availability and seats accordingly  
            if(occupied_hi_seating(seating,num_seat,row_num,col_num)){
                fill_seating(seating,custID,num_seat,row_num,col_num,pricing,
                    ticket_price);
		return 0;
            }
	}
    }
    //called if seats can't all be put together in 1 row
    if(split_seating(seating,custID,num_seat,price,pricing) == 0)
        return 0;
    return 1;
}

/******************************************************************************
purpose: checks to see if each index in the premium seating is already 
    occupied and therefore unavailable to new customers
input: seating array, number of seats, row and column counters from the 
    search_hi_seating function
returns: false if the index of the array is NOT available and IS occupied,
    returns false if the loops extend past the premium seating boundaries,
    returns true if the checks fail and the index is an empty string and 
    therefore is available
******************************************************************************/
bool occupied_hi_seating(string seating[rows][cols],int num_seat,int row_num,
        int col_num)
{	
    for(int counter = col_num; counter < (num_seat + col_num); counter++){
        if(seating[row_num][counter] != "---"){ //means is occupied
            return false;
	}
	if(counter > 15){
            return false;
	}
    }
	
    return true;
}

/******************************************************************************
purpose: the function defines a left, right, and bottom lo price sections as
    described by the row and column boundaries; the function first searches
    through the left, then right, then bottom low price sections and calls 
    the function that checks to see if seats are available, if seats are
    available, the function then calls another function that seats the 
    customer in the proper number of seats in that section; if the customer 
    cannot be seated in a single continues row, the function that splits
    seating is called
input: seating and pricing arrays, customer ID, number of seats, desired
    ticket-price
returns: 0 if the customer is seated in a continues row for the proper 
    number of seats in any of the three lo sections; returns 1 if the 
    single row seating was unsuccessful and the split seating function is 
    called
******************************************************************************/
int search_lo_seating(string seating[rows][cols],string custID,int num_seat,
        double pricing[rows][cols],string price)
{
    int col_num = 0;
    double ticket_price = general_price;
    for(int row_num = 0; row_num < rows; row_num++){
        for(col_num = 0; col_num < 4; col_num++){
             //checks for availability and seats accordingly  
            if(occupied_lo_seating_left(seating,num_seat,row_num,col_num)){
                fill_seating(seating,custID,num_seat,row_num,col_num,pricing,
                    ticket_price);
		return 0;
	    }
	}
        for(col_num = 16; col_num < cols; col_num++){
             //checks for availability and seats accordingly  
            if(occupied_lo_seating_right(seating,num_seat,row_num,col_num)){
		fill_seating(seating,custID,num_seat,row_num,col_num,pricing,
                    ticket_price);
		return 0;
	    }
	}			
	for(col_num = 0; col_num < cols; col_num++){
	    //checks for availability and seats accordingly  
	   if(occupied_lo_seating_bottom(seating,num_seat,row_num,col_num)){			
		fill_seating(seating,custID,num_seat,row_num,col_num,pricing,
                    ticket_price);
		return 0;
	   }
	}
    }r
    //called if seats can't all be put together in 1 row
    split_seating(seating,custID,num_seat,price,pricing);
    return 1;
}	

/******************************************************************************
purpose: checks to see if each index in the left lo section is already 
    occupied and therefore is unavilable to new customers
input: seating array, number of seats, and row and column counters from the
    search_lo_seating function
return: false if the inex of the array is NOT available and IS occupied,
    false if the for loop from the previous function exceeds the boundaries
    of the low left section, returns true if the checks fail and the index is 
    an empty string and therefore is available
******************************************************************************/
bool occupied_lo_seating_left(string seating[rows][cols],int num_seat,
        int row_num,int col_num)
{	
    if(row_num >= 7){
        return false;
    }

    for(int counter = col_num; counter < (num_seat + col_num); counter++){
        if(seating[row_num][counter] != "---"){
            return false;
	}
	if(counter > 3){
            return false;
	}
    }
	
    return true;
}

/******************************************************************************
purpose: checks to see if each index in the right lo section is already 
    occupied and therefore is unavilable to new customers
input: seating array, number of seats, and row and column counters from the
    search_lo_seating function
return: false if the inex of the array is NOT available and IS occupied,
    false if the for loop from the previous function exceeds the boundaries
    of the low right section, returns true if the checks fail and the index 
    is an empty string and therefore is available
******************************************************************************/
bool occupied_lo_seating_right(string seating[rows][cols],int num_seat,
        int row_num,int col_num)
{
    if(row_num >= 7){
        return false;
    }
	
    for(int counter = col_num; counter < (num_seat + col_num); counter++){
        if(seating[row_num][counter] != "---"){
            return false;
	} 
	if((counter < 16) || (counter > 19)){
            return false;
	}
    }
	
    return true;
}

/******************************************************************************
purpose: checks to see if each index in the bottom lo section is already 
    occupied and therefore is unavilable to new customers
input: seating array, number of seats, and row and column counters from the
    search_lo_seating function
return: false if the inex of the array is NOT available and IS occupied,
    false if the for loop from the previous function exceeds the boundaries
    of the low bottom section, returns true if the checks fail and the index 
    is an empty string and therefore is available
******************************************************************************/
bool occupied_lo_seating_bottom(string seating[rows][cols],int num_seat,
        int row_num,int col_num)
{
    if((row_num > 13) || (row_num < 8)){
        return false;
    }
	
    for(int counter = col_num; counter < (num_seat + col_num); counter++){
        if((counter < 0) || (counter > 19)){
            return false;
	}
	if(seating[row_num][counter] != "---"){ //means is occupied
            return false;
	}
    }

    return true;
}

/******************************************************************************
purpose: seats the customers who select any priced tickets by first trying
    to seat them continuesly in premium seating, then in
    continuesly in general seating,and if both fail the funtion calls the 
    split seating function
input: seating and pricing arrays, customer ID, number of seats, desired
    price
return: n/a
******************************************************************************/
void any_seating(string seating[rows][cols],string custID,int num_seat,
        double pricing[rows][cols],string price)
{
    if(search_hi_seating(seating,custID,num_seat, pricing, price) == 1){
	if(search_lo_seating(seating, custID, num_seat, pricing, price) == 1){
            price = "any2";
             //means that seats can't be placed together in hi
             //calls to split the tickets of 'any' value
            split_seating(seating, custID, num_seat, price, pricing);
	}
    }
}

/******************************************************************************
purpose: if the occupied seating check passes and the number of seats
    requested are located along one another continuesly, this function gets
    called to replace the empty string that represents the seat with the 
    customer ID; also prints a reservation confirmation to the user that
    lets them know their request went through, the custID reserved, the price
    of the purchase, how many seats were reserved, and the location of each
    seat reserved
input: seating and pricing arrays, customer ID, number of seats, desired
    ticket price, row and column counters from previous function
return: void; alters the seating and pricing arrays and prints a confirmation
    to the user
******************************************************************************/
void fill_seating(string seating[rows][cols],string custID,int num_seat,
        int row_num,int col_num,double pricing[rows][cols],double ticket_price)
{
    char row_letter = 'A';
    int seated = 0;

    row_letter += row_num;	
    cout << "OK " << custID << " "; //part of confirmation
    if (row_num < 8 && col_num > 3 && col_num < 16){
        cout << premium_price*num_seat << " "; //cost of purchase
    }
    else {
        cout << general_price*num_seat << " "; //cost of purchase
    }
    cout << num_seat << " ";
    for(int counter = col_num; counter < (col_num + num_seat); counter++){
        seating[row_num][counter] = custID;
        pricing[row_num][counter] = ticket_price;
        cout << row_letter << counter + 1 << " "; //part of confirmation			
        seated++;
        if(seated == num_seat){
	break;
	}	
    }
    cout << endl;	
}

/******************************************************************************
purpose: this function calls other function that check to see if a request of
    seats that had to be split can be seated in the appropriate section; if 
    the checks pass, this function calls other function sthat fill those 
    requests in the seating and pricing charts; if the reservation is 
    successful, this function calls another function that prints a 
    reservation confirmation
return: returns 0 if the split reservations are successful in the appropriate 
    sections; returns 1 if no split reservation could be made
******************************************************************************/
int split_seating(string seating[rows][cols],string custID,int num_seat,
        string price,double pricing[rows][cols])
{
    int remaining_seats = 0;	
    int remaining_seats_two = 0;
    //split seats of hi or any value
    if((price == "hi" || price == "any" ) && (check_split_hi(seating,num_seat,
                                                custID,price) >= num_seat)){
        if(fill_split_hi(seating,num_seat,custID,pricing) >= 0){
            printing_split_confirmation(custID,seating,pricing,num_seat);
            return 0;
        }
    }
    //split seats of lo value
    if((price == "lo") && ((check_split_all(seating,num_seat,custID) - 
        check_split_hi(seating,num_seat,custID,price) >= num_seat))){
            remaining_seats = fill_split_lo_left(seating,num_seat,custID,
                                                    pricing);
        if(remaining_seats > 0){
            remaining_seats_two = fill_split_lo_right(seating,remaining_seats,
                                                        custID,pricing);
        }
        if(remaining_seats > 0){
	  remaining_seats = fill_split_lo_bottom(seating,remaining_seats_two,
	                                           custID,pricing);
        }
        if(remaining_seats > 0){
            rejection(custID);
        }
        if(remaining_seats == 0){
               printing_split_confirmation(custID, seating, pricing, num_seat);
        }
        return 0;
    }	
    //split seats of any value that could not fit in hi
    if((price == "any2") && (check_split_any(seating,num_seat,custID) 
        >= num_seat)){
            fill_split_any(seating,num_seat,custID,pricing);
            printing_split_confirmation(custID, seating, pricing, num_seat);
            return 0;
    }
    return 1;
}

/******************************************************************************
purpose: this function is called if a reservation has to be split, it checks
    to see if an adequate number of seats to meet the number of seats requested
    exist in the entire premium seating section
input: seating array, number of seats, customer ID, desired ticket-price
return: if an adequate number of seats is available in the premium seating 
    section this function returns that number of seats that are available
    as empty strings; prints a rejection statement and returns 0 if there
    are not enough available seats in premium seating
******************************************************************************/
int check_split_hi(string seating[rows][cols],int num_seat,string custID,
        string price)
{	
    int available = 0;
	
    for(int row_num = 0; row_num < 8; row_num++){
	for(int col_num = 4; col_num < 16; col_num++){
            if(seating[row_num][col_num] == "---"){
                available++; //counts availability for hi split tickets
            }
	}	
    }	
		
    if(available >= num_seat){
        return available; //returns number of hi split tickets available
    }
    else if(available < num_seat && price == "hi"){
        rejection(custID); //if not enough hi split tickets are available
    }
    return 0;
}

/******************************************************************************
purpose: assuming there are enough seats available in the premium section,
    this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input:seating and pricing arrays, number of seats, customer ID
return: number of seats that were not placed in the premium seating
    section
******************************************************************************/
int fill_split_hi(string seating[rows][cols],int num_seat,string custID,
        double pricing[rows][cols])
{
    int counter = num_seat;
    double ticket_price = premium_price * (1 - deduction); //hi split price
	
    for(int row_num = 0; row_num < 8; row_num++){
	for(int col_num = 4; col_num < 16; col_num++){
            if(seating[row_num][col_num] == "---"){
		seating[row_num][col_num] = custID;
		counter--; //count down number of seats as seated
		pricing[row_num][col_num] = ticket_price;
            }
            if(counter == 0){
                break;
            }
		
	}	
	if(counter == 0){
		break;
	}
    }
    return counter; //split hi tickets that could not be seated
}

/******************************************************************************
purpose: this function is called if a reservation has to be split, it checks
    to see if an adequate number of seats to meet the number of seats requested
    exist in the entire seating chart
input: seating array, number of seats, customer ID
return: if an adequate number of seats is available in the seating chart
    this function returns that number of seats that are available
    as empty strings; prints a rejection statement and returns 0 if there
    are not enough available seats in the seating chart
******************************************************************************/
int check_split_all(string seating[rows][cols],int num_seat,string custID)
{
    int available = 0;
	
    for(int row_num = 0; row_num < rows; row_num++){
	for(int col_num = 0; col_num < cols; col_num++){
            if(seating[row_num][col_num] == "---"){
                available++;
            }
	}
    }

    if(available >= num_seat){
	return available; //returns split seats available in all the chart
    }
    else if(available < num_seat){
	rejection(custID); //if not enough split seats are available
    }
    return 0;
}

/******************************************************************************
purpose: assuming there are enough split seats available in the lo left section,
    this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input:seating and pricing arrays, number of seats, customer ID
return: 0 if all requested seats are reserved; returns 
number of seats that were not placed in the lo left section if some remain
******************************************************************************/
int fill_split_lo_left(string seating[rows][cols],int num_seat,string custID,
        double pricing[rows][cols])
{
    int counter = num_seat;
    double ticket_price = general_price * (1 - deduction); //split lo price
	
    for(int row_num = 0; row_num < 8; row_num++){
        for(int col_num = 0; col_num < 4; col_num++){
            if(seating[row_num][col_num] == "---"){
		seating[row_num][col_num] = custID;
		counter --;
		pricing[row_num][col_num] = ticket_price;	
            }
            if (counter == 0){
		return 0;
            }
	}
    }
	
    return counter;  //split lo tickets that could not be seated
}
			
/******************************************************************************
purpose: assuming there are enough split seats available in the lo right section,
    this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input:seating and pricing arrays, number of seats, customer ID
return: 0 if all requested seats are reserved; returns 
number of seats that were not placed in the lo right section if some remain
******************************************************************************/
int fill_split_lo_right(string seating[rows][cols],int remaining_seats,
        string custID,double pricing[rows][cols])
{
    int counter = remaining_seats;
    double ticket_price = general_price * ( 1- deduction); //split lo price
	
    for(int row_num = 0; row_num < 8; row_num++){
	for(int col_num = 16; col_num < cols; col_num++){
            if(seating[row_num][col_num] == "---"){
		seating[row_num][col_num] = custID;
		counter--;
		pricing[row_num][col_num] = ticket_price;
            }
            if(counter == 0){
		return 0;
            }
	}
    }
	
    return counter; //split lo tickets that could not be seated
}

/******************************************************************************
purpose: assuming there are enough split seats in the lo bottom section,
    this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input:seating and pricing arrays, number of seats, customer ID
return: 0 if all requested seats are reserved or if the function ends without
    seating all of the split seats
******************************************************************************/
int fill_split_lo_bottom(string seating[rows][cols],int remaining_seats_two,
        string custID,double pricing[rows][cols])
{
    int counter = remaining_seats_two;
    double ticket_price = general_price * (1 - deduction); //split lo price
	
    for(int row_num = 8; row_num < rows; row_num++){
	for(int col_num = 0; col_num < cols; col_num++){
            if(seating[row_num][col_num] == "---"){
		seating[row_num][col_num] = custID;
		counter--;
		pricing[row_num][col_num] = ticket_price;
            }
            if(counter == 0){
		return 0;
            }
	}
    }
	
    return 0; //all seats are either seated or not enough are available
}

/******************************************************************************
purpose: this function is called if a reservation has to be split and the
    user requests any price tickets, it checks
    to see if an adequate number of seats to meet the number of seats requested
    exist in the entire premium seating section
input: seating array, number of seats, customer ID
return: if an adequate number of seats is available in the premium seating 
    section this function returns that number of seats that are available
    as empty strings; prints a rejection statement and returns 0 if there
    are not enough available seats in premium seating
******************************************************************************/
int check_split_any(string seating[rows][cols],int num_seat,string custID)
{
    int available = 0;
	
    for(int row_num = 0; row_num < rows; row_num++){
	for(int col_num = 0; col_num < cols; col_num++){
            if(seating[row_num][col_num] == "---"){
		available++; //counts total number of available split seats
            }
        }
    }
	
    if(available >= num_seat){
	return available; //returns number of free split seats
    }
    else if(available < num_seat){
	rejection(custID); //if not enough split seats are available
    }	
    return 0;
}	

/******************************************************************************
purpose: this function is called if there is an adequate number of split seats
    available in the entire seating chart and the user has requested any
    ticket-price; the function first tries to seat the entire request in the
    premium section, then in the general left section, then in the general 
    right section and lastly in the general bottom section; a series of 
    counters are used to track how many seats are left over after each 
    section check; if all of the seats of the request cannot be seated the
    function calls a rejection function
input: seating and pricing arrays, number of seats, customer ID,
return: void; calls functions that fill seats in the various sections of 
    the array an collects the new number of seats left after each filling
    process
******************************************************************************/
void fill_split_any(string seating[rows][cols],int num_seat,string custID,
        double pricing[rows][cols])
{	
    int counter = 0;
    int counter_two = 0;
    int counter_three = 0;
    int counter_four = 0;

    counter = fill_split_hi(seating, num_seat, custID, pricing); //start hi
    if(counter > 0){
	counter_two = fill_split_lo_left(seating, counter, custID, pricing);
    }
    if(counter_two > 0){
	counter_three = fill_split_lo_right(seating,counter_two,custID,pricing);
    }
    if(counter_three > 0){
	counter_four = fill_split_lo_bottom(seating,counter_three,custID,
	                                       pricing);
    }
    if(counter <= 0){
	rejection(custID); //if nt enough split seats are available
    }
}

/******************************************************************************
purpose: this function prints out a confirmation to the user if their
    request processed successsfully; the confirmation includes the customer ID,
    the price of the purchase, the number of seats allocated, and the 
    identification of each seat assigned to that user
input: seating and pricing arrays, customer ID, number of seats
return: n/a
******************************************************************************/
void printing_split_confirmation(string custID,string seating[rows][cols],
        double pricing[rows][cols], int num_seat)
{
    double total_price = 0;
    char row_letter = 'A';
    
    cout << fixed << noshowpoint << setprecision(0); //maintains decimal
    
    for(int row_num = 0; row_num < rows; row_num++){
        for(int col_num = 0; col_num < cols; col_num++){
            if(seating[row_num][col_num] == custID){
                total_price += pricing[row_num][col_num]; //price of purchase
            }
        }
    }
    
    cout << "OK " << custID << " " << total_price << " ";
    cout << num_seat << " ";
    
      //seat identification
      for(int row_num = 0; row_num < rows; row_num++){
        for(int col_num = 0; col_num < cols; col_num++){
            if(seating[row_num][col_num] == custID){
                cout << (char)(row_letter + row_num) << col_num +1 << " ";
            }
        }
      }
      cout << endl;
}



