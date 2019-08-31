/*William Li
CSC 133-GW
Lab2f.cpp*/

#include <iostream>												//a
#include <string>

using namespace std;											//b

int main()
{
	string name;
	double studyHours;
	
	cout <<"Enter your name here: ";
	cin >>name;
	
	cout <<"Enter the number of hours you need to study here: ";
	cin >>studyHours;
	
	cout <<"Hello, " <<name <<"! On Saturday, you need to study "
		 <<studyHours <<" hours for the exam.\n";
		 
	system("pause");
	return 0;	 
	
}
