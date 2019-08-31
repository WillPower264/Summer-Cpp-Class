/*William Li
CSC 133-GW
Lab5b.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;						//declare input stream variable
	ofstream fout;						//declare output stream variable
	
	fin.open("Lab5bin.txt");			//open input file
	fout.open("Lab5bout.txt");			//open output file
							  
	int num1, num2, num3;				//declare number variables
	int first, second, third;			//declare variables of sequenced numbers
	
	fin >>num1 >>num2 >>num3;			//reads the numbers from file into var
	
	if (num1 < num2 && num1 < num3) 		
	   first = num1;					//determines if num1 is the smallest
	else if (num2 < num1 && num2 < num3)
	   first = num2;					//determines if num2 is the smallest
	else
	   first = num3;					//determines if num3 is the smallest
	   
	if (first == num1)					//If num1 is the smallest...
	   if (num2 < num3)					
	   	  second = num2;				//determines if num2 is the middle #
	   else
	   	   second = num3;  				//determines if num3 is the middle #

	if (first == num2)					//If num2 is the smallest...
	   if (num1 < num3)
	   	  second = num1;				//determines if num1 is the middle #
	   else
	   	   second = num3;				//determines if num3 is the middle #
			  
	if (first == num3)					//If num3 is the smallest...
	   if (num1 < num2)
	   	  second = num1;				//determines if num1 is the middle #
	   else
	   	   second = num2;				//determines if num2 is the middle #
	
	//if num1 is the smallest and num2 is the middle, then num3 is the largest		  
	if (first == num1 && second == num2)
	   third = num3;	  	

	//if num1 is the smallest and num3 is the middle, then num2 is the largest		  
	else if (first == num1 && second == num3)
	   third = num2;
	
	//if num2 is the smallest and num1 is the middle, then num3 is the largest		  
	else if (first == num2 && second == num1)
	   third = num3;
	
	//if num2 is the smallest and num3 is the middle, then num1 is the largest		  
	else if (first == num2 && second == num3)
	   third = num1;

	//if num3 is the smallest and num1 is the middle, then num2 is the largest		  
	else if (first == num3 && second == num1)
	   third = num2;	
	
	//if num3 is the smallest and num2 is the middle, then num1 is the largest		  
	else if (first == num3 && second == num2)
	   third = num1;

	//displays the ascending order of the three numbers	   
	fout <<"The ascending order of " <<num1 <<", " <<num2 <<", and " <<num3
		 <<" is " <<first <<", " <<second <<", and " <<third <<".";
	
	fin.close();					//close input file
	fout.close();					//close output file
	   
	system("pause");
	return 0;
}
