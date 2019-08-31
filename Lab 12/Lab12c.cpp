/*William Li
CSC 133-GW
Lab12c.cpp*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int RUNNERS = 5;					//declare const int RUNNERS as 5
const int DAYS_IN_WEEK = 7;				//declare const in DAYS_IN_WEEK as 7

//declare function prototypes
void getData(string names[], int milesRun[][DAYS_IN_WEEK]);
void calculateTotal(double totalInWeek[], double average[], 
	 				int milesRun[][DAYS_IN_WEEK]);
void outputData(string names[], int milesRun[][DAYS_IN_WEEK], 
	    		double totalInWeek[], double average[]);


ifstream fin;							//declare input stream variable
ofstream fout;							//declare output stream variable

int main()
{
	fin.open("Lab12cin.txt");			//open input stream
	fout.open("Lab12cout.txt");			//open output stream
	
	string names[RUNNERS];				//declare array names size RUNNERS	
	//declare array milesRun size RUNNERS (rows) and DAYS_IN_WEEK (columns)
	int milesRun[RUNNERS][DAYS_IN_WEEK];
	double totalInWeek[RUNNERS];		//declare array totalInWeek size RUNNERS
	double average[RUNNERS];			//declare array average size RUNNERS
	
	getData(names, milesRun);			//call function getData
	
	//call function calculateTotal
	calculateTotal(totalInWeek, average, milesRun);	
	
	//call function outputData
	outputData(names, milesRun, totalInWeek, average);
		
	system("pause");
	return 0;
}

//function to get the datat from the input stream
void getData (string names[], int milesRun[][DAYS_IN_WEEK])
{
	//while i is less than RUNNERS, loop and increment i
	for (int i = 0; i < RUNNERS; i++)
	{
		//read input into array names at index i
		fin >>names[i];
		
		//while j is less than DAYS_IN_WEEK, loop and increment j
		for (int j = 0; j < DAYS_IN_WEEK; j++)
			//read input into array milesRun at index i,j
			fin >>milesRun[i][j];
	}
}

//functino to calculate the total amount of miles run in a week
void calculateTotal(double totalInWeek[], double average[], 
	 				int milesRun[][DAYS_IN_WEEK])
{
	//while i is less than RUNNERS, loop and increment i
	for (int i = 0; i < RUNNERS; i++)
	{
		double sum = 0.0;				//declare double var sum set to 0.0
		
		//while j is less than DAYS_IN_WEEK, loop and increment j
		for (int j = 0; j < DAYS_IN_WEEK; j++)
			//add the element in milesRun indicate by the indices to sum
			sum += milesRun[i][j];
		
		//assign element in parallel array totalInWeek the value of sum
		totalInWeek[i] = sum;
		//assign element in parallel array average the value of sum/DAYS_IN_WEEK
		average[i] = sum / DAYS_IN_WEEK;
	}
}

//function to output data
void outputData(string names[], int milesRun[][DAYS_IN_WEEK], 
	    		double totalInWeek[], double average[])
{
	//output headers
	fout <<"Name   \t\tMon\tTues\tWed\tThur\tFri"
		 <<"\tSat\tSun \tTotal\t  Average" <<endl;
	
	//while i is less than RUNNERS, loop and increment i
	for (int i = 0; i < RUNNERS; i++)
	{
		fout <<endl;
		
		//output each name in stored in array names
		fout <<names[i] <<"    \t";
		
		//format output to 3 sig digits
		fout <<fixed <<showpoint <<setprecision(3);
		
		//while j is less than DAYS_IN_WEEK, loop and increment j
		for (int j = 0; j < DAYS_IN_WEEK; j++)
			//output the components of milesRun
			fout <<milesRun[i][j] <<"\t";
		
		//output the total amount of miles run in a week, followed by average
		fout <<totalInWeek[i] <<"\t  " <<average[i];
	}
}	    		
