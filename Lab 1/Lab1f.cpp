//William Li
//CSC 133-GW
//Lab1f.cpp

#include <iostream>
using namespace std;

int main( )
{
	char yesOrNo; //variable declarations
	int year = 2008;
	int birthYear;
	int ageThisYear;
	
	cout <<"This program illustrates the use of variables.\n";
	cout <<"Please enter your year of birth: ";
	cin >>birthYear;
	
	cout <<"Is the year still " <<year <<"- (Y/N)?";
	cin >>yesOrNo;
	
	if ((yesOrNo == 'N') || (yesOrNo == 'n'))
	{
	   			 cout <<"Please enter current year (2008): ";
	   			 cin >>year;
	}
	ageThisYear = year - birthYear;
	cout <<"You are " <<ageThisYear <<" this year.\n";
	cout <<"You are obviously ";
	
	if (ageThisYear < 13)
	   cout <<"a young person.";
	else if ((ageThisYear >= 13) && (ageThisYear < 20))
 		 cout <<"a teenager.";
 	else if ((ageThisYear >= 20) && (ageThisYear < 40))
	 	 cout <<"a person waiting for life to begin!";
	else if (ageThisYear == 40)
		 cout <<"a person whose life is now beginning!";
	else if ((ageThisYear > 40)	&& (ageThisYear < 60))
		 cout <<"a person who wonders if work is worth it.";
	else
		cout <<"a person in the prime of life.";
		
	system("pause");
	return 0;	  
}
