//William Li
//CSC 133-GW
//Lab1a.cpp

#include <iostream>
using namespace std;

int main ( )
{
	float hoursWorked;
	float hourlyPay;
	float weeklyPay;
	
	cout <<"Enter the number of hours worked: ";
	cin >> hoursWorked;
	
	cout <<"Enter the hourly pay rate: ";
	cin >> hourlyPay;
	
	weeklyPay = hourlyPay * hoursWorked;
	cout << "Weekly pay : $" <<weeklyPay;
	
	system("pause");
	return 0;
}
