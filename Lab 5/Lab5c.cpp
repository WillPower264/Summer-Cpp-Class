/*William Li
CSC 133-GW
Lab5c.cpp*/

//This program takes a number between 0 and 35 and either returns the number
//if it is less than 10 or returns the number as a captital letter with 10 = A
//and so on.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;								//declare input stream variable 
	ofstream fout;								//declare output stream variable
	
	int num;									//declare number variable
	char ch;									//declare character variable
	
	fin.open("Lab5cin.txt");					//open input file
	fout.open("Lab5cout.txt");					//open output file
	
	fin >>num;							//read number from file into var num
	
	if (num <= 9)						//if num is less than 10, then output
	   fout <<num;
	
	if (num >= 10)								//if num is greater than 9
 	{
	   	ch = static_cast<char>(num + 55);	//cast number into letter and output
	   	fout <<"The number " <<num <<" turns into '" <<ch <<"'." <<endl;
	}
	   
	fin.close();								//close input file
	fout.close();   							//close output file
	
	system("pause");
	return 0;
}
