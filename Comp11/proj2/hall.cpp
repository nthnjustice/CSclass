#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "hall.h"

/******************************************************************************
purpose: initializes the seating chart by setting the array elements
    to empty strings; initializes the pricing chart by setting the array
    elements to 0.0
input: private seating array and private pricing array
returns: void; modifies seating and pricing arrays
******************************************************************************/
Hall::Hall()
{
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      seating[i][j] = "---"; //all of seating chart gets empty string
      pricing[i][j] = 0.0; //all of pricing chart gets value 0.00
    }
  }
}

/******************************************************************************
purpose: prints the running seating chart; also prints the running calculated
    revenue
input: private seating and private pricing array
returns: n/a
******************************************************************************/
void Hall::print()
{
  cout << fixed << showpoint << setprecision(2); //sets decimal points
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cout << seating[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Revenue: " << revenue_calculator() << endl;
  cout << fixed << showpoint << setprecision(2); //sets decimal points
}

/******************************************************************************
purpose: calculates the running total revenue from the pricing array; 
input: private pricing array
returns: the current total revenue
******************************************************************************/
double Hall::revenue_calculator()
{
  double revenue = 0.0;

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      revenue = revenue + pricing[i][j]; //adds up total presen in entire array
    }
  }

  return revenue;
}

/******************************************************************************
purpose: cancells a previously made request and removes the alterations to the
    seating and pricing arrays
input: private seating and private pricing arrays, customer ID from the user
returns: void; alters the seating and pricing arrays
******************************************************************************/
bool Hall::cancel(string custID)
{
  int counter = 0;

  while(custID.size() < 3){
    custID += " ";
  }

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      if(seating[i][j] == custID){
	seating[i][j] = "---"; //sets seat back to empty string
	pricing[i][j] = 0.0; //sets seat back to value 0.00
        counter++;
      }
    }
  }
  if(counter != 0){
    cout << "OK " << custID << " cancelled" << endl;
      return true;
  }
  else{ //if cancellation fails
    cout << "NO " << custID << " no-reservation" << endl;
      return false;
  }
}

/******************************************************************************
purpose: takes in the customer ID, the number of tickets, and the ticket-price
    from the user; calles the functions that check if customer ID has already
    been used or if the number of tickets is a bad number; call sthe function
    that leads the checking for availability of seats
input: private seating and private pricing arrays, customer ID from the user,
    number of seats from the user, desired ticket-price from the user
returns: n/a
******************************************************************************/
bool Hall::request(string custID, int num, string price, int day)
{
  int a = 0;
  private_day = day;
  while(custID.size() < 3){ //maintains a 3 character maximum to the customer
    custID += " ";          //to maintain an organized seating chart
  }
    if((name_already_reserved(custID) == false) && 
      (bad_number_requested(custID, num) == false)){
        check_seating_type_desired(custID, num, price);
        a = 10;
        return true;
    }
    else{
      return false;
    }
}

/******************************************************************************
purpose: error check that alerts the request function that the inputted
     customer ID has already been used; a single customer ID can only be used
     once
input: private seating array and customer ID
returns: true if the customer ID has already been used and the program
    ignores the command; false if the customer ID is novel and the program
    continues with the command
******************************************************************************/
bool Hall::name_already_reserved(string custID)
{
  for(int i = 0; i < ROWS; i++){ 
    for(int j = 0; j < COLS; j++){
      if(custID == seating[i][j]){
        return true;
      }
    }
  }

  return false;
}

/******************************************************************************
purpose: checks to see if the number of tickets requested by the user is
    greater than or equal to 1 and less than or equal to 12; program only
    approves number of tickets that lie in that range
input: number of seats and the customer ID
returns: false if the number of tickets is invalid; true if the number of 
    tickets is approved and the program continues with the command
******************************************************************************/
bool Hall::bad_number_requested(string custID, int num)
{
  if((num < min_num_seat) || (num > max_num_seat)){
    cout << "NO " << custID << " bad-number" << endl;

    return true;
  }

  return false;
}

