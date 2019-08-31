/*William Li
CSC 133-GW
Lab7a.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	ifstream fin;						//declare input stream variable
	ofstream fout;						//declare output stream variable

	fin.open("Lab7ain.txt");			//open input stream
	fout.open("Lab7aout.txt");			//open output stream
	
	int num, digit, i;					//declare num as a int
	string strNum;						//declare strNum as a string
	double sum = 0.0;					//declare sum as a double and set to 0.0
	
	cout <<"Please input a number: ";	//prompt user to enter a number
	fin >>num;							//read number from file into num
	
	fin.close();						//close input stream
	fin.open("Lab7ain.txt");			//reopen input stream
	fin >>strNum;						//read number as a string from file
	
	fout <<fixed <<showpoint <<setprecision(2);	//format output to 2 sig digits
	fout <<"The sum of the digits ";	//output a statement before digits
	
	if (num < 0)						//if entered number is negative
	   num = -num;						//ignore the '-' sign and read next char
	
	i = strNum.length() - 1; //assign loop control variable length of string - 1
	while (i >= 0)			 //continue loop while loop control variable is > 0
	{
		//assign digit to value of number divided by 10 to the power of the 
		//number's length minus 1
		digit = num / pow(10, i);		
		//update value of num to eliminate the first digit
		num = num - (digit * pow(10,i));
		
		//output digit and a space
		fout <<digit <<" ";	
	 	
		//update loop control variable
		i--;
		
		sum = sum + digit;					//add digit to the sum
		fin >>num;							//read next char
	}
	
	fout <<"is "<<sum <<".";			//output the sum of digits
	
	fin.close();						//close input stream
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}
