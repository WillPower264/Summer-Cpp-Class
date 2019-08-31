/*William Li
CSC 133-GW
Lab7d.cpp*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{	
	int num;							//declare var num as int
	double evenSum = 0.0, oddSum = 0.0;		//declare even sum and odd sum as 0.0
	
	//prompt user to enter a group of integers
	cout <<"Please enter a group of integers ending with 0: ";
	
	cin >>num;					//read first number into var num
	cout <<endl;
	
	for (;num != 0;)
	{
		if (num % 2 == 0) 		//if # is even add to even sum
			evenSum += num;		
		else					//if # is odd add to odd sum
			oddSum += num;
		
		cin >>num;				//read next number
	}
 
 	//format output to 2 significant digits
	cout <<fixed <<showpoint <<setprecision(2);
	
	//output the sum of all odd numbers
	cout <<"The sum of all the odd numbers is " <<oddSum <<"." <<endl;
	//output the sum of all even numbers
	cout <<"The sum of all the even numbers is " <<evenSum <<"." <<endl;
	
	system("pause");
	return 0;
}
