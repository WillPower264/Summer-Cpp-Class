//William Li
//CSC 133-GW
//Lab1c.cpp

#include <iostream>
using namespace std;

int main( )
{
	int item1;
	int item2;
	int item3;
	int total;
	int paid;
	int change;
	
	//read in the cost of the 3 items purchased
	
	cout <<"Please enter the cost of the first item: ";
	cin >>item1;
	
	cout <<"Please enter the cost of the second item: ";
	cin >>item2;
	
	cout <<"Please enter the cost of the third item: ";
	cin >>item3;
	
	//calculate the total cost of the items
	total = item1 + item2 + item3;
	
	//read in the amount paid
	cout <<"Please enter the amount paid: ";
	cin >>paid;
	
	//if not enough paid print error message
	if (paid < total)
 	   cout <<"Error: amount paid is not enough to cover the cost."
 	   		<<endl;
	else
	{
		//otherwise, calculate the change, then output the total cost,
		//the amount paid, and the change due
		change = paid - total;
		cout <<endl;
		cout <<"Total Cost: $" <<total <<endl;
		cout <<endl;
		cout <<"Amount Paid: $" <<paid <<endl;
		cout <<endl;
		cout <<"Your Change: $" <<change <<endl;
	}
	system ("pause");
	return 0;
}
