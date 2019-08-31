//William Li
//CSC 133-GW
//Lab1e.cpp

#include <iostream>
using namespace std;

const bool NO = false; //defines NO to false
const bool YES = true; //defines YES to true

void welcome( );
int main( )
{
	bool answer; //variable answer declared as type boolean
	
	cout <<"Do you want to see a welcome message?\n";
	cout <<"Enter 0 for NO, 1 for YES - and then press return ";
	cin >> answer;
	
	if (answer == YES)
	   welcome( ); //call the function called welcome
	else
		cout <<"Goodbye for now.\n";
		
system("pause");
return 0;
}

void welcome( )
{
 	 cout <<"Welcome to CSC 133 - Intro to C++ Programming\n";
}
