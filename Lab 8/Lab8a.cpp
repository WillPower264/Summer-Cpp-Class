/*William Li
CSC 133-GW
Lab8a.cpp*/

#include <iostream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	//declare int variables for the first and second number
	int firstNum, secondNum;
	//declare double variables for sum of the odd squares and sum of 
 	//the even numbers
	double oddSquareSum = 0.0, evenIntSum = 0.0;
	//declare three loop control variables
	int i, j = 1, k = 0;
	
	//prompt user to enter two numbers, with the smaller first
	cout <<"Please enter two integers with the smaller first: ";
	cin >>firstNum >>secondNum;		//read both integers into variables
	cout <<endl;

	i = firstNum;
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	
	//output the first statement before listing odd numbers
	cout <<"The odd numbers between " <<firstNum <<" and " 
	  	 <<secondNum <<" are: ";
	
	//while the first number remains less than the second number minus 2, 
	//continue the loop
	while (i < secondNum - 2)
	{
		//if the first number is even, add 1 to the number	
		if (i % 2 == 0)
			i++;
		//if the first number is odd, add 2 to the number	
		else             
			i += 2;
		
		//output the new number as the next odd number		
		cout <<i <<" ";			
		
		//square the new odd number and add to the sum of previous odd squares
		oddSquareSum += (i * i);	
	}
	cout <<endl <<endl;
	
	//reassign the loop control variable to equal the first number
	i = firstNum;
	
	//while the first number remains less than the second number plus 2, 
	//continue the loop
	while (i < secondNum + 2)
	{
 	 	//if the number is not even, add 1
		if (i % 2 != 0)
			i++;
		
		//add the number to the sum of previous even integers		
		evenIntSum += i;
		
		//increment i by 2
		i += 2;
	}
	//output the sum of all the even integers between the previously entered #'s
	cout <<"The sum of the even integers between " <<firstNum <<" and "
		 <<secondNum <<" is " <<evenIntSum <<endl <<endl;
	
	//while the loop control variable is less than or equal to 10, continue loop
	while (j <= 10)
	{
 	 	//output the number and its squared value
		cout <<j <<" squared = " <<j * j <<endl;
		//increment loop control variable by 1
		j++;
	}
	
	cout <<endl;
	//output the sum of the squares of the odd numbers
	cout <<"The sum of the squares of the odd numbers between " <<firstNum 
		 <<" and " <<secondNum <<" is " <<oddSquareSum <<"." <<endl <<endl;
	
	//output the statement before outputting the letters of the alphabet	 
	cout <<"The uppercase letters of the alphabet are: " <<endl;
	
	//while loop control variable is less than 26, continue loop
	while (k < 26)
	{
 	 	//if the output is supposed to be Z, output the word and
		if (static_cast<char>(k + 65) == 'Z')
			cout <<"and " <<static_cast<char>(k + 65) <<endl;
		//output the casted letter and a comma and space after it	
		else
			cout <<static_cast<char>(k + 65) <<", ";
		
		//increment loop control variable by 1
		k++;
	}
	
	system("pause");
	return 0;
}