/******************************************************************************
purpose: breaks down the search function into three seperate and callable
    functions that correspond the the ticket prices
input: private seating and pricing arrays, desired price, number of seats,
  customer ID
returns: void; calls the appropriate search function for the desired ticket
    price
******************************************************************************/
bool Hall::check_seating_type_desired(string custID, int num, string price)
{
     if(price == "hi"){
       if(search_hi_seating(custID, num, price)){
         return true;
       }
     }
     if(price == "lo"){
       if(search_lo_seating(custID, num, price)){
        return true;
       }
     }
     if(price == "any"){
       if(any_seating(custID, num, price)){
        return true;
       }
     }
     return false;
}

/******************************************************************************
purpose: searches through the high section of the seating array and call the
     function that checks to see if the particular index is already occupied,
     if not the function calls another function that seats the customer ID
     into the proper seats in a continues row; if the number of seats can't
     be seated in a single row, the function call another function that
     splits of seats
input: private seating and private pricing arrays, customer ID,
     number of seats, ticket-price desired
returns: returns true if the function successfully seats the customer ID in
    the proper number of seats in a single row, also can return true if the
    split seating function is called, returns false if the function runs
    unsuccessfully.
******************************************************************************/
bool Hall::search_hi_seating(string custID, int num, string price)
{
  double ticket_price = premium_price;

  for(int row_num = 0; row_num < HI_LIM_BOTTOM; row_num++){
    for(int col_num = HI_LIM_LEFT; col_num < HI_LIM_RIGHT; col_num++){
      if(check_if_occupied_hi(num, row_num, col_num) == true){
        fill_seat(custID, num,row_num, col_num, ticket_price);
          return true;
      }
    }
  }

  if(split_seating(custID, num, price) == 0)
    return true;
  return false;
}

/******************************************************************************
purpose: checks to see if each index in the premium seating is already
    occupied and therefore unavailable to new customers
input: private seating array, number of seats, row and column counters from the
    search_hi_seating function
returns: false if the index of the array is NOT available and IS occupied,
    returns false if the loops extend past the premium seating boundaries,
    returns true if the checks fail and the index is an empty string and
    therefore is available
******************************************************************************/
bool Hall::check_if_occupied_hi(int num, int row_num, int col_num)
{
  for(int counter = col_num; counter < (num + col_num); counter++){
    if(seating[row_num][counter] != "---"){ //means is occupied
      return false;
    }
    if(counter > (HI_LIM_RIGHT - 1)){
      return false;
    }
  }

  return true;
}

