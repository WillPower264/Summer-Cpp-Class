/*William Li
CSC 133-GW
Lab9d.cpp*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.1415926;				//set constant value PI to 3.1415926

double findRadius(double, double, double, double);	
double findDiameter (double);				//declare all function prototypes
double findCircumference (double);
double findArea (double);

int main()
{
	ifstream fin;							//declare input stream variable
	ofstream fout;							//declare output stream variable
	
	fin.open("Lab9din.txt");				//open input stream
	fout.open("Lab9dout.txt");				//close input stream
											
	//declare variables for the x and y coordinates of the center and point										
	double centerX, centerY, pointX, pointY;		
	//declare variables for the radius, diameter, circumference, and area
	double radius, diameter, circumference, area;
	
	//prompt user to enter the x coordinate of the center of the circle
	cout <<"Please enter the x coordinate of the center of the circle: ";
	fin >>centerX;					//read x coordinate of point
	cout <<endl;
	
	//prompt user to enter the y coordinate of the center of the circle
	cout <<"Please enter the y coordinate of the center of the circle: ";
	fin >>centerY;					//read y coordinate of point
	cout <<endl;
	
	//prompt user to enter the x coordinate of a point on the circle
	cout <<"Please enter the x coordinate of a point on the circle: ";
	fin >>pointX;					//read x coordinate of point
	cout <<endl;
	
	//prompt user to enter the y coordinate of a point on the circle
	cout <<"Please enter the y coordinate of a point on the circle: ";
	fin >>pointY;					//read y coordinate of point
	cout <<endl;
	
	//set precision to 3 significant digits
	fout <<fixed <<showpoint <<setprecision(3);
	
	//call function to find distance between points and the radius of the circle
	radius = findRadius(centerX, centerY, pointX, pointY);
	//output the distance between the points and the radius of the circle
	fout <<"The distance is: \t" <<radius <<" units" <<endl <<endl;
	fout <<"The radius is: \t\t" <<radius <<" units" <<endl <<endl;
	
	//call function to find the diameter of the circle
	diameter = findDiameter(radius);
	//output the diameter
	fout <<"The diameter is: \t" <<diameter <<" units" <<endl <<endl;
	
	//call function to find the circumference of the circle
	circumference = findCircumference (radius);
	//output the circumference
	fout <<"The circumference is:\t" <<circumference <<" units" <<endl <<endl;
	
	//call function to find area of the circle
	area = findArea (radius);
	//output the area
	fout <<"The area is: \t\t" <<area <<" units squared" <<endl <<endl;
	
	system("pause");
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
