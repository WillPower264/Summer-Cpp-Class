/*William Li
CSC 133-GW
Lab10a.cpp*/

#include <iostream>
#include <fstream>

using namespace std;


bool isLeapYear(int);					//declare function prototypes
int findLeapDayNumber(int, int);
int findNormDayNumber(int, int);
void inputDate(int&, int&, int&);
void countDays(bool);

ifstream fin;				//declare input stream variable
ofstream fout;				//declare output stream variable
	
int month, day, year;				//declare month, day, and year as ints
char ch;							//declare ch as char

int main()
{
	fin.open("Lab10ain.txt");			//open input stream
	fout.open("Lab10aout.txt");			//open output stream
	
	//call function inputDate
	inputDate (month, day, year);
	
	//call function isLeapYear and use returned value to call void function 
 	//countDays
	countDays(isLeapYear(year));

	fin.close();						//close input stream
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}

void inputDate(int& month, int& day, int& year)
{
	char ch;
	
	//read in month, day, and year, separated by a divider entered by the user
	fin >>month >>ch >>day >>ch >>year;	
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

void countDays(bool tOrF)
{		
	//output the date entered by the user
	fout <<month <<'-' <<day <<'-' <<year;
	
	//if ifLeapYear returns true, call funtion findLeapDayNumber
	if (tOrF == true)
		fout <<" is the " <<findLeapDayNumber(month, day);
	//if ifLeapYear returns false, call function findNormDayNumber	
	else
		fout <<" is the " <<findNormDayNumber(month, day);	
	
	//complete final output
	fout <<" day in the year.";	
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
			cout <<"Error. Please enter a valid month number.";
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
	    return 59;
	    
	//call function findNormDayNumber and assign value into totalDays
	int totalDays = findNormDayNumber(month, day);
	
	//if the given date is before february 29, return the total days 
	//without any adjustment
	if (totalDays < 59)
	    return totalDays;
	//if the given date is after february 29, add 1 to total days
	//and return adjusted value
	return totalDays + 1;
}
