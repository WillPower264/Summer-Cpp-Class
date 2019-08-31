/*William Li
CSC 133-GW
Lab11d.cpp*/

#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 30;				//declare const var ARRAY_SIZE to 30

void inputData(char letter[]);			//declare variable prototypes
void changeCase(char letter[]);
void outputSentence(char letter[]);

int main()
{
	char letters[ARRAY_SIZE];			//declare array letters with 30 elements
	inputData(letters);					//call function inputData and pass array
	
	changeCase(letters);			   //call function changeCase and pass array
	
	outputSentence(letters);	   //call function outputSentence and pass array
	
	system("pause");
	return 0;
}

void inputData(char letter[])
{
	//prompt user to enter a sentence
	cout <<"Please enter a sentence: " <<endl;
	
	//while i is less than the array size, loop and increment i
	for (int i = 0; i < ARRAY_SIZE; i++)
		//get the next character in the input and store it in array letter at 
		//index i
		cin.get(letter[i]);
		
	cout <<endl;	
}

//function to change the lowercase letter in array letter to uppercase
void changeCase(char letter[])
{
	//while i is less than the array size, loop and increment
	for (int i = 0; i < ARRAY_SIZE; i++)
		//if the static cast value of the char is between 97 and 122 inclusive
		if (static_cast<int>(letter[i]) >= 97 && 
			static_cast<int>(letter[i]) <= 122)
			//static cast the letter with a value of the uppercase letter
			letter[i] = static_cast<char>(static_cast<int>(letter[i]) - 32);
}

//function to output the sentence after manipulation
void outputSentence(char letter[])
{
	//output the header before outputting the sentence
	cout <<"Your sentence is now: " <<endl;
	
	//while i is less than the array size, loop and increment i
	for (int i = 0; i < ARRAY_SIZE; i++)
		//output each char stored in array letter
		cout <<letter[i];
		
	cout <<endl <<endl;	
}
