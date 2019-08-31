/*William Li
CSC 133-GW
Lab11b.cpp*/

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 15;				//declare constant var ARRAY_SIZE to 15
	  
void initialize(int x[]);				//declare function prototypes
void printArray(const int x[]);
void smallestIndex(const int x[]);


int main()
{
	int array[ARRAY_SIZE];				//declare array of 15 integers
	
	initialize(array);					//call function initialize
	
	printArray(array);					//call function printArray
	
	smallestIndex(array);				//call function smallestIndex
	
	system("pause");
	return 0;
}

//function to initialize the array
void initialize(int x[])
{
	int temp;							//declare var temp as int
	
	//prompt user to enter a number
	cout <<"Please enter a number: ";
	cin >>x[0];							//read first number into first element
	
	//loop while i is less than the array size, and increment
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		//prompt user to enter another number
		cout <<"Please enter another number: ";
		
		//read next number into next element of array
		cin >>x[i];
	}
	cout <<endl;
}

//function to print out array
void printArray(const int x[])
{
	//output statement before outputting content
	cout <<"The numbers are: \n";
	
	//while i is less than the array size, output the element at the given index
	//and increment i
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout <<x[i] <<" ";
	cout <<endl <<endl;	
}

//function to find the index of the smallest element of an array
void smallestIndex(const int x[])
{
	int smallestIndex = 0;				//declare smallestIndex as in and set 0
	
	//while i is less than array size, loop and increment i
	for (int i = 1; i < ARRAY_SIZE; i++)
		//if the element at index i is less than the element at index 
		//smallesIndex, then assign i into smallesIndex
		if (x[smallestIndex] > x[i])
			smallestIndex = i;
	
	//output the smallest number using the index from smallestIndex and
	//output its position using smallestIndex + 1		
	cout <<"The smallest number is " <<x[smallestIndex] <<" and its index is "
		 <<smallestIndex <<"." <<endl;
}
