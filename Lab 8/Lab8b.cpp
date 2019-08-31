/*William Li
CSC 133-GW
Lab8b.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;						//declare input stream variable
	ofstream fout;						//declare output stream variable
	
	fin.open("Lab8bin.txt");			//open input stream
	fout.open("Lab8bout.txt");			//open output stream
	
	//declare int variables for the first and second number
	int firstNum, secondNum;
	//declare double variables for sum of the odd squares and sum of 
 	//the even numbers			
	double oddSquareSum = 0.0, evenIntSum = 0.0;
	
	//prompt user to enter two numbers, with the smaller first
	cout <<"Please enter two integers with the smallest first: ";
	fin >>firstNum >>secondNum;			//read both integers into variables
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	
	//output the first statement before listing odd numbers
	fout <<"The odd numbers between " <<firstNum <<" and " 
	  	 <<secondNum <<" are: ";

	//while the first number remains less than the second number minus 2, 
	//continue the loop	 
	for (int i = firstNum; i < secondNum - 2;)
	{
		//if the first number is even, add 1 to the number
		if (i % 2 == 0)
			i++;
		//if the first number is odd, add 2 to the number	
		else             
			i += 2;
		
		//output the new number as the next odd number		
		fout <<i <<" ";			
		
		//square the new odd number and add to the sum of previous odd squares
		oddSquareSum += (i * i);		
	}
	fout <<endl <<endl;
	
	//while the first number remains less than the second number minus 2, 
	//continue the loop
	for (int i = firstNum; i < secondNum + 2;)
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
	fout <<"The sum of the even integers between " <<firstNum <<" and "
		 <<secondNum <<" is " <<evenIntSum;
	fout <<endl <<endl;
	
	//while the loop control variable is less than or equal to 10, continue loop
	for (int j = 1; j <= 10; j++)
		//output the number and its squared value
		fout <<j <<" squared = " <<j * j <<endl <<endl;
	
	//output the sum of the squares of the odd numbers
	fout <<"The sum of the squares of the odd numbers between " <<firstNum 
		 <<" and " <<secondNum <<" is " <<oddSquareSum <<"." <<endl <<endl;
	
	//output the statement before outputting the letters of the alphabet	 
	fout <<"The uppercase letters of the alphabet are: \n";
	
	//while loop control variable is less than 26, continue loop
	for (int k = 0; k < 26; k++)
	{
	 	//if the output is supposed to be Z, output the word and
		if (static_cast<char>(k + 65) == 'Z')
			fout <<"and " <<static_cast<char>(k + 65) <<endl;
		//output the casted letter and a comma and space after it	
		else
			fout <<static_cast<char>(k + 65) <<", ";
	}
	
	fin.close();						//close input stream
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}
