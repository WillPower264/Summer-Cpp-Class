/*William Li
CSC 133-GW
Lab7e.cpp*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long int num;			//declare num and loop control variable as ints
	int i;
	bool prime = true;			//declare prime as bool value and set to true
	
	cout <<"This program tests a number to determine if it is prime or not." <<endl;
	cout <<"To exit the program, enter a negative number." <<endl <<endl;
	
	cout <<"Please enter a number: ";
	cin >>num;					//read number from file into variable num
	
	while (num >= 0)
	{
		//if number is negative, display error
		if (num < 0)			
			cout <<"Error. Please input a positive number.";
		
		//if number is 2, then prime
		else if(num == 2)
			cout <<"The number " <<num <<" is prime." <<endl;
		
		//if number is 1 or 0, then neither prime nor composite 
		else if (num == 1 ||num == 0)
			cout <<"The number " <<num <<" is neither prime nor composite." <<endl;
		
		//if number is even, then composite
		else if (num % 2 == 0)
			cout <<"The number " <<num <<" is composite." <<endl;
		
		//if odd and greater than 1, then determine if prime
		else
		{
			i = sqrt(num);				//assign i to sqrt of num
			 
			while (i >= 3)				//loop if sqrt is greater than 3
			{			
				if (i % 2 == 0)			//if sqrt of number is even, add 1 to i
					i++;
				if (num % i == 0)		//if num is divisible by i, num is not prime
					prime = false;
				
				i -= 2;					//decrement i by 2 after each iteration
			}		
			
			//if prime was not changed, then output the number is prime
			if (prime == true)
				cout <<"The number " <<num <<" is prime." <<endl;
			
			//if prime was changed to false, then output the number is composite
			else if (prime == false)
				cout <<"The number " <<num <<" is composite." <<endl;	
		}	
		prime = true;
		cout <<endl <<"Please enter another number: ";
		cin >>num;
	}
	return 0;
}
