/*William Li
CSC 133-GW
Lab3d.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	
	fin.open("Lab3din.txt");
	fout.open("Lab3dout.txt");
	
	double originalPrice, markupRate, salesTaxRate;
	double sellPrice, salesTax, finalPrice;
	
	cout <<"Please enter the original price, mark up rate\nand sales tax rate"
		 <<" without % signs: \n";
 	fin >>originalPrice >>markupRate >>salesTaxRate;
 	
 	sellPrice = originalPrice * (1+ markupRate / 100);
 	salesTax = sellPrice * salesTaxRate / 100;
 	finalPrice = sellPrice + salesTax;
 	
 	fout <<fixed <<showpoint;
 	fout <<"The original price is: \t$" <<setprecision(2) <<originalPrice <<endl;
 	fout <<"The mark up rate is: \t" <<setprecision(2) <<markupRate <<"%" <<endl;
 	fout <<"The selling price is: \t$" <<setprecision(2) <<sellPrice <<endl;
 	fout <<"The sales tax rate is: \t" <<setprecision(2) <<salesTaxRate <<"%" <<endl;
 	fout <<"The sales tax is: \t$" <<setprecision(2) <<salesTax <<endl;
 	fout <<"The final price is: \t$" <<setprecision(2) <<finalPrice <<endl;
	
	fin.close();
	fout.close();
	
	system("pause");
	return 0;
}
