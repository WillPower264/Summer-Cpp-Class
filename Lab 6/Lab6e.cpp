/*William Li
CSC 133-GW
Lab6e.cpp*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//declare variables for gender, body weight, wrist size, waist 
	//size, hip size, forearm size, body fat content, and body fat percentage 
	string gender;
	double bodyWeight, wrist, waist, hip, forearm;
	double bodyFat, bodyFatPercent;
	//declare variables for number holders a1, a2, a3, a4, a5, and b
	double a1, a2, a3, a4, a5, b;
	
	//prompt user to identify him or herself as a male or female
	cout <<"Are you a male or female? "
		 <<"(please enter either \"male\" or \"female\"): ";
	cin >>gender;			//read user input into gender 
	
	//set number of significant digits to 2
	cout <<fixed <<showpoint <<setprecision(2);
	
	if (gender == "male")
	{	//if user is male, then execute following statements
		
		//prompt user to enter body weight
		cout <<"Please enter your body weight (in pounds): ";
		cin >>bodyWeight;	//read body weight into var
		//prompt user to enter wrist size
		cout <<"Please eneter your wrist size (in inches): ";
		cin >>wrist;		//read wrist size into var
		cout <<endl;
		
		//calculate body fat percentage following a formula
		a1 = bodyWeight * 1.082 + 94.42;
		a2 = wrist * 4.15;
		b = a1 - a2;
		bodyFat = bodyWeight - b;
		bodyFatPercent = bodyFat * 100 / bodyWeight;
		
		//output body fat to user
		cout <<"Your body fat is " <<bodyFat <<" pounds." <<endl;
		
		//output BMI to user
		cout <<"Your BMI is " <<bodyFatPercent <<" lbs/in^2." <<endl <<endl;
			 
	}
	
	else 
	{	//if user is female, then execute following statements
		
		//prompt user to enter body weight
		cout <<"Please enter your body weight (in pounds): ";
		cin >>bodyWeight;	//read body weight to var
		
		//prompt user to enter wrist size
		cout <<"Please enter your wrist size (in inches): ";
		cin >>wrist;		//read wrist size to var
		
		//prompt user to enter waist size
		cout <<"Please enter your waist size (in inches): ";
		cin >>waist;		//read waist size to var
		
		//prompt user to enter hip size
		cout <<"Please enter your hip size (in inches): ";
		cin >>hip;			//read hip size to var
		
		//prompt user to enter forearm size
		cout <<"Please enter your forearm size (in inches): ";
		cin >>forearm;		//read forearm size to var
		cout <<endl;
		
		//calculate body fat percentage following a formula				 		 		 	   			  
		a1 = bodyWeight * 0.732 + 8.987;
		a2 = wrist / 3.14;
		a3 = hip * 0.249;
		a4 = forearm * 0.434;
		b = a1 + a2 - a3 - a4 + a5;
		bodyFat = bodyWeight - b;
		bodyFatPercent = bodyFat * 100 / bodyWeight;
				
		//output body fat to user
		cout <<"Your body fat is " <<bodyFat <<" pounds." <<endl;
		
		//output BMI to user
		cout <<"Your BMI is " <<bodyFatPercent <<" lbs/in^2." <<endl <<endl;
	}	
	
	system("pause");
	return 0;
}
