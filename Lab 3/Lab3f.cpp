/*William Li
CSC 133-GW
Lab3f.cpp*/

#include <iostream>
#include <locale>

using namespace std;

struct comma_facet : public std:: numpunct<char>
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	int quarters, dimes, nickels, pennies;
 	
 	cout <<"Please enter the number of quarters, dimes, and nickels: ";
 	cin >>quarters >>dimes >>nickels;
 	
 	pennies = 25 * quarters + 10 * dimes + 5 * nickels;
 	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );
 	cout <<quarters <<" quarters, " <<dimes <<" dimes, and " <<nickels 
 		 <<" nickels are equivalent to " <<pennies <<" pennies." <<endl;
	
	system("pause");
	return 0;
}
