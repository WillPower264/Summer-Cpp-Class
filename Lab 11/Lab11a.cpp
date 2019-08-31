/*William Li
CSC 133-GW
Lab11a.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void initialize();						//declare function prototypes
void print();

ofstream fout;							//declare output stream variable

const int ARRAY_SIZE = 50;				//declare const array size to 50

double alpha[ARRAY_SIZE];	//declare array alpha with 50 type double components

int main()
{
	fout.open("Lab11aout.txt");			//open output stream
	
	initialize();						//call void function initialize
	print();							//call void function print
	
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}

//function to initialize the values in an array
void initialize()
{
	//while i is less than the array size, loop and increment
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		//if the index is less than half the array size, assign the value of 
		//the index squared to the element indicated by the index
		if (i < (ARRAY_SIZE / 2))
		    alpha[i] = i * i;
		//if the index is less than half the array size, assign the value of 
		//the index times 3 to the element indicated by the index
		else
			alpha[i] = 3 * i;   
	}
}

//functino to print out the components of an array
void print()
{
	//format output so that doubles show 3 sig digits
	fout <<fixed <<showpoint <<setprecision(3);
	//output statement before listing components
	fout <<"The components of the array are: " <<endl;
	
	//while i is less than array size, loop and increment
	for (int i = 0; i < (ARRAY_SIZE); i++)
	{
		//output the element in array alpha at index i and a space after
		fout <<alpha[i] <<" ";
		
		//if the index ends in a 9, go to the next line
		if (i % 10 == 9)
		   fout <<endl;
	}
}
