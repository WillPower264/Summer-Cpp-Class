/*William Li
CSC 133-GW
Lab5e.cpp*/

//This program determines the number of boxes and containers needed to ship a
//given amount of cookies and determines the number of extra cookies and boxes

#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
	ifstream fin;					//declare input stream variable
	ofstream fout;					//declare output stream variable
	
	int cookies, cookiesPerBox, boxesPerContainer;				
	int boxes, containers, leftoverCookies, leftoverBoxes;		
	
	fin.open("Lab5ein.txt");						//open input file
	fout.open("Lab5eout.txt");						//open output file
	
	//prompt user to enter the number of cookies, the number of cookies per box
	//and the number of boxes per container
	cout <<"Please enter the number of cookies total, the number of cookies per"
		 <<" box, and the number of boxes per container: ";
	fin >>cookies >>cookiesPerBox >>boxesPerContainer;		//read from file to 
	cout <<endl;											//variables
	
	boxes = (cookies / cookiesPerBox);				//calculate total boxes
	leftoverCookies = (cookies % cookiesPerBox);	//calculate extra cookies
	
	containers = boxes / boxesPerContainer;			//calculate total containers
	leftoverBoxes = boxes % boxesPerContainer;		//calculate extra boxes
	
	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas

	//to display number of cookies
	fout <<"If there are " <<cookies <<" cookies then: " <<endl;
	
	//to display number of boxes and containers needed
	//change boxes to box and containers to container
	if (containers == 1 && boxes == 1)	
 	    fout <<"You will need " <<boxes <<" box.\n"
		 	 <<"You will need " <<containers <<" container. " <<endl;
    else if (containers == 1)			//change containers to container		
		fout <<"You will need " <<boxes <<" boxes.\n"
			 <<"You will need " <<containers <<" container." <<endl;
	else if (boxes == 1)				//change boxes to box
		fout <<"You will need " <<boxes <<" box.\n" 
			 <<"You will need " <<containers <<" containers." <<endl;
	else 								//no change to plural nouns
		fout <<"You will need " <<boxes <<" box.\n"
			 <<"You will need " <<containers <<" containers." <<endl;		 	 	 

	
	//to display number of extra cookies and boxes
	if (leftoverCookies == 1 && leftoverBoxes == 1) //change cookies to cookie
	     fout <<"You will have " <<leftoverCookies 	//and boxes to box
		 	  <<" leftover cookie. You will have " 
 			  <<leftoverBoxes <<" leftover box.";
	else if(leftoverBoxes == 1)						//change boxes to box
		 fout <<"You will have " <<leftoverCookies <<" leftover cookies.\n"
		 	  <<"You will have " <<leftoverBoxes <<" leftover box.";
	else if(leftoverCookies == 1)					//change cookies to cookie
		 fout <<"You will have " <<leftoverCookies <<" leftover cookie.\n"
		 	  <<"You will have " <<leftoverBoxes <<" leftover boxes.";
	else 											//no change to plural nouns
		 fout <<"You will have " <<leftoverCookies <<" leftover cookies.\n"
		 	  <<"You will have " <<leftoverBoxes <<" leftover boxes.";		 	  
		 	
	fin.close();									//close input file
	fout.close();									//close output file
	
	system("pause");
	return 0;
}
