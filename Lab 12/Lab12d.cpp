/*William Li
CSC 133-GW
Lab12d.cpp*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int WORKERS = 10;					//declare const int WORKERS set to 10

//declare function prototypes
void getData(string names[], double salaries[][3]);
void calculateSalary(double salaries[][3]);
double calculateAvgSalary(const double salaries[][3]);
void findGreaterThanAvg(const string names[], const double salaries[][3], 
	 					double averageSalary, string higherPaid[]);
void outputData(const string names[], const double salaries[][3], 
	 			double averageSalary, string higherPaid[]);

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

ifstream fin;							//declare input stream variable
ofstream fout;							//declare output stream variable

int main()
{
	fin.open("Lab12din.txt");			//open input stream
	fout.open("Lab12dout.txt");			//open output stream
	
	string names[WORKERS];				//declare array names size WORKERS
	//declare array salaries size WORKERS (rows) and 3 (columns)
	double salaries[WORKERS][3];		
	string higherPaid[WORKERS];			//declare array higherPaid size WORKERS
	
	getData(names, salaries);			//call function getData
	
	calculateSalary(salaries);			//call function calculateSalary
	
	//assign value returned from caclulateAvgSalary into double averageSalary
	double averageSalary = calculateAvgSalary(salaries);
	
	//call function findGreaterThanAvg
	findGreaterThanAvg(names, salaries, averageSalary, higherPaid);
	
	//call function to output data
	outputData(names, salaries, averageSalary, higherPaid);
	
	system("pause");
	return 0;
}

//functino to get data from input stream
void getData(string names[], double salaries[][3])
{
	//while i is less than WORKERS, loop and increment i
	for (int i = 0; i < WORKERS; i++)
	{
		//read names into the array names at index i
		fin >>names[i];
		
		//while j is less than 2 (to access hours and pay rate), 
		//loop and increment j
		for (int j = 0; j < 2; j++)
			//read  hours worked and hourly pay rate into array salaries
			fin >>salaries[i][j];
	}
}

//function to calculate the weekly salary of each person
void calculateSalary(double salaries[][3])
{
	//while i is less than WORKERS, loop and increment i
	for (int i = 0; i < WORKERS; i++)
	{
		//if the worker works less than or equal to 40 hours
		if (salaries[i][0] <= 40)
		   //salary = hours * pay rate
  		    salaries[i][2] = salaries[i][0] * salaries[i][1];
  		//if the worker had worked overtime    
		else
			//salary = 40 * pay rate + extra hours * pay rate * 1.5		
			salaries[i][2] = (salaries[i][0] - 40) * (salaries[i][1] * 1.5) + 
						   	  (40 * salaries[i][1]);
	}
}

//function to calculate the average salary of everyone
double calculateAvgSalary(const double salaries[][3])
{
	double total = 0.0;					//declare double total and set to 0.0
	
	//while i is less than WORKERS, loop and increment i
	for (int i = 0; i < WORKERS; i++)
		//add the salary to total
		total += salaries[i][2];
		
	//return the total divided by WORKERS (the average) back to main
	return total / WORKERS;	
}

//function to find who earns more than average
void findGreaterThanAvg(const string names[], const double salaries[][3], 
	 					double averageSalary, string higherPaid[])
{
	//while i is less than WORKERS, loop and increment i
	for (int i = 0; i < WORKERS; i++)
	{
		higherPaid[i] = "no";			//set element to "no"
  		//if one's salary is higher than average
		if (salaries[i][2] >= averageSalary)
		   //change element from "no" to the name of the person
		   higherPaid[i] = names[i];
	}
}

//function to output the data
void outputData(const string names[], const double salaries[][3], 
	 			double averageSalary, string higherPaid[])
{
	//output headers
	fout <<"Name   \t\tHours \t\tHourly Pay \tWeekly Salary" <<endl <<endl;
	
	//format output to show 2 sig digits
	fout <<fixed <<showpoint <<setprecision(2);
	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	
	//while i is less than WORKERS, loop and increment i
	for (int i = 0; i < WORKERS; i++)
	{
		//output each name
		fout <<names[i] <<"   \t";
		
		//while j is less than 3 (to access hours, pay rate, and salary), 
		//loop and increment j
		for (int j = 0; j < 3; j++)
		{
			//if outputting the second or third columns, then output '$'
	 	 	if (j == 1 || j == 2)
	 	 	   fout <<"$";
 	   		
 	   		//output the hours worked, hourly pay, and weekly salary
			fout <<salaries[i][j] <<"\t\t";
		}	
		fout <<endl;	
	}
	fout <<endl;
	
	//output the average weekly salary
	fout <<"The average weekly salary is: $" <<averageSalary <<endl;
	
	//while i is less than WORKERS, loop and increment i
	for (int i = 0; i < (WORKERS); i++)
		//if the element in higherPaid is changed from "no"
		if (higherPaid[i] != "no")
		   //output the name stored and a space
		   fout <<higherPaid[i] <<" ";
		   
	//output statement 	   
	fout <<"have salaries greater than the average weekly salary.";
}
