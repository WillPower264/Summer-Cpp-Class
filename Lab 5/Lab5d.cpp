/*William Li
CSC 133-GW
Lab5d.cpp*/

//This program takes in 3 sides of a triangle and determines whether or not the
//triangle is a right triangle or not.

#include <iostream>

using namespace std;

int main()
{
	double side1, side2, side3;				//declare variables for side lengths
	
	cout <<"Please enter the lengths of" 	//prompt user to enter side lengths
		 <<" the three sides of the triangle: ";
	cin >>side1 >>side2 >>side3;					//read from console to vars
	cout <<endl;
	
	if (side1 * side1 + side2 * side2 == side3 * side3 ||	//determine right
	    side2 * side2 + side3 * side3 == side1 * side1 ||	//triangle by
		side1 * side1 + side3 * side3 == side2 * side2)		//testing sides
		cout <<"This triangle is a right triangle.\n";
	else													//output when not 
		cout <<"This triangle is not a right triangle.\n";	//a right triangle
		
	system("pause");
	return 0;
}
