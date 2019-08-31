/*William Li
CSC 133-GW
Lab2e.cpp*/

#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14;

struct comma_facet : public std:: numpunct<char>
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	double radius;
	double area;
	double circumference;
	
	cout <<"This program finds circumference and area of a circle, given the radius." <<endl;
	cout <<"It uses 3.14 for pi." <<endl <<endl;
	cout <<"To exit the program, enter a length less than 0." <<endl <<endl;
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );
	cout <<fixed <<showpoint <<setprecision(4);
	
	while (true)
	{
		cout <<"Enter radius:\t";
		cin >>radius;
		
		
		if (radius < 0)
			return 0;
		
		circumference = 2 * PI * radius;
		area = PI * radius * radius;
		
		cout <<"Circumference =\t" <<circumference <<" units" <<endl;
		cout <<"Area = \t\t" <<area <<" sq. units" <<endl <<endl;
		
	}
	
	return 0;
	
}
