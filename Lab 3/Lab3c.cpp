/*William Li
CSC 133-GW
Lab3c.cpp*/

#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

struct comma_facet : public std:: numpunct<char>
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;
	ofstream fout;
	double gal, mpg, miles;
	
	fin.open("Lab3cin.txt");
	fout.open("Lab3cout.txt");
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) );
	
	cout <<"Please enter your car's gas capacity in gallons \nand your "
		 <<"car's average mpg separated by spaces: \n";
	fin >>gal >>mpg;
	
	miles = gal * mpg;
	
	fout <<"You can drive approximately " <<miles <<" miles if your car holds "
		 <<gal <<" gallons of gasoline and averages " <<mpg <<" mpg.";
	
	fin.close();
	fin.close();
	
	
	system("pause");
	return 0;
}
