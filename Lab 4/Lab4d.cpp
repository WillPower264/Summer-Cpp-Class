/*William Li
CSC 133-GW
Lab4d.cpp*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

struct comma_facet : public std:: numpunct<char>	//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;						//declare input stream variable
	ofstream fout;						//declare output stream variable
	
	fin.open("Ch3_Ex6Data.txt");		//open input stream
	fout.open("Ch3_EX6Output.txt");		//close input stream
	
	//declare strings for the first and last names of 3 people and doubles
	//for their salaries, increase percentages, and new salaries.
	string lastName1, firstName1, lastName2, firstName2, lastName3, firstName3;
	double salary1, salary2, salary3;
	double increase1, increase2, increase3;
	double newSalary1, newSalary2, newSalary3;
	
	//read the last names, first names, salaries, and increase percentages into
	//appropriate variables
	fin >>lastName1 >>firstName1 >>salary1 >>increase1 
		>>lastName2 >>firstName2 >>salary2 >>increase2
		>>lastName3 >>firstName3 >>salary3 >>increase3;
	
	//calculate new salaries for 3 people using current salary and increase %
	newSalary1 = salary1 * (1 + increase1/100);	
	newSalary2 = salary2 * (1 + increase2/100);	
	newSalary3 = salary3 * (1 + increase3/100);	
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) );	//to use commas
	fout <<fixed <<showpoint <<setprecision(2); //to show 2 significant digits
	//output the first name, last name, and new salary for each person
	fout <<firstName1 <<"\t" <<lastName1 <<"\t$" <<newSalary1 <<endl;
	fout <<firstName2 <<"\t" <<lastName2 <<"\t$" <<newSalary2 <<endl;
	fout <<firstName3 <<"\t" <<lastName3 <<"\t$" <<newSalary3 <<endl;

	fin.close();						//close input stream
	fout.close();						//close output stream
		
	system("pause");
	return 0;
}
