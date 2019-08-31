/*William Li
CSC 133-GW
Lab7c.cpp*/

#include <iostream>
#include <string>

using namespace std;

const int LETTERS = 15;

void inputWords (char letter[], string words, int length);

int main()
{
	char letter[LETTERS];
	string words;
	int length;							//declare variable i as int
	bool dash = false, redo = false;
	
	cout <<"This program translates words to telephone digits. Press '*' to terminate.";
	cout <<endl <<endl <<"Please enter some words: " <<endl;
	
	//fill array with 0's
	for (int j = 0; j < LETTERS; j++)
		letter[j] = '0';
	
	//get the input
	getline(cin, words);
	
	//find the length
	length = words.length();
	if (length > LETTERS)		//if length of input is longer than letters, length = letters
		length = LETTERS;
	
	for (int i = 0; i < length; i++)
		letter[i] = words.at(i);
		
	//if user enter y or Y, continue, if not, terminate program
	for (int i = 0, k = 0; letter[k] != '*'; k++)
	{	
		if (i == 0)					//if first iteration of loop, output string
		   if (redo == false)
		    	cout <<"The telephone digits are: ";
	
		if (i == 3)					//if 4th iteration, output hyphen
		   if (dash == false)
		   		cout <<"-";
		
		switch (letter[k])				//set up switch structure
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
		 			 
		 	case'0': case'1': case'2': case'3': case'4': case'5': case'6':
		 	case'7': case'8': case'9':	
			 		 cout <<letter[k];	
					 break;		 
		 	
			//if a letter was not entered, output error message
			default:
					 if (i == 3)
					 	dash = true;
					 redo = true;
					 			 
					 i--;
			 		 break;
 		}	
		i++;					//increment i by 1
		
		if (i == 7)				//if 8th iteration, execute following statements
		{
			dash = false;
			redo = false;
			
			cout <<endl <<endl;	
			cout <<"Please enter more words: " <<endl;
			
			for (int j = 0; j < LETTERS; j++)
				letter[j] = '0';
			i = 0;					//reset i to i
			k = 0;
			
			inputWords(letter, words, length);
		}
	}

	cout <<endl;
	
	return 0;
}

void inputWords (char letter[], string words, int length)
{
	//get the input
	getline(cin, words);
	
	//find the length
	length = words.length();
	if (length > LETTERS)		//if length of input is longer than letters, length = letters
		length = LETTERS;
	
	for (int i = 0; i < length; i++)
		letter[i + 1] = words.at(i);
}
