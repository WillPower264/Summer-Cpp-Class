/*William Li
CSC 133-GW
Lab9c.cpp*/

#include <iostream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

void reverseDigit(int);					//declare function prototype

int main()
{
	int num;							//declare num as an int
	
	//prompt user to enter an integer to be flipped
	cout <<"Enter an integer to be flipped: ";
	cin >>num;							//read number int var num
	cout <<endl;
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	//output statement and number to be followed by reversed number
	cout <<"The number " <<num <<" reversed is: ";
	reverseDigit(num);			//call void function with num as actual param
	cout <<endl;
	
	system("pause");			
	return 0;
}

//function to output the reversed digit
void reverseDigit(int number)
{	
	//declare newNum, digit, j, places, and num1 as ints
	int newNum, digit, j, places, num1;	
	
	//assign value of number into num1
	num1 = number;
	
	//set up for loop to count the number of places in the given number
	for (places = 0; num1 >= 1; places++)
		num1 = num1/10;
		
	//if the number is negative, execute following statetments	
	if (number < 0)
	{
		//output a negative sign before the reversed number
		cout <<"-";
		//assign the opposite value of number back into number
	   	number = -number;
	}
	
	//set up for loop which continues as long as the number is greater than or 
	//equal to 1 after being divided by 10
	for (int i = number; i >= 1; i = i / 10)
	{
		//calculate digit by finding the remainder when dividing by 10
	 	digit = i % 10;
	  	
	  	//output digit
	  	cout <<digit;
	  	
	  	//increment j to keep track of iterations
	  	j++;
	  	
	  	//while the number remains above or equal to 10, add a comma
	  	if (i >= 10)
	  	{	
	  		//if the number of places is divisible by 3, add a comma if it is 
		  	//the third, sixth, ninth and so on place
		 	if (places % 3 == 0)
 			{
			   if (j % 3 == 0)
		  	          cout << ",";
 			}    
 			
 			//if the number of places divided by 3 has a remainder 1, add a 
		 	//comma if it is the first, fourth, seventh and so on place
			else if (places % 3 == 1)
			{
				if (j % 3 == 1)
		  		 	  cout <<",";
			}	
			
			//if the number of places divided by 3 has a remainder 1, add a 
			//comma if it is the second, fifth, eighth and so on place
			else
			{
				if (j % 3 == 2)   	  
	  				  cout <<",";
			}
	  	}
	}	
}
