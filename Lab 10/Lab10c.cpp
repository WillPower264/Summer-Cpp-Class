/*William Li
CSC 133-GW
Lab10c.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

void digitCount(long long, int&, int&, int&);	//declare function prototypes
long long inputNumber();
void outputResults();

ifstream fin;							//declare input stream variable
ofstream fout;							//declare output stream variable
	
//declare num as a long long
long long num;						
//declare even, odd, and zero to keep track of occurences and set to 0
int even, odd, zero;	
	
int main()
{
	fin.open("Lab10cin.txt");			//open input stream
	fout.open("Lab10cout.txt");			//open output stream
	
	num = inputNumber();
	
	//call function digitCount with actual parameters num, even, odd, and zero
	digitCount(num, even, odd, zero);
	
	outputResults();					//call function outputResults
	
	fin.close();						//close input stream
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}

//function to return number read from file
long long inputNumber()
{
	fin >>num;							//read number into num from file
	
	return num;							//return num to function call
}


//function to count number of even digits, odd digits, and zero's
void digitCount(long long number, int& evenDigit, int& oddDigit, int& zeroDigit)
{
	int digit;							//declare digits as an int
	
	//continue loop while number is greater than or equal to 1
	while (number >= 1)
	{
		//calculate a digit and reduce number each iteration
		digit = number % 10;
		number = number / 10;
		
		//set switch structure to read the value of digit
		switch (digit)
		{
			//if zero, add 1 to zeroDigit
			case 0:				
				zeroDigit += 1;
				break;
			
			//if 1, 3, 5, 7, or 9, add 1 to oddDigit	
			case 1: case 3: case 5: case 7: case 9:
				oddDigit += 1;
				break;
				
			//if 2, 4, 6, or 8, add 1 to evenDigit	
			case 2: case 4: case 6: case 8:
				evenDigit += 1;
				break;
		}
	}
}

//function to output results
void outputResults()
{
 	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	
	//output number
	fout <<"The number " <<num <<" has: " <<endl <<endl;
	
	//output number of even digits
	fout <<"Even digits: \t" <<even <<endl;
	//output the number of odd digits
	fout <<"Odd digits: \t" <<odd <<endl;
	//output the number of zeroes
	fout <<"Zeroes: \t" <<zero <<endl <<endl;
}
