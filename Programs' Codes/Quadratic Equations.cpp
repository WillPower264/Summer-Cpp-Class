#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

void findDiscriminant (int a, int b, int c, double& disc);
void calculateRoots(int a, int b, int c, double disc);

int main()
{
	double disc;
	int a, b, c;
	
	cout <<"This program gives type and value of the roots of a quadratic equation." <<endl;
	cout <<"To end this program, enter 3 0's." <<endl <<endl;
	
	while (true)
	{
		cout <<"Please enter the coefficients of x^2, x, and the constant: ";
		cin >>a >>b >>c;
		
		if (a == 0 && b == 0 && c == 0)
			break;
		
		findDiscriminant(a, b, c, disc);
		   
		calculateRoots(a, b, c, disc);
		
		cout <<endl <<endl;
	}
	return 0;
}

void findDiscriminant (int a, int b, int c, double& disc)
{
	//calculate the discriminant using b^2-4ac
	disc = pow(b,2) - 4 * a * c;
		
	//output the type of roots of the equation based on the discriminant
	if (disc == 0)
	   cout <<"This equation has a single (repeated) root which is ";
	else if (disc > 0)
       cout <<"This equation has two real roots which are ";
    else
	   cout <<"This equation has two complex roots.";
}

void calculateRoots(int a, int b, int c, double disc)
{
	double root1, root2;
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );
	cout <<fixed <<showpoint <<setprecision(4);
	//calculate the root of a quadratic equation in which the discriminant = 0
	//by using the quadratic formula and 
	if (disc == 0)
	   cout <<-b /(2 * a) <<".";
	
	//calculate the root of a quadratic equation in which the discriminant > 0
	//by using the quadratic formula and output the roots   
	else if (disc > 0)
	{
		root1 = (-b + pow((pow(b , 2) - 4 * a * c), 0.5))/(2 * a);
		root2 = (-b - pow((pow(b , 2) - 4 * a * c), 0.5))/(2 * a);
			cout <<root1 <<" and " <<root2 <<"." <<endl;		
	}
}
