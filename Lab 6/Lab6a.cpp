/*William Li
CSC 133-GW
Lab6a.cpp*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;				//declare input stream variable
	ofstream fout;				//declare output stream variable
	
	fin.open("Lab6ain.txt");	//open input stream
	fout.open("Lab6aout.txt");	//open output stream
	
	double disc, root1, root2;	//declare discriminant, and roots as doubles
	int a, b, c; //declare the coefficients and constant of the equation as ints
	
	//prompt user to enter coefficients and constant of the equation
	cout <<"Please enter the coefficients of x^2, x, and the constant: ";
	fin >>a >>b >>c;			//read coefficients and constant into variables
	cout <<endl;
	
	//calculate the discriminant using b^2-4ac
	disc = pow(b,2) - 4 * a * c;
	
	//output the type of roots of the equation based on the discriminant
	if (disc == 0)		//when discriminant = 0 output this
	   fout <<"This equation has a single (repeated) root." <<endl;
	else if (disc > 0)	//when discriminant > 0 output this
       fout <<"This equation has two real roots." <<endl;
    else   				//when discriminant < 0 output this
	   fout <<"This equation has two complex roots." <<endl;
	   
	//calculate the root of a quadratic equation in which the discriminant = 0
	//by using the quadratic formula and 
	if (disc == 0)
	{
	   root1 = -b /(2 * a); 
    }
	
	//calculate the root of a quadratic equation in which the discriminant > 0
	//by using the quadratic formula and output the roots   
	if (disc > 0)
	{	//to find both roots, complete formula with + and then -
		root1 = (-b + pow((pow(b , 2) - 4 * a * c), 0.5))/(2 * a);
		root2 = (-b - pow((pow(b , 2) - 4 * a * c), 0.5))/(2 * a);
		fout <<"The roots of the quadratic equation " <<a <<"x^2 + " <<b 
			 <<"x +" <<"("<<c <<") = 0 are " <<root1 <<" and " <<root2 <<".\n";		
	}   
	
	fin.close();						//close input stream
	fout.close();						//close output stream
	   
	system("pause");
	return 0;
}
