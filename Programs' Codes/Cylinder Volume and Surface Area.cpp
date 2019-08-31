/*William Li
CSC 133-GW
Lab4b.cpp*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14; 			//set PI equal to 3.14 for entire program

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	double radius;					//declare radius as a double
	double height;					//declare height as a double
	
	cout <<"This program finds the volume and surface area of a cylinder." <<endl;
	cout <<"Pi is set to 3.14." <<endl <<endl;
	
	cout <<"To exit the program enter a negative value for the radius or height.";
	cout <<endl <<endl;
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	
	while (true)
	{
		cout <<"Enter the radius: "; //prompt user to enter radius
		cin >>radius;						 //read radius into variable radius
		
		if (radius < 0)
			return 0;
		
		cout <<"Enter the height: "; //prompt user to enter height
		cin >>height;						 //read height into variable height
		cout <<endl;
		
		if (height < 0)
			return 0;
		
		
		cout <<fixed <<showpoint <<setprecision(4);	//set numbers to 2 sig. digits
		cout <<"Volume =\t"			//calculate volume of cylinder 
			 <<PI * pow(radius, 2.0) * height <<" units^3" <<endl;	//and output
		cout <<"Surface area =\t"		//calculate surface area and output
			 <<2 * PI * radius * height + 2 * PI * pow(radius, 2.0) <<" units^2"
			 <<endl <<endl <<endl;
	}
}
