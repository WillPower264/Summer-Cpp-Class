/*William Li
CSC 133-GW
Lab7f.cpp*/

#include <iostream>
#include <string>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	//declare num and digit as ints
 	int num, digit;
 	//declare result and set to 0
	int result = 0;
 	//declare digit position variable and set to 0
	int i = 0;
	
	//prompt user to enter a number
	cout <<"Please enter a number to test divisibility by 11: ";
	cin >>num;			//read number into var num

	cout <<num;			//output the number read
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas

	do
	{
		digit = num % 10;					//find the last digit of num
		num = num / 10;						//reduce num by 1 digit
	
		//if 1st, 3rd, 5th, ... digit, then add digit to sum	
		if (i % 2 == 0)	 
		    result += digit;
  	
	  	//if 2nd, 4th, 6th, ...digit, then subtract digit from sum
		else 			 
			result -= digit;	 
		
		i++;		//increment var i by one to determine digit position in num
	}
	while (num > 1);					//loop while num remains greater than 1
	
	//test if the result is divisible by 11
	if (result % 11 == 0)		//if result is divisible, output divisible
		cout <<" is divisible by 11.\n";
	else					//if result is not divisible, output not divisible
		cout <<" is not divisible by 11.\n";
	
	system("pause");
	return 0;
}
