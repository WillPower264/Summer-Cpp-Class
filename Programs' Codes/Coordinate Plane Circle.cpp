#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.1415926;				//set constant value PI to 3.1415926

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

double findRadius(double, double, double, double);	
double findDiameter (double);				//declare all function prototypes
double findCircumference (double);
double findArea (double);

int main()
{
	//declare variables for the x and y coordinates of the center and point										
	double centerX, centerY, pointX, pointY;		
	//declare variables for the radius
	double radius;
	char ch;
	
	cout <<"This program takes the coordinates of the center of and a point on a circle\n" 
		 <<"and gives back the radius, diameter, circumference, and area." <<endl <<endl;
	cout <<"To exit the program, enter the center (99, 99)." <<endl <<endl;	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );
	
	while (true)
	{
		//prompt user to enter the x coordinate of the center of the circle
		cout <<"Please enter the coordinates of the center: (";
		cin >>centerX;
		cin.get();
		cin >>centerY;
		cin.ignore(100,'\n');
		
		if (centerX == 99 && centerY == 99)
			break;
		
		//prompt user to enter the x coordinate of a point on the circle
		cout <<"Please enter the coordinates of a point: (";
		cin >>pointX;
		cin.get();
		cin >>pointY;	
		cin.ignore(100,'\n');
		cout <<endl;
		
		//set precision to 3 significant digits
		cout <<fixed <<showpoint <<setprecision(4);
		
		//call function to find distance between points and the radius of the circle
		radius = findRadius(centerX, centerY, pointX, pointY);
		//output the distance between the points and the radius of the circle
		cout <<"The distance is: \t" <<radius <<" units" <<endl;
		cout <<"The radius is: \t\t" <<radius <<" units" <<endl;
		
		//output the diameter
		cout <<"The diameter is: \t" <<findDiameter(radius) <<" units" <<endl;
		
		//output the circumference
		cout <<"The circumference is:\t" <<findCircumference (radius) <<" units" <<endl;
		
		//output the area
		cout <<"The area is: \t\t" <<findArea (radius) <<" sq. units" <<endl <<endl <<endl;
	}
	
	return 0;
}

//function to find radius
double findRadius (double x1, double y1, double x2, double y2)
{
	//find distance/radius by using distance formula between given points
	return sqrt(((x1 - x2) * (x1 - x2)) + 
		   		((y1 - y2) * (y1 - y2)));
}

//function to find diameter
double findDiameter (double radius)
{
	//find diameter by doubling radius
	return radius * 2;
}

//function to find circumference
double findCircumference (double radius)
{
	//find circumference by using 2 * pi * radius
	return 2 * PI * radius;
}

//function to find area
double findArea (double radius)
{
	//find area by using radius squared times pi
	return radius * radius * PI;
}
