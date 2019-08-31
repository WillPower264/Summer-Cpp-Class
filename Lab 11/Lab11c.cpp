/*William Li
CSC 133-GW
Lab11c.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

const int ARRAY_SIZE = 26;				//declare constant var ARRAY_SIZE to 26

void readData(int x[]);					//declare function prototypes
void printScores(int x[]);

ifstream fin;							//declare input stream variable
ofstream fout;							//declare output stream variable

int main()
{
	fin.open("Lab11cin.txt");			//open input stream
	fout.open("Lab11cout.txt");			//open output stream
	
	//declare array testScores with given array size and initialize all to 0
	int testScores[ARRAY_SIZE] = {0};	
	
	readData(testScores);				//call function readData and pass array
	
	printScores(testScores);		 //call function printScores and pass array
	
	system("pause");
	return 0;
}

//function to read the input data to array
void readData(int x[])
{
	//while i is less than the array size, loop and increment
	for (int i = 0; i < ARRAY_SIZE; i++)
		//read in number and enter into array using index
		fin >>x[i];
}

//function to print out scores
void printScores(int x[])
{
	int range[8] = {0};	  //declare array range with 8 elements and initialize 0
	
	//while i is less than the array size, loop and increment
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		//set up switch structure to read the value of the element divided by 25
		switch ((x[i])/ 25)
		{
			//if the quotient is 0, add 1 to the 1st element in array range
			case 0:
				range[0] += 1;
				break;
			
			//if the quotient is 1, add 1 to the 2nd element in array range	
			case 1:
				range[1] += 1;
				break;
			
			//if the quotient is 2, add 1 to the 3rd element in array range		
			case 2:
				range[2] += 1;
				break;
			
			//if the quotient is 3, add 1 to the 4th element in array range		
			case 3:
				range[3] += 1;
				break;
			
			//if the quotient is 4, add 1 to the 5th element in array range		
			case 4:
				range[4] += 1;
				break;
				
			//if the quotient is 5, add 1 to the 6th element in array range		
			case 5:
				range[5] += 1;
				break;
				
			//if the quotient is 4, add 1 to the 7th element in array range		
			case 6:
				range[6] += 1;
				break;
				
			//if the quotient is 7 or 8, add 1 to the 8th element in array range		
			case 7: case 8:
				range[7] += 1;
				break;
				
			//if the quotient is not between 0 and 8, inclusive, then break	
			default:
				break;
		} 
	}
	
	//output the header of the output
	fout <<"Out of the " <<ARRAY_SIZE <<" students, the scores are "
		 <<"distributed as shown: " <<endl <<endl;
	
	//output the score range and the number of students who scored inside each	 
	fout <<"0 - 24:\t\t" <<range[0] <<endl;
	fout <<"25 - 49:\t" <<range[1] <<endl;
	fout <<"50 - 74:\t" <<range[2] <<endl;
	fout <<"75 - 99:\t" <<range[3] <<endl;
	fout <<"100 - 124:\t" <<range[4] <<endl;
	fout <<"125 - 149:\t" <<range[5] <<endl;
	fout <<"150 - 174:\t" <<range[6] <<endl;
	fout <<"175 - 200:\t" <<range[7] <<endl;
		 
}
