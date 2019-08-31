/*William Li
CSC 133-GW
Lab4a.cpp*/

#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct comma_facet : public std:: numpunct<char>		//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream inFile;								//declare input stream var
	ofstream outFile;								//declare output stream var
	
	inFile.open("inData.txt");						//open input stream
	outFile.open("outData.txt");					//open output stream
	
	//declare strings for first name, last name, and department
	string firstName, lastName, department;			
	//declare num var for monthly gross salary, bonus, tax rate and paycheck
	double monthlyGrossSalary, monthlyBonusRate, taxRate, paycheck;
	//declare num var for distance traveled, time taken, and average speed
	double distanceTraveled, travelTime, averageSpeed;
	//declare var for # of cups of coffee sold
	int coffeeCupsSold;
	//declare cost per cup and total sales
	double costPerCup, salesTotal;

	/*prompt user to enter first name, last name, department, monthly gross
	salary, bonus, tax rate, distance traveled, time taken, coffee cups sold,
	and cost per cup*/
	cout <<"Please enter your first name, last name, department,"
 		 <<"\nmonthly gross salary, bonus percentage, tax percentage,"
		 <<"\ndistance traveled, traveling time, number of coffee cups sold"
		 <<"\nand cost per cup: \n";

	/*read first name, last name, department, monthly gross
	salary, bonus, tax rate, distance traveled, time taken, coffee cups sold,
	and cost per cup into variables*/
	inFile >>firstName >>lastName >>department >>monthlyGrossSalary 
		>>monthlyBonusRate >>taxRate >>distanceTraveled >>travelTime
		>>coffeeCupsSold >>costPerCup;
	
	//calculate paycheck with bonus and tax considered
	paycheck = (monthlyGrossSalary * (1 + monthlyBonusRate/100))
			   * (1 - taxRate/100);
	
	//output full name, department, monthly gross salary, bonus, tax, and pay
	outFile.imbue( locale( cout.getloc(), new comma_facet ) ); //to use commas
	outFile <<fixed <<showpoint <<setprecision(2);
	outFile <<"Name: " <<firstName <<" " <<lastName <<", Department: "
		 <<department <<endl;
	outFile <<"Monthly Gross Salary: $" <<monthlyGrossSalary 
			<<", Monthly Bonus: " <<monthlyBonusRate <<"%, Taxes: " 
		 	<<taxRate <<"%\n";
	outFile <<"Paycheck: $" <<paycheck <<endl <<endl;
	
	//calculate average speed
	averageSpeed = distanceTraveled / travelTime;
	
	//output distance traveled, travel time, and average speed in mph
	outFile <<"Distance Traveled: " <<distanceTraveled 
			<<" miles, Traveling Time: " <<travelTime <<" hours\n";
	outFile <<"Average Speed: "	<<averageSpeed <<" miles per hour\n\n";
	
	//calculate total sales based on cups sold and price per cup
	salesTotal = coffeeCupsSold * costPerCup;
	
	//output number of coffee cups sold, cost per cup, and total sales
	outFile <<"Number of Coffee Cups Sold: " <<coffeeCupsSold
			<<", Cost: $" <<costPerCup <<" per cup\n";
	outFile <<"Sales Amount = $" <<salesTotal;			
	
	inFile.close();					//close input file
	outFile.close();				//close output file
	
	system("pause");
	return 0;
}
