#include <iostream>
using namespace std;

// namestats.cpp -- age stats by names
//   usage: namestats name < datafile-of-year-name
//  result: find avg, then range of ages and frequency by age
//  history: revised 2012-10-23 added 'who' to show_freq

struct Person {
	int age;
	string name;
	// define attributes of a person here
};

const int MAXPEOPLE = 50000;
const int SENTINEL  = -1;
const int NOW       = 2012;

void    read_in_data( Person[], int, int);
string  get_name();
void	print_ages( Person[], int, string );
void    do_stats( Person[], int, string );
int	find_max( Person[], int, string );
int	find_min( Person[], int, string );
double	find_avg( Person[], int, string );
void	show_freq( Person[], int, string, int, int );

int main()
{
	Person	people[MAXPEOPLE];
	string	name;

	read_in_data( people, SENTINEL, MAXPEOPLE );
	name = get_name();
	print_ages( people, SENTINEL, name );
	do_stats( people, SENTINEL, name );
	return 0;
}
// --- read_in_data ------------------------------------------------------
//  args: list of structs, sentinel, max space in array
//  rets: nothing
//  does: reads from cin a year and name, puts sentinel in array
//  errs: calls exit if out of space
//
void read_in_data( Person list[], int sentinel, int space )
{
	int	yr;
	string	nm;
	int	pos = 0;

	do {
		cin >> yr >> nm ;
		if ( pos >= space ){
			cerr << "Out of space\n";
			exit(1);
		}
		if (yr == sentinel){
			list[pos].age = sentinel;
		}
		else {
			list[pos].age = (NOW - yr);
			list[pos].name = nm;
		}
		pos++;
		// TODO: add code here to store data in struct
	} while ( yr != sentinel );
}
// --- get_name ----------------------------------------------------------
//  purp: read in one name from cin
//  args: none
//  rets: the name
string get_name()
{
	string n;
	cin >> n;
	return n;
	// TODO: add code here to read in the name and return it
}

// --- print_ages -------------------------------------------------------
//  purp: print all ages for the specified name
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void print_ages( Person list[], int sentinel, string who )
{
	int pos = 0;
	do {
		if (list[pos].name == who ){
			cout << list[pos].age << endl;
		}
		pos++;
		
	}
	while ( list[pos].age != sentinel );
	
	// TODO: write and test this function first
}
// --- do_stats ----------------------------------------------------------
//  purp: compute and print avg, range AND freq for each age in range
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void do_stats( Person list[], int sentinel, string who )
{
	int	min, max;	// min and max age for 'who'
	double	avg;

	avg = find_avg( list, sentinel, who );
	min = find_min( list, sentinel, who );
	max = find_max( list, sentinel, who );
	cout << "average: " << avg << endl;
	cout << "range: "   << min << "-" << max << endl;
	show_freq( list, sentinel, who, min, max );
}
double find_avg(Person list[], int sent, string name)
{
	int pos = 0;
	double average = 0.0;
	double sum = 0.0;
	for ( int i = 0, list[i] != sent, 
}
int find_min( Person list[], int sent, string name )
{
}
int find_max( Person list[], int sent, string name )
{
}
void show_freq( Person list[], int sent, string who, int min, int max )
{
}
