/*William Li
CSC 133-GW
Lab9b.cpp*/

#include <iostream>

using namespace std;

int isVowel(char);					//declare function prototype

int main()
{		
	char letter;					//declare letter as a char
	int numOfVowels = 0;			//delcare numOfVowels as an int and set to 0
	
	//prompt user to enter a sentence, ending in a period
	cout <<"Please enter a sentence, ending in a period: \n";
	cin >>letter; 					//read first character of sentence
	
	//continue loop until a period is read
	while (letter != '.')
 	{
 		//call function and add value that is returned to numOfVowels
 		numOfVowels += isVowel(letter);
 		cin >>letter;				//read next character of sentence
 	}
	
	//output the number of vowels in the inputted sentence
	cout <<"\nThere were "<<numOfVowels <<" vowels in your sentence." <<endl;

	system("pause");
	return 0;
}

//function to determine whether vowel or not
int isVowel(char letter)
{
	//if the character read matches any of these characters, return 1
	if (letter == 'A' || letter == 'a' || letter == 'E' || letter == 'e' || 
	    letter == 'I' || letter == 'i' || letter == 'O' || letter == 'o' || 
 		letter == 'U' || letter == 'u')
		return 1;
	//if the character read does not match any of the previous chars, return 0	
	else
		return 0;
}
