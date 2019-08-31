/*William Li
CSC 133-GW
Lab3a.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	
	fin.open("Lab3ain.txt");
	fout.open("Lab3aout.txt");
	
	double num1, num2, num3, num4, num5, avg;
	
	cout <<"Please enter the five test scores: \n";
	fin >>num1 >>num2 >>num3 >>num4 >>num5;
	avg = (num1 + num2 + num3 + num4 + num5)/5.0;
	
	fout <<fixed <<showpoint <<setprecision(1);f
	fout <<"The test average of "<<num1 <<", "<<num2 <<", "<<num3 <<", "<<num4 
 		 <<", and "<<num5 <<" is " <<setprecision(3) <<avg <<".";
	
	fin.close();
	fout.close();
	
	system("pause");
	return 0;
}
