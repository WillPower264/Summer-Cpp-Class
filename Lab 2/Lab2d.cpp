/*William Li
CSC 133-GW
Lab2d.cpp*/

#include <iostream>										//a

using namespace std;									//b

int main()
{
	double num1,num2,num3,average;						//c
	num1=75.35;											//d
	num2=-35.56;
	num3=15.76;
	
	average= (num1 + num2 + num3)/3;					//e
	
	cout <<"Number 1 is: " <<num1 <<"\nNumber 2 is: " <<num2 
		 <<"\nNumber 3 is: " <<num3 <<"\nThe average of " <<num1 <<", " 
		 <<num2 <<", and " <<num3 <<" is: " <<average <<".\n";
	
	system("pause");
	return 0;	 
}
