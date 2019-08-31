/*William Li
CSC 133-GW
Lab3b.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	double num1, num2, num3, num4, num5, sum;
	
	fin.open("Lab3bin.txt");
	fout.open("Lab3bout.txt");
	
	cout <<"Please enter 5 decimal numbers: \n";
	fin >>num1 >>num2 >>num3 >>num4 >>num5;
	
	sum = num1 + num2 + num3 + num4 +num5;
	
	fout <<fixed <<showpoint <<setprecision(1);
	fout <<"The sum of " <<num1 <<", "<<num2 <<", "<<num3 <<", "<<num4 
 		 <<", and "<<num5 <<" is " <<setprecision(3) <<sum <<".\n";
 	fout <<"Also, the average of " <<setprecision(1) <<num1 <<", "<<num2 
	 	 <<", "<<num3 <<", "<<num4 <<", and " <<num5 <<" is " 
  		 <<setprecision(3) <<(num1 + num2 + num3 + num4 + num5)/5;
	
	system("pause");
	return 0;
}
