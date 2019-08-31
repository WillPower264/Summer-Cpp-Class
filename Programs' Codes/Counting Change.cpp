/*William Li
CSC 133-GW
Lab3f.cpp*/

#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

struct comma_facet : public std:: numpunct<char>
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	int quarters, dimes, nickels, pennies;
	float total;
 	
 	cout <<"This program calculates the total value of your loose change." <<endl <<endl;
 	
 	cout <<"How many quarters do you have?\t";
 	cin >>quarters;
	
	cout <<"How many dimes do you have?\t";
 	cin >>dimes;
	 
	cout <<"How many nickels do you have?\t";
 	cin >>nickels;
	 
	cout <<"How many pennies do you have?\t";
 	cin >>pennies;
	cout <<endl;
 	
 	total = 25 * quarters + 10 * dimes + 5 * nickels + pennies;
 	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );
 	cout <<quarters <<" quarters, " <<dimes <<" dimes, " <<nickels 
 		 <<" nickels, and " <<pennies <<" pennies total to $" 
		 <<fixed <<showpoint <<setprecision(2) <<total/100 <<"." <<endl;
	
	return 0;
}
