/*William Li
CSC 133-GW
Lab10d.cpp*/

#include <iostream>

using namespace std;

void printStars (int lines);		//declare function prototype
int inputLines();

int orig;							//declare global variable orig as int

int main()
{
	//call function inputLines and use return value to call function printStars
	printStars (inputLines());		
	
	system("pause");
	return 0;
}

//function to input number of lines the user wishes to see
int inputLines()
{
	int lines;						//declare lines as int
	
	//prompt user to enter number of lines of stars he or she wishes to see
	cout <<"Please enter the number of lines of stars you wish to see: ";
	cin >>lines;					//read in number of lines into var lines
	
	orig = lines;					//assign value of lines into orig
	
	return lines;					//return value of lines back to main
}

//function to print stars based on number of lines wished to see
void printStars (int lines)
{
	//declare rewind as false and make sure it does not change
 	static bool rewind = false;
	
	//if lines has decremented to 0, set rewind to true
	if (lines == 0)
		rewind = true;
	//if rewind is false, execute for loop which decrements iloop
	else if (rewind == false)
		    //output a star for every iteration i is less than 0
		for (int i = lines; i > 0; i--)
			cout <<'*';
	//if rewind is true, execute for loop which increments i		
	else
		//output a star for every iteration i is greater than lines
		for (int i = 0; i < lines; i++)
			cout <<'*';
	
	//if the line is not equal to 0, go to the next line
	if (lines != 0)
	    cout <<endl;
	
	//if rewind is set to true and lines is equal to the original value of lines
	//then return to main
	if (rewind == true && lines == orig)
	    return;	
	
	//if rewind is false, decrement lines by 1 and recall itself
	if (rewind == false)
	    printStars (lines - 1);	
	//if rewind is true, increment lines by 1 and recall itself    
	else 
	    printStars (lines + 1); 	
}
