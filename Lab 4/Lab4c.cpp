/*William Li
CSC 133-GW
Lab4c.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>

using namespace std;

struct comma_facet : public std:: numpunct<char>		//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;					//declare input stream variable
	ofstream fout;					//dclare output stream variable

	fin.open("Lab4cin.txt");		//open input file
	fout.open("Lab4cout.txt");		//open output file
	
	//declare 4 prices and total sale as doubles
	double price1, price2, price3, price4, totalSale;
	//declare # of type of tickets sold and total tickets sold as ints
	int sold1, sold2, sold3, sold4, totalSold;
	
	fin >>price1 >>sold1			//read prices and number sold
		>>price2 >>sold2			//of 4 types of tickets
		>>price3 >>sold3
		>>price4 >>sold4;
	
	//calculate the grand total amount of money taken in
	totalSale = price1*sold1+price2*sold2+price3*sold3+price4*sold4;
	//calculate the grand total  sold
	totalSold = sold1 + sold2 + sold3 + sold4;
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) ); //to use commas
	//display the grand total sale and grand total tickets sold and set to
	//2 significant digits
	fout <<fixed <<showpoint <<setprecision(2);
	fout <<"Grand total number of tickets sold: \t" <<totalSold <<" tickets.\n";
	fout <<"Grand total sale amount: \t\t$" <<totalSale <<".";
		 
 	fin.close();					//close input file
	fout.close(); 					//close output file
	
	system("pause");
	return 0;
}
