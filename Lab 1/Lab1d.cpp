//William Li
//CSC 133-GW
//Lab1d.cpp

//This program reads the hours worked during a week and the hourly pay rate
//and calculates the weekly pay
#include <iomanip>
#include <iostream>
using namespace std;

int main( )
{
	float hoursWorked;
	float hourlyPay;
	float grossPay;
	float taxes;
	float takeHomePay;
	
	//read the input values
	cout <<"Enter the number of hours worked: ";
	cin >>hoursWorked;
	
	cout <<"Enter the hourly pay rate: ";
	cin >>hourlyPay;
	
	//calculate the pay before taxes (gross pay), taxes, and take home pay
	grossPay = hourlyPay * hoursWorked;
	taxes = grossPay * .05;
	takeHomePay = grossPay - taxes;
	
	//set up output so float variable prints with 2 decimal places
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout <<setprecision(2);
	
	//print gross pay, taxes, and take home pay
	
	cout <<endl;
	cout <<"Gross Pay: $" <<grossPay <<endl;
	cout <<"Taxes: $" <<taxes <<endl;
	cout <<"Take Home Pay: $" <<takeHomePay <<endl;
	
	system("pause");
	return 0;	
}
