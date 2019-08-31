/*William Li
CSC 133-GW
Lab6b.cpp*/

#include <iostream>
#include <locale>

using namespace std;

struct comma_facet : public std:: numpunct<char>		//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	int num1, num2, result;			//declare the 2 numbers as ints
	char operation;					//declare the operation as a char
	
	//prompt user to enter two integers and an operation
	cout <<"Please enter two integers and then the operation "
		 <<"you wish to accomplish: ";
	//reads the entered numbers as ints and	the operation as a char
	cin >>num1 >>num2 >>operation; 		
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas

	switch (operation)
	{
		case '+':		//if the char in operation is +, then find the sum
			result = num1 + num2;					//calculate sum
			cout <<"The sum of " <<num1 <<" and " <<num2 
				 <<" is " <<result <<".\n";			//output sum
			break;
		case '-':		//if the char in operation is -, then find the diff
			result = num1 - num2;					//calculate difference
			cout <<"The difference of " <<num1 <<" and " <<num2 
			 	  <<" is " <<result <<".\n";		//output difference
			break;	  
		case '*':		//if the char in operation is *, then find the product
			result = num1 * num2;					//calculate product
			cout <<"The product of " <<num1 <<" and " <<num2 
				  <<" is " <<result <<".\n";		//output product
			break;	  	  
		case '/':		//if the char in operation is /, then find the quotient
			if (num2 != 0) 	//to make sure there is no dividing by zero
   			{	
   				result = num1 / num2;				//calculate quotient
		   	 	cout <<"The quotient of " <<num1 <<" and " <<num2 
			 	  	 <<" is " <<result <<".\n";		//output quotient
   			}
   			else		//prompt error message if attempt to divide by zero
   				cout <<"Error. Can not divide by zero.\n";
			break;
		default:		//if input is faulty, prompt user to try again
			cout <<"Invalid input, rerun the program and try again.";
	}
	
	system("pause");
	return 0;
}
