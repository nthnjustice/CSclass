#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

#include "hall.h"

void command_loop(string command, string custID, int num, string price,
                  int day_num, string day, Hall hall[]);
void rejection_final(string custID);
void request_main(string custID, int num, string price, string day,
                  Hall hall[]);
void print_main(string day, Hall hall[], int day_num);
void request_info(string custID, int num, string price, string day, 
                  Hall hall[]);

/******************************************************************************
purpose: declares variables and calls the comman loop; if command loop exits
    main is done and the entire program is finished
input: n/a
return: n/a
******************************************************************************/
int main()
{
  Hall hall[SIZE];
  string command;
  string custID;
  int num = 0;
  string price;
  int day_num = 0;
  string day;

  command_loop(command, custID, num, price, day_num, day, hall);
}

/******************************************************************************
purpose: takes in the desired command from the user; calls the functions
    that corresponds to the inputted command
input: seating and pricing array, desired command from the user
returns: n/a
******************************************************************************/
void command_loop(string command, string custID, int num, string price,
                  int day_num, string day, Hall hall[SIZE])
{
  do{
    cin >> command;
    if(command == "RQ"){
      request_info(custID, num, price, day, hall);
      }
    else if(command == "CA"){
      cin >> custID;
      cin >> day_num;
      if((day_num != 0) && (day_num != 1) && (day_num != 2) && (day_num != 3)
          && (day_num != 4) && (day_num != 5) && (day_num != 6)){
      cout << "NO bad-day " << endl;
      }
      else{ hall[day_num].cancel(custID);
      }
    }
    else if(command == "PR"){
      cin >> day;
    if((day != "0") && (day != "1") && (day != "2") && (day != "3") &&
        (day != "4") && (day != "5") && (day != "6") && (day != "all")){
      cout << "NO bad-day " << endl;
    }
    else{  print_main(day, hall, day_num);
    }
    }
  }while(command != "QU");
}

/******************************************************************************
purpose: takes in the desired information from the user for the
    requesting process; calls the functions request_main
input: private seating and pricing array, customer ID, desired price, desired
    day, all 7 halls
returns: n/a
******************************************************************************/
void request_info(string custID, int num, string price, string day,
                  Hall hall[])
{
  cin >> custID;
  cin >> num;
  cin >> price;
  cin >> day;
  if((day != "0") && (day != "1") && (day != "2") && (day != "3") &&
      (day != "4") && (day != "5") && (day != "6") && (day != "any")){
    cout << "NO bad-day " << endl;
  }
  else{request_main(custID, num, price, day, hall);
  }
}

/******************************************************************************
purpose: if any day is requested, function looks through all 7 halls and seats
    when the first available valid option is presented; if a specific day
    is requested, function converts string day to an int and looks in the 
    appropriate hall for that day to seat the customer request
input: private seating and pricing array, customer ID, desired price, desired
    day, all 7 halls
returns: n/a
******************************************************************************/
void request_main(string custID, int num, string price, string day,
                  Hall hall[])
{
  int a = 0;
  int day_num;
  if(day == "any"){
    for (day_num = 0; day_num < SIZE; day_num++){
      if (hall[day_num].request(custID, num, price, day_num)){
        a = 10; //an assignment test that will eventually test to see if the
                //seating process completed successfully
        break;
      }
    }
  }
  if(day != "any"){
    day_num = atoi(day.c_str());
    if((day_num == 0) || (day_num == 1) || (day_num == 2) || (day_num == 3)
        || (day_num == 4) || (day_num == 5) || (day_num == 6)){
          if(hall[day_num].request(custID, num, price, day_num)){
            a = 10;  //an assignment test that will eventually test to see if
                    //the seating process completed successfully
          }
     }
  }
  if(a != 10){ 
    //will be true only if the user absolutely could not be seated
    //because either all halls are unable to satisfy the request or the user
    //name has already been used in the hall that the reservation is trying to
    //use
    rejection_final(custID);
  }
}

/******************************************************************************
purpose: will print a specific day or the function will loop through all of
    the halls and print each one; calls another print function
input: desired day, array of halls, day converted to an int called day_num
returns: n/a
******************************************************************************/
void print_main(string day, Hall hall[], int day_num)
{
 if(day == "all"){
   for(int i = 0; i < SIZE; i++){ //prints all of the halls
     hall[i].print();
   }
 }
 else{
   day_num = atoi(day.c_str()); //converts string day to an integer
   hall[day_num].print(); //prints a single hall
 }
}

/******************************************************************************
purpose: ultimate rejection statement if a request cannot be satisfied; called
    by many other functions
intput: customer ID
returns: n/a
******************************************************************************/
void rejection_final(string custID)
{
  cout << "NO " << custID << " not-available" << endl;
}

