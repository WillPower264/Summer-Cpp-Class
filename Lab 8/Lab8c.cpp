/*William Li
CSC 133-GW
Lab8c.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;							//declare input stream variable
	ofstream fout;							//declare output stream variable
	
	fin.open("Lab8cin.txt");				//open input stream
	fout.open("Lab8cout.txt");				//open output stream
	
	int populationA, populationB;			//declare variables for populations
	double growthA, growthB;				//declare variables for growth rate
	int years = 0;							//declare variable year and set to 0
	
	//prompt user to enter the population of town A
	cout <<"Please enter the population of town A: ";
	fin >>populationA; 						//read population into variable
	cout <<endl;
	
	//prompt user to enter the population of town B
	cout <<"Please enter the population of town B: ";
	fin >>populationB; 						//read population into variable
	cout <<endl;
	
	//prompt user to enter the growth rate of town A
	cout <<"Please enter the growth rate of town A (%): ";
	fin >>growthA; 							//read growth rate into variable
	cout <<endl;
	
	//prompt user to enter the growth rate of town B
	cout <<"Please enter the growth rate of town B (%): ";
	fin >>growthB;							//read growth rate into variable
	cout <<endl;
	
	//while the population of town A is less than the population of town B,
	//continue loop
	while (populationA < populationB)
 	{
  	 	//calculate the new populations of each town after a year
 		populationA *= (1 + growthA/100);
 		populationB *= (1 + growthB/100);
 		//increment variable year by 1 to keep track of years passed
 		years++;
 	}
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas

	//output the number of years it will take for townA to be larger than townB
	fout <<"In " <<years <<" years, the population of town A will be equal to "
		 <<"or greater than the population of town B." <<endl;
	//output the populations of town A and B in the year when town A is larger 
	//than town B
	fout <<"Town A will have a population of " <<populationA <<" people." <<endl
		 <<"Town B will have a population of " <<populationB <<" people.";
	
	system("pause");
	return 0;
}
