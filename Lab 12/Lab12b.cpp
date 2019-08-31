/*William Li
CSC 133-GW
Lab12b.cpp*/

#include <iostream>
#include <iomanip>

using namespace std;

const int EXTREMES = 2;					//declare const int EXTREMES to 2
const int MONTHS = 12;					//declare const int MONTHS to 12

void getData(int temps[][MONTHS]);		//declare function prototypes
double averageHigh(int temps[][MONTHS]);
double averageLow(int temps[][MONTHS]);
int indexHighTemp(int temps[][MONTHS]);
int indexLowTemp(int temps[][MONTHS]);
void outputData(double averageHighTemp, double averageLowTemp, 
				int highestIndex, int lowestIndex, int temps[][MONTHS]);

int main()
{
	//declare array temps with EXTREMES rows and MONTHS columns
	int temps [EXTREMES][MONTHS];		
	getData(temps);						//call function getData
	
	//assign value returned from averageHigh into double averageHighTemp
	double averageHighTemp = averageHigh(temps);
	
	//assign value returned from averageLow into double averageLowTemp
	double averageLowTemp = averageLow(temps); 

	//assign value returned from indexHighTemp into int highestIndex
	int highestIndex = indexHighTemp(temps);
	
	//assign value returned from indexLowTemp into int lowestIndex
	int lowestIndex = indexLowTemp(temps);
	
	//call function outputData
	outputData(averageHighTemp, averageLowTemp, 
			   highestIndex, lowestIndex, temps);
	
	system("pause");
	return 0;
}

//function to get data and store in array
void getData(int temps[][MONTHS])
{
	//while i is less than EXTREMES, loop and increment i
	for(int i = 0; i < EXTREMES; i++)
	{
		//i = 0 when entering highest temperatures
		if (i == 0)
		   //prompt user to enter the highest temperatures for each month
			cout <<"Please enter the highest temperatures each month "
				 <<"for this year: " <<endl;
		//i = 1 when entering lowest temperatures
		else
			//prompt user to enter the lowest temperatures for each month
			cout <<"Please enter the lowest temperatures each month "
				 <<"for this year: " <<endl;
		
		//while j is less than MONTHS, loop and increment j		 
		for(int j = 0; j < MONTHS; j++)
			//read input into array temps
			cin >>temps[i][j];
	}
}

//function to find the average high temp
double averageHigh(int temps[][MONTHS])
{
	int i = 0;							//declare int var i and set to 0
	double sum = 0.0;					//declare double var sum and set to 0.0
	
	//while j is less than MONTHS, loop and increment j		 
	for (int j = 0; j < MONTHS; j++)
		//add the element in temps to var sum
		sum += temps[i][j];
	
	//return sum divided by MONTHS, which is the average, to main
	return sum / MONTHS;
}

double averageLow(int temps[][MONTHS])
{
	int i = 1;							//declare int var i and set to 1
	double sum = 0.0;					//declare double var sum and set to 0.0
	
	//while j is less than MONTHS, loop and increment j
	for (int j = 0; j < MONTHS; j++)
		//add the element in temps to var sum
		sum += temps[i][j];
	
	//return sum divided by MONTHS, which is the average, to main
	return sum / MONTHS;
}

//function to find the index of the highest temperature of the data set
int indexHighTemp(int temps[][MONTHS])
{
	int i = 0;							//declare int var i and set to 0
	int indexHighest = 0;				//declare int indexHighest and set to 0
	
	//while j is less than MONTHS, loop and increment j
	for (int j = 1; j < MONTHS; j++)
		//if the temperature at indexHighest is less than the temperature at 
		//index j, assign j's value into indexHighest
		if (temps[i][indexHighest] < temps[i][j])
			indexHighest = j;
	
	//return indexHighest back to main
	return indexHighest;		
}

int indexLowTemp(int temps[][MONTHS])
{
	int i = 1;							//declare int var i and set to 1
	int indexLowest = 0;				//declare int indexLowest and set to 0
	
	//while j is less than MONTHS, loop and increment j
	for (int j = 1; j < MONTHS; j++)
		//if the temperature at indexLowest is greater than the temperature at 
		//index j, assign j's value into indexLowest
		if (temps[i][indexLowest] > temps[i][j])
			indexLowest = j;
	
	//return indexLowest back to main
	return indexLowest;
}

//function to output the data
void outputData(double averageHighTemp, double averageLowTemp, 
				int highestIndex, int lowestIndex, int temps[][MONTHS])
{
	//format output to show 3 sig digits
	cout <<fixed <<showpoint <<setprecision(3) <<endl;
	
	//output the average high temperature of the year
	cout <<"The average high temperature for the year was:\t" 
		 <<averageHighTemp  <<" degrees"<<endl;
	//output the average low temperature of the year	 
	cout <<"The average low temperature of the year was:  \t" 
		 <<averageLowTemp <<" degrees"<<endl <<endl;
	//output the highest temperature	 
	cout <<"The highest temperature is: " <<temps[0][highestIndex]
		 <<" degrees" <<endl;
	//output the lowest temperature	 
	cout <<"The lowest temperature is: " <<temps[1][lowestIndex] 
		 <<" degrees" <<endl <<endl;
}			
