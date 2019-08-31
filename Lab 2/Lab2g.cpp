/*William Li
CSC 133-GW
Lab2g.cpp*/

#include <iostream>

using namespace std;

int main()
{
	double num;
	int num1;
	
	cout <<"Please enter a decimal number: ";
	cin >>num;
	
	num1 = static_cast<int>(num + 0.5);
	
	cout <<num <<" rounds to " <<num1 <<".\n";
	
	system("pause");
	return 0;
}
