/*William Li
CSC 133-GW
Lab7c.cpp*/

#include <iostream>

using namespace std;

int main()
{
	char letter;						//declare letter and yesNo as chars
	int i = 1;							//declare variable i as int
	bool dash = false, redo = false;
	
	cout <<"This program translates words to telephone digits. Press '*' to terminate.";
	cout <<endl <<endl <<"Please enter some words: " <<endl;
	
	cin >>letter;
		
	//if user enter y or Y, continue, if not, terminate program
	while (letter != '*')
	{	
		if (i == 1)					//if first iteration of loop, output string
			if (redo == false)
		    	cout <<"The telephone digits are: ";
	
		if (i == 4)					//if 4th iteration, output hyphen
		   if (dash == false)
		   		cout <<"-";
   	
			
		switch (letter)				//set up switch structure
 		{
 			//if A, a, B, b, C, or c, output 2
			case'A': case'a': case'B': case'b': case'C': case'c': 
					 cout <<2;
					 break;
			
			//if D, d, E, e, F, or f, output 3		 
		 	case'D': case'd': case'E': case'e': case'F': case'f': 
		 			 cout <<3;
 					 break;
 			
		 	//if G, g, H, h, I, or i, output 4		 
		 	case'G': case'g': case'H': case'h': case'I': case'i': 
		 			 cout <<4;
		 			 break;
		 	
			//if J, j, K, k, L, or l, output 5		 
		 	case'J': case'j': case'K': case'k': case'L': case'l': 
		 			 cout <<5;
		 			 break;
		 	
		 	//if M, m, N, n, O, or o, output 6
			case'M': case'm': case'N': case'n': case'O': case'o': 
		  			 cout <<6;
		  			 break;
		  			 
		  	//if P, p, Q, q, R, r, S, or s, output 7		 
		 	case'P': case'p': case'Q': case'q': case'R': case'r': case'S': 
			 		 case's': 
		 			 cout <<7;
		 			 break;
		 	
			//if T, t, U, u, V, or v, output 8 		 
		 	case'T': case't': case'U': case'u': case'V': case'v': 
	 				 cout <<8;
	 				 break;
	 		
			//if W, w, X, x, Y, y, Z, or z, output 9 		 
		 	case'W': case'w': case'X': case'x': case'Y': case'y': case'Z': 
			 		 case'z':
		 			 cout <<9;
		 			 break;
		 	
			//if a letter was not entered, output error message
			default:
					 if (i == 1)
					 	redo = true;
					 if (i == 4)
					 	dash = true;				 
					 i--;
			 		 break;
 		}	
		i++;					//increment i by 1
		
		if (i == 8)				//if 8th iteration, execute following statements
		{
			cin.clear();			//clear input stream
			cin.ignore(100,'\n');	//ignore remaining input
			dash = false;
			redo = false;
			
			cout <<endl <<endl;	
			cout <<"Please enter more words: " <<endl;
			
			i = 1;					//reset i to 1
		}
		
		cin >>letter;				//read next letter from file
	}

	return 0;
}
