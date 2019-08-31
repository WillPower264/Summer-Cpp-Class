//William Li
//CSC 133-GW
//Lab1b.cpp

#include <iostream>
using namespace std;

const int LBS = 10;

int main( )
{
	int price;
	int cost;
	char ch;
	
	price = 30;
	cost = price * LBS;
	
	ch = 'A';
	
	cout <<"Cost is " <<endl;
	cout <<cost << endl;
	
	cout <<"Price is " <<price <<" Cost is " <<cost <<endl;
	cout <<"Grade " <<ch <<" costs " <<endl;
	cout <<cost  <<endl;
	
	system("pause");
	return 0;
}
