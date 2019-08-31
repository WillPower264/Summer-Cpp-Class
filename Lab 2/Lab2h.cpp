/*William Li
CSC 133-GW
Lab2h.cpp*/

#include <iostream>
#include <string>

using namespace std;

const int SECRET = 11;
const double RATE = 12.50;

int main()
{
	int num1,num2,newNum;
	string name;
	double hoursWorked, wages;
	
	cout <<"Please input two integers separated by a space: ";
	cin >>num1 >>num2;
	cout <<endl;
	
	cout <<"The value of num1 = " <<num1 <<" and the value of num2 = " <<num2
		 <<".\n";
		 
	newNum = num1 * 2 + num2;
	cout <<"The new number is " <<newNum <<".\n";
	
	newNum += SECRET;
	cout <<"Your new number, combined with our secret number is " <<newNum 
		 <<".\n";
		 
	cout <<"Please enter your last name: ";
	cin >>name;
	cout <<endl;
	
	cout <<"Please enter the number of hours worked (between 0 and 70): ";
	cin >>hoursWorked;
	cout <<endl;
	
	wages = RATE * hoursWorked;
	
	cout <<"Name: " <<name <<endl;
	cout <<"Pay Rate: $" <<RATE <<endl;
	cout <<"Hours Worked: " <<hoursWorked <<endl;
	cout <<"Salary: $" <<wages <<endl;
	
	system("pause");
	return 0;
}
