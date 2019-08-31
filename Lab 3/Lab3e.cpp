/*William Li
CSC 133-GW
Lab3e.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const double litersPerCarton = 3.78;
const double costPerLiter = .38;
const double profitPerCarton = .27;

int main()
{
	ifstream fin;
	ofstream fout;
	
	fin.open("Lab3ein.txt");
	fout.open("Lab3eout.txt");
	
	int carton;
	double cost, profit, litersProduced;
	
	cout <<"Please enter the total amount of milk produced in the morning: \n";
	fin >>litersProduced;
	
	carton = litersProduced / litersPerCarton + 0.5;
	cost = litersProduced * costPerLiter;
	profit = carton * profitPerCarton;
	
	fout <<"You will need " <<carton <<" cartons to hold milk." <<endl;
	fout <<"It will cost $" <<fixed <<showpoint <<setprecision(2)
		 <<cost <<" to produce " <<setprecision(1)<<litersProduced 
		 <<" liters of milk.\n";
	fout <<"You will earn $" <<setprecision(2) <<profit <<" in total.";	 
	
	fin.close();
	fout.close();		 
	
	system("pause");
	return 0;
}
