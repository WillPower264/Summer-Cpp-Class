/*William Li
CSC 133-GW
Lab6d.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream fin;					//declare input stream variable
	ofstream fout;					//declare output stream variable
	
	//declare variables for account number, total minutes used, minutes used at
	//night, and minutes used in the day
	int acctNum, minutes, nightMin, dayMin;	
	char code;						//declare char for type of service
	double bill;					//declare double for final bill
	string acctType;				//declare string for the account type
	
	fin.open("Lab6din.txt");		//open input stream
	fout.open("Lab6dout.txt");		//open output stream
	
	//prompt user to enter account number, service code, and total number of
	//minutes used
	cout <<"Please enter your account number, service code (R for regular and"
		 <<" P for premium), and number of minutes used: ";
	fin >>acctNum >>code >>minutes;	//read account number, service code, and
				  		 			//total minutes into appropriate variables
	
	fout <<fixed <<showpoint <<setprecision(2);	//set # of sig. dig to 2
	
	switch (code)				//set up switch structure
	{
		case 'r': case 'R':		//if user entered r or R, then regular service
			acctType = "Regular";
			
			//output account number, type and total minutes used
			fout <<"Your account number is: " <<acctNum <<endl;
			fout <<"Your account type is: \t" <<acctType <<endl;
			fout <<"Your minutes used are: \t" <<minutes <<endl;
			
			//calculate amount due if more than 50 minutes used
			if (minutes > 50)
			{
				bill = 10 + 0.2 * (minutes - 50);
				fout <<"Your bill is: \t\t$" <<bill;	//output amount due
			}
		
			//calculate amount due if less than 50 minutes used		
			else if (minutes <= 50 && minutes >= 0)
			{
				bill = 10;
				fout <<"Your bill is: \t\t$" <<bill; 	//output amount due
			}
			
			//error message if user enters a negative amount of minutes
			else
				fout <<"Error. Please enter a positive amount of minutes.\n";
			break;				//exit switch structure when service is regular
	
		case 'p': case 'P':		//if user entered p or P, then premium service
			acctType = "Premium";
			
			//prompt user to enter number of minutes used at night
			cout <<"Please enter the number of minutes used at night "
				 <<"(between 6 AM and 6 PM): ";
			cin >>nightMin;		//read number of minutes used at night into var
			
			//calculate number of minutes used in the day by subtracting night 
			//minutes from total minutes
			dayMin = minutes - nightMin; 	
			
			//output account number and type
			fout <<"Your account number is: " <<acctNum <<endl;
			fout <<"Your account type is: \t" <<acctType <<endl;
			
			//if user enters more minutes used at night than total minutes, 
			//then output error message		 
			if (nightMin > minutes)
				fout <<"Error. You can not use more minutes at night than "
					 <<"you have used in total. Please try again.";

			//if user enters less than 0 minutes, then output error message	
			else if (minutes < 0)
				fout <<"Error. Please enter a positive amount of minutes.\n";
			
			//if user went over quota on both day minutes and night minutes
			else if (dayMin > 75 && nightMin > 100)
			{		//calculate amount due
				bill = 25 + 0.1 * (dayMin - 75) + 0.05 * (nightMin - 100);
				fout <<"Your bill is: \t\t$" <<bill; 	//output amount due
			}
			
			//if user went over quota on day minutes
			else if (dayMin > 75)
			{		//calculate amount due
				bill = 25 + 0.1 * (dayMin - 75);
				fout <<"Your bill is: \t\t$" <<bill; 	//output amount due 				
			}
			
			//if user went over quota on night minutes
			else if (nightMin > 100)
			{		//calculate amount due
				bill = 25 + 0.05 * (nightMin - 100);
				fout <<"Your bill is: \t\t$" <<bill; 	//output amount due 				
			}
			
			//if user does not go over either night or day minutes quota
			else
			{		//calculate amount due
				bill = 25;
				fout <<"Your bill is: \t\t$" <<bill; 	//output amount due 								
			}	
			break;				//exit switch structure when service is premium
		
		//error message if user enters a service code other than r, R, p, or P
		default:
			fout <<"Error. Please enter a valid service code "
			 	<<"(R for regular or P for premium) and try again.\n";
			break;	 			//exit switch structure
	}	
	
	fin.close();			//close input file
	fout.close();			//close output file
	
	system("pause");
	return 0;
}
