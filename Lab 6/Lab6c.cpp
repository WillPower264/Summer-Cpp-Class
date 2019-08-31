/*William Li
CSC 133-GW
Lab6c.cpp*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;					//declare input stream variable
	ofstream fout;					//declare output stream variable
	
	fin.open("Lab6cin.txt");		//open input stream
	fout.open("Lab6cout.txt");		//open output stream
	
	float num1, num2, result;		//declare the 2 numbers as ints
	char operation;					//declare the operation as a char
	
	//prompt user to enter two integers and an operation
	cout <<"Please enter two integers and then the operation "
		 <<"you wish to accomplish: ";
	//reads the entered numbers as ints and	the operation as a char
	fin >>num1 >>num2 >>operation; 		
	
	fout <<fixed <<showpoint <<setprecision(2);
	switch (operation)
	{
		case '+':		//if the char in operation is +, then calculate sum
			result = num1 + num2;
			fout <<"The sum of " <<num1 <<" and " <<num2 
				 <<" is " <<result <<".\n";			//output sum
			break;
		case '-':		//if the char in operation is -, then calulate diff
			result = num1 - num2;
			fout <<"The difference of " <<num1 <<" and " <<num2 
			 	  <<" is " <<result <<".\n";		//output difference
			break;	  
		case '*':		//if the char in operation is *, then calculate product
			result = num1 * num2;
			fout <<"The product of " <<num1 <<" and " <<num2 
				  <<" is " <<result <<".\n";		//output product
			break;	  	  
		case '/':		//if the char in operation is /, then calculate quotient
			result = num1 / num2;
			fout <<"The quotient of " <<num1 <<" and " <<num2 
			 	  <<" is " <<result <<".\n";		//output quotient
			break;
		default:		//if input is faulty, prompts user to try again
			fout <<"Invalid input, rerun the program and try again.";
	}
	
	fin.close();			//close input stream
	fout.close();			//close output stream
	
	system("pause");
	return 0;
}
