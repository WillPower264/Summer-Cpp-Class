/*William Li
CSC 133-GW
Lab8d.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;					//declare input stream variable
	ofstream fout;					//declare output stream variable
	
	fin.open("Lab8din.txt");		//open input stream variable
	fout.open("Lab8dout.txt");		//open output stream variable
	
	int num, iterations;			//declare variables for num and iterations
	
	//prompt user to enter the first number of the sequence
	cout <<"Please enter the first number of the sequence: ";
	fin >>num;						//read number into var num
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas

	//output the statement before listing the numbers in the sequence
	fout <<"The sequence is: " <<num;
	
	//while num is not 1, continue loop. increment k by 1 after each iteration
	//and assign the value of k into var iterations
	for (int k = 0; num != 1; k++, iterations = k)
	{
 	 	//if number is even, then divide by 2 for the next number
		if (num % 2 == 0)
		    num = num / 2;
		//if number is odd, then multiply by 3 and add 1
		else
  			num = 3 * num + 1;
  		
		//output the number with a space before it  	
  		fout <<" " <<num;
	}
	
	//output which place in the sequence the number 1 appeared
	fout <<"\n\nThe number 1 was the " <<iterations <<" number in the "
		 <<"sequence.";
		 
	fin.close();					//close input stream
	fout.close();	 				//close output stream
	
	system("pause");
	return 0;
}
