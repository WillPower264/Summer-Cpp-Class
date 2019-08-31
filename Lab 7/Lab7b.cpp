/*William Li
CSC 133-GW
Lab7b.cpp*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double pi = 0.0;					//declare pi as double and set to 0.0
	int i;								//declare i as a double
	long n;								//declare n as a long int
		 
	cout <<"Enter the value of n: ";	//prompt user to enter value of n
	cin >>n;							//read input into variable n
	
	for (i = 0; i < n; i++)				//loop for n amount of times
	{
		if (i % 2 == 0)						//if 1st, 3rd, 5th, 7th... input
			pi = pi + (1.0 / (2 * i + 1));	//add fractional expression to pi
		
		else								//if 2nd, 4th, 6th, 8th... input
			pi = pi - (1.0 / (2 * i + 1));	//subtract fractional expr from pi
	}
	
	pi = 4 * pi;						//multiply value of pi by 4 to find pi
	cout <<"pi = " <<pi <<endl <<endl;	//output the value of pi
	
	system("pause");
	return 0;
}
