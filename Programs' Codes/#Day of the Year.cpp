/*William Li
CSC 133-GW
Lab10a.cpp*/

#include <iostream>

using namespace std;


bool isLeapYear(int);					//declare function prototypes
int findLeapDayNumber(int, int);
int findNormDayNumber(int, int);
void inputDate(int&, int&, int&, bool&);
void countDays(bool, int, int, int);

char ch;							//declare ch as char

int main()
{
	int month, day, year;				//declare month, day, and year as ints
	bool stop = false;
	month = 1;
	
	cout <<"This program calculates the which day of the year a given date falls on.\n"
		   "Enter 0's to end the program." <<endl <<endl;
	
	//call function inputDate
	inputDate (month, day, year, stop);
		if (stop == true)
			return 0;
	
	while (true)
	{
		//call function isLeapYear and use returned value to call void function 
 		//countDays
		countDays(isLeapYear(year), month, day, year);
		
		//call function inputDate
		inputDate (month, day, year, stop);
		
		if (stop == true)
			return 0;
	}
}
	
void inputDate(int& month, int& day, int& year, bool& stop)
{
	cout <<"Please enter a date: ";
	//read in month, day, and year, separated by a divider entered by the user
	cin >>month;
	
	if (month == 0)
	{
		stop = true;
		return;
	}
	
	cin >>ch >>day >>ch >>year;	
	
	//if user omits first two digits of year
	if (year <= 20 && year >= 0)
		year += 2000;
	else if (year >= 21 && year <= 99)
		year += 1900;	
	
	//test if date is not part of the calendar
	if ((month > 12 || month < 1 || day < 1) || 
		(month == 2 && day > 29 && isLeapYear(year)) ||
		(month == 2 && (day > 28 && !isLeapYear(year))) ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
			 month == 10 || month == 12) && day > 31) || 
		((month == 4 || month == 6 || month == 9 || month == 11 ) && day > 30))
	{
		cout <<"Invalid date. " <<endl <<endl;
		inputDate(month, day, year, stop);
	}
}

//function that returns true or false that determines if a leap year
bool isLeapYear(int year)
{
	//if the year is not divisible by 4, or is divisible by 100 but not 400,
	//then the year is not a leap year and false is returned
	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
	   return false;
	
	//if the year is divisible by 4, but not by 100 unless it is also divisible
	//by 400, then it is a leap year and true is returned  
	return true;
}

void countDays(bool tOrF, int month, int day, int year)
{		
	//output the date entered by the user
	cout <<month <<ch <<day <<ch <<year;
	
	//if ifLeapYear returns true, call funtion findLeapDayNumber
	if (tOrF == true)
		cout <<" is the " <<findLeapDayNumber(month, day);
	//if ifLeapYear returns false, call function findNormDayNumber	
	else
		cout <<" is the " <<findNormDayNumber(month, day);	
	
	//complete final output
	cout <<" day in the year." <<endl <<endl;	
}

//function to determine how many days into a non-leap year a date lies on
int findNormDayNumber(int month, int day)
{
	//declare totalDays as an int and set to 0
 	int totalDays = 0;
	
	//jan, mar, may, jul, aug, oct, dec = 31 days
	//feb = 28 days
	//apr, jun, sep, nov = 30 days
	
	//set up switch structure which adds the number of total days in the months
	//prior to the entered month
	switch (month)
	{
		case 12:				//if december, add # of days in november
			totalDays += 30;
		case 11:				//if november, add # of days in october
			totalDays += 31;
		case 10:				//if october, add # of days in september
			totalDays += 30;	
		case 9:					//if september, add # of days in august
			totalDays += 31;
		case 8:					//if august, add # of days in july
			totalDays += 31;
		case 7:					//if july, add # of days in june
			totalDays += 30;
		case 6:					//if june, add # of days in may
			totalDays += 31;
		case 5:					//if may, add # of days in april
			totalDays += 30;
		case 4:					//if april, add # of days in march
			totalDays += 31;
		case 3:					//if march, add # of days in february
			totalDays += 28;
		case 2:					//if february, add # of days in january
			totalDays += 31;
		case 1:					//if january, don't add any days
			break;
			
		default: 				//if user entered invalid month, output error
			cout <<"Invalid date!";
	}	
	
	//add the number of days in the current month with total of days in 
	//previous months
	totalDays += day;
	//return total number of days into the year the date lies on
	return totalDays;
}

//function to determine how many days into a leap year a date lies on
int findLeapDayNumber(int month, int day)
{
	//if user enter the date 2/29, return the value 59
	if (month == 2 && day == 29)
	    return 60;
	    
	//call function findNormDayNumber and assign value into totalDays
	int totalDays = findNormDayNumber(month, day);
	
	//if the given date is before february 29, return the total days 
	//without any adjustment
	if (totalDays < 60)
	    return totalDays;
	//if the given date is after february 29, add 1 to total days
	//and return adjusted value
	return totalDays + 1;
}
