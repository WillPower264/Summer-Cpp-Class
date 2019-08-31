#include <iostream>
#include <cmath>

using namespace std;

void findLongest (double& side1, double& side2, double& side3);
void outputResults (double side1, double side2, double side3);

int main()
{
	double side1, side2, side3;				//declare variables for side lengths
	
	cout <<"This program determines whether a triangle is right, acute, or obtuse, \ngiven its sides.";
	cout <<endl <<"To exit the program, enter negative values." <<endl <<endl;
	
	while (true)
	{
		cout <<"Please enter the lengths of" 	//prompt user to enter side lengths
			 <<" the three sides of the triangle: ";
		cin >>side1;
		if (side1 < 0)
			break;
		
		cin >>side2;
		if (side2 < 0)
			break;
		
		cin >>side3;					//read from console to vars
		if (side3 < 0)
			break;
			
		findLongest(side1, side2, side3);
		
		outputResults(side1, side2, side3);	
	}
	return 0;
}

void findLongest(double& side1, double& side2, double& side3)
{
	double longest = side3, short1 = side2, short2 = side1;
	
	if (side2 > longest && side2 > side1)
		{
			longest = side2;
			short1 = side3;
		}	
	else if (side1 > longest && side1 > side2)
		{
			longest = side1;
			short2 = side3;
		}
}

void outputResults (double side1, double side2, double side3)
{
	if (side1 + side2 < side3)
		cout <<"This is not a triangle.";
	else if (side1 * side1 + side2 * side2 == side3 * side3)
		cout <<"This triangle is a right triangle.";
	else if (side1 * side1 + side2 * side2 < side3 * side3)	 
		cout <<"This triangle is an obtuse triangle.\n";
	else if (side1 * side1 + side2 * side2 > side3 * side3)	 
		cout <<"This triangle is an acute triangle.\n";
		
	cout <<endl <<endl;	
}