/******************************************************************************
purpose: if the occupied seating check passes and the number of seats
    requested are located along one another continuesly, this function gets
    called to replace the empty string that represents the seat with the
    customer ID; also prints a reservation confirmation to the user that
    lets them know their request went through, the custID reserved, the price
    of the purchase, how many seats were reserved, and the location of each
    seat reserved
input: private seating and pricing arrays, customer ID, number of seats,
    desired ticket price, row and column counters from previous function
return: void; alters the seating and pricing arrays and prints a confirmation
    to the user
******************************************************************************/
void Hall::fill_seat(string custID, int num, int row_num, int col_num,
                      double ticket_price)
{
  char row_letter = 'A';
  int seated = 0;

  row_letter += row_num;	
  cout << "OK " << custID << " "; //part of confirmation
  if (row_num < HI_LIM_BOTTOM && col_num > (HI_LIM_LEFT - 1) 
    && col_num < HI_LIM_RIGHT){ 
    cout << premium_price * num << " "; //cost of purchase
  }
  else {
    cout << general_price * num << " "; //cost of purchase
  }
  cout << num << " " << private_day << " ";
  for(int counter = col_num; counter < (col_num + num); counter++){
    seating[row_num][counter] = custID;
    pricing[row_num][counter] = ticket_price;
    cout << row_letter << counter + 1 << " ";  //part of confirmation
    seated++;
    if(seated == num){
      break;
    }
  }
  cout << endl;
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
input: private seating and pricing arrays, customer ID, number of seats,
    desired ticket-price
returns: true if the customer is seated in a continues row for the proper
    number of seats in any of the three lo sections; returns false if the
    single row seating was unsuccessful and the split seating function is
    called
******************************************************************************/
bool Hall::search_lo_seating(string custID, int num, string price)
{
  int col_num = 0;
  double ticket_price = general_price;

  for(int row_num = 0; row_num < ROWS; row_num++){
    for(col_num = 0; col_num < COLS; col_num++){
                   //checks for availability and seats accordingly
      if(check_if_occupied_left(num, row_num, col_num) == true){
        fill_seat(custID, num, row_num, col_num, ticket_price);
        return true;
      }
    }
    for(col_num = HI_LIM_RIGHT; col_num < COLS; col_num++){
                   //checks for availability and seats accordingly
      if(check_if_occupied_right(num, row_num, col_num) == true){
        fill_seat(custID, num, row_num, col_num, ticket_price);
        return true;
      }
    }
    for(col_num = 0; col_num < COLS; col_num++){
                  //checks for availability and seats accordingly
      if(check_if_occupied_bottom(num, row_num, col_num) == true){
        fill_seat(custID, num, row_num, col_num, ticket_price);
        return true;
      }
    }
  }
    //called if seats can't all be put together in 1 row
  split_seating(custID, num, price);

  return false;
}

/******************************************************************************
purpose: checks to see if each index in the left lo section is already
    occupied and therefore is unavilable to new customers
input: private seating array, number of seats, and row and column
    counters from the search_lo_seating function
return: false if the index of the array is NOT available and IS occupied,
    false if the for loop from the previous function exceeds the boundaries
    of the low left section, returns true if the checks fail and the index is
    an empty string and therefore is available
******************************************************************************/
bool Hall::check_if_occupied_left(int num, int row_num, int col_num)
{
  if(row_num >= (HI_LIM_BOTTOM - 1)){
    return false;
  }

  for(int counter = col_num; counter < (num + col_num); counter++){
    if(seating[row_num][counter] != "---"){
      return false;
    }
    if(counter > (HI_LIM_LEFT - 1)){
      return false;
    }
  }

  return true;
}

/******************************************************************************
purpose: checks to see if each index in the right lo section is already
    occupied and therefore is unavilable to new customers
input: private seating array, number of seats, and row and column counters
    from the search_lo_seating function
return: false if the inex of the array is NOT available and IS occupied,
    false if the for loop from the previous function exceeds the boundaries
    of the low right section, returns true if the checks fail and the index
    is an empty string and therefore is available
******************************************************************************/
bool Hall::check_if_occupied_right(int num, int row_num, int col_num)
{
  if(row_num >= (HI_LIM_BOTTOM - 1)){
    return false;
  }

  for(int counter = col_num; counter < (num + col_num); counter++){
    if(seating[row_num][counter] != "---"){
      return false;
    }
    if((counter < HI_LIM_RIGHT) || (counter > (COLS - 1))){
      return false;
    }
  }

  return true;
}

/******************************************************************************
purpose: checks to see if each index in the bottom lo section is already
    occupied and therefore is unavilable to new customers
input: private seating array, number of seats, and row and column counters
    from the search_lo_seating function
return: false if the inex of the array is NOT available and IS occupied,
    false if the for loop from the previous function exceeds the boundaries
    of the low bottom section, returns true if the checks fail and the index
    is an empty string and therefore is available
******************************************************************************/
bool Hall::check_if_occupied_bottom(int num, int row_num, int col_num)
{
  if((row_num > (max_num_seat - 1)) || (row_num < HI_LIM_BOTTOM )){
    return false;
  }

  for(int counter = col_num; counter < (num + col_num); counter++){
    if((counter < 0) || (counter > (COLS - 1))){
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
input: private seating and pricing arrays, customer ID, number of seats,
    desired price
return: n/a
******************************************************************************/
bool Hall::any_seating(string custID, int num, string price)
{
  if(search_hi_seating(custID, num, price) == false){
    if(search_lo_seating(custID, num, price) == false){
      price = "any2";
      //means that seats can't be placed together in hi
      //calls to split the tickets of 'any' value
      if(split_seating(custID, num, price) == 0){
        return true;
      }
    }
  }
  return false;
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
int Hall::split_seating(string custID, int num, string price)
{
  int remaining_seats = 0;
  int remaining_seats_mark2 = 0;
  //split seats of hi or any value
  if(((price == "hi") || (price == "any")) && 
    (check_split_hi(custID, num, price) >= num)){
      if(fill_split_hi(custID, num) >= 0){
        printing_split_confirmation(custID, num);
        return 0;
      }
  }
  //split seats of lo value
  if((price == "lo") && ((check_split_all(custID, num) - 
    check_split_hi(custID, num, price) >= num))){
      remaining_seats = fill_split_lo_left(custID, num);
      if(remaining_seats > 0){
        remaining_seats_mark2 = fill_split_lo_right(custID, remaining_seats);
      }
      if(remaining_seats > 0){
        remaining_seats = fill_split_lo_bottom(custID, remaining_seats);
      }
      if(remaining_seats > 0){
        rejection(custID);
      }
      if(remaining_seats == 0){
        printing_split_confirmation(custID, num);
      }
      return 0;
  }
  //split seats of any value that could not fit in hi
  if((price == "any2") && (check_split_any(custID, num) >= num)){
    fill_split_any(custID, num);
    printing_split_confirmation(custID, num);
    return 0;
  }

  return 1;
}

/******************************************************************************
purpose: this function is called if a reservation has to be split, it checks
    to see if an adequate number of seats to meet the number of seats requested
    exist in the entire seating chart
input: private seating array, number of seats, customer ID
return: if an adequate number of seats is available in the seating chart
    this function returns that number of seats that are available
    as empty strings; prints a rejection statement and returns 0 if there
    are not enough available seats in the seating chart
******************************************************************************/
int Hall::check_split_all(string custID, int num)
{
  int available = 0;

  for(int row_num = 0; row_num < ROWS; row_num++){
    for(int col_num = 0; col_num < COLS; col_num++){
      if(seating[row_num][col_num] == "---"){
        available++;
      }
    }
  }

  if(available >= num){
    return available; //returns split seats available in all the chart
  }
  else if(available < num){
    rejection(custID); //if not enough split seats are available
  }

  return 0;
}

/******************************************************************************
purpose: this function is called if a reservation has to be split, it checks
    to see if an adequate number of seats to meet the number of seats requested
    exist in the entire premium seating section
input: private seating array, number of seats, customer ID, desired 
    ticket-price
return: if an adequate number of seats is available in the premium seating 
    section this function returns that number of seats that are available
    as empty strings; prints a rejection statement and returns 0 if there
    are not enough available seats in premium seating
******************************************************************************/
int Hall::check_split_hi(string custID, int num, string price)
{
  int available = 0;

  for(int row_num = 0; row_num < HI_LIM_BOTTOM; row_num++){
    for(int col_num = HI_LIM_LEFT; col_num < HI_LIM_RIGHT; col_num++){
      if(seating[row_num][col_num] == "---"){
        available++; //counts availability for hi split tickets
      }
    }
  }

  if(available >= num){
    return available; //returns number of hi split tickets available
  }
  else if((available < num) && (price == "hi")){
    rejection(custID); //if not enough hi split tickets are available
  }

  return 0;
}

/******************************************************************************
purpose: assuming there are enough seats available in the premium section,
    this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input:private seating and pricing arrays, number of seats, customer ID
return: number of seats that were not placed in the premium seating
    section
******************************************************************************/
int Hall::fill_split_hi(string custID, int num)
{
  int counter = num;
  double ticket_price = premium_price * (1 - deduction); //hi split price

  for(int row_num = 0; row_num < HI_LIM_BOTTOM; row_num++){
    for(int col_num = HI_LIM_LEFT; col_num < HI_LIM_RIGHT; col_num++){
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
purpose: assuming there are enough split seats available in the lo left section,
    this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input: private seating and pricing arrays, number of seats, customer ID
return: 0 if all requested seats are reserved; returns 
number of seats that were not placed in the lo left section if some remain
******************************************************************************/
int Hall::fill_split_lo_left(string custID, int num)
{
  int counter = num;
  double ticket_price = general_price * (1 - deduction); //split lo price

  for(int row_num = 0; row_num < HI_LIM_BOTTOM; row_num++){
    for(int col_num = 0; col_num < HI_LIM_LEFT; col_num++){
      if(seating[row_num][col_num] == "---"){
        seating[row_num][col_num] = custID;
        counter--;
        pricing[row_num][col_num] = ticket_price;
      }
      if (counter == 0){
        return 0;
      }
    }
  }

  return counter; //split lo tickets that could not be seated
}

/******************************************************************************
purpose: assuming there are enough split seats available in the lo right,
    section this function fills those empty string seats with the customer ID
    and calculates the price of the purchase with a 10% discount
input: private seating and pricing arrays, number of seats, customer ID
return: 0 if all requested seats are reserved; returns 
number of seats that were not placed in the lo right section if some remain
******************************************************************************/
int Hall::fill_split_lo_right(string custID, int remaining_seats)
{
  int counter = remaining_seats;
  double ticket_price = general_price * (1 - deduction); //split lo price

  for(int row_num = 0; row_num < HI_LIM_BOTTOM; row_num++){
    for(int col_num = 0; col_num < COLS; col_num++){
      if(seating[row_num][col_num] == "---"){
        seating[row_num][col_num] = custID;
        counter--;
        pricing[row_num][col_num] = ticket_price;
      }
      if (counter == 0){
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
input: private seating and pricing arrays, number of seats, customer ID
return: 0 if all requested seats are reserved or if the function ends without
    seating all of the split seats
******************************************************************************/
int Hall::fill_split_lo_bottom(string custID, int remaining_seats_mark2)
{
  int counter = remaining_seats_mark2;
  double ticket_price = general_price * (1 - deduction); //split lo price

  for(int row_num = HI_LIM_BOTTOM; row_num < ROWS; row_num++){
    for(int col_num = 0; col_num < COLS; col_num++){
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
input: private seating array, number of seats, customer ID
return: if an adequate number of seats is available in the premium seating 
    section this function returns that number of seats that are available
    as empty strings; prints a rejection statement and returns 0 if there
    are not enough available seats in premium seating
******************************************************************************/
int Hall::check_split_any(string custID, int num)
{
  int available = 0;

  for(int row_num = 0; row_num < ROWS; row_num++){
    for(int col_num = 0; col_num < COLS; col_num++){
      if(seating[row_num][col_num] == "---"){
	available++; //counts total number of available split seats
      }
    }
  }

  if(available >= num){
    return available; //returns number of free split seats
  }
  else if(available < num){
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
input: private seating and pricing arrays, number of seats, customer ID,
return: void; calls functions that fill seats in the various sections of
    the array an collects the new number of seats left after each filling
    process
******************************************************************************/
void Hall::fill_split_any(string custID, int num)
{
  int counter = 0;
  int counter_two = 0;
  int counter_three = 0;
  int counter_four = 0;

  counter = fill_split_hi(custID, num);

  if(counter > 0){
    counter_two = fill_split_lo_left(custID, counter); //start hi
  }
  if(counter_two > 0){
    counter_three = fill_split_lo_right(custID, counter_two);
  }
  if(counter_three > 0){
    counter_four = fill_split_lo_bottom(custID, counter_three);
  }
  if(counter <= 0){
    rejection(custID); //if not enough split seats are available
  }
}

/******************************************************************************
purpose: this function prints out a confirmation to the user if their
    request processed successsfully; the confirmation includes the customer ID,
    the price of the purchase, the number of seats allocated, and the 
    identification of each seat assigned to that user
input: private seating and pricing arrays, customer ID, number of seats
return: n/a
******************************************************************************/
void Hall::printing_split_confirmation(string custID, int num)
{
  double total_price = 0;
  char row_letter = 'A';

  cout << fixed << noshowpoint << setprecision(0); //maintains decimal

  for(int row_num = 0; row_num < ROWS; row_num++){
    for(int col_num = 0; col_num < COLS; col_num++){
      if(seating[row_num][col_num] == custID){
        total_price += pricing[row_num][col_num]; //price of purchase
      }
    }
  }

  cout << "OK " << custID << " " << total_price << " ";
  cout << num << " ";
  cout << private_day << " ";

   //seat identification
  for(int row_num = 0; row_num < ROWS; row_num++){
    for(int col_num = 0; col_num < COLS; col_num++){
      if(seating[row_num][col_num] == custID){
        cout << (char)(row_letter + row_num) << col_num +1 << " ";
      }
    }
  }
  cout << endl;
}

/******************************************************************************
purpose: this function prints out a confirmation generic rejection statement
    if called
input: private seating and pricing arrays, customer ID
return: n/a
******************************************************************************/
void Hall::rejection(string custID)
{
  cout << "NO " << custID << " not-available" << endl;
}
