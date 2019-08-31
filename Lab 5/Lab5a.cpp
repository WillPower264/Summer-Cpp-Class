/*William Li
CSC 133-GW
Lab5a.cpp*/

//This program receives a number and determines whether or not it is positive,
//negative, or zero

#include <iostream>

using namespace std;

int main()
{
	double num;
	
	cout <<"Please enter a number: ";				//enter number
	cin >>num;										//reads number into num
	cout <<endl;
	
	if (num > 0)									//determines positive #
	   cout <<"The number " <<num <<" is positive.\n";
	else if (num == 0)								//determines if # is zero
	   cout <<"The number " <<num <<" is zero.\n";
  	else
	   cout <<"The number " <<num <<" is negative.\n";	//determines negative #
   
	system("pause");
	return 0;
}
