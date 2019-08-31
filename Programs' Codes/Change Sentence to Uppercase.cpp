/*William Li
CSC 133-GW
Lab11d.cpp*/

#include <iostream>
#include <string>

using namespace std;

void changeCase(char *letters, int length, string sent);
void outputSentence(char *letters, int length, string sent);

int main()
{
	string sent;
	int length;
	char *letters, *temp;
	
	cout <<"Please enter a sentence to be changed to capital letters: " <<endl;
	
	getline(cin, sent);
	length = sent.length();	
	letters = new char[length];
	
	temp = letters;
	
	for (int i = 0; i < length; i++, letters++)
		*letters = sent.at(i);
	
	letters = temp;

	changeCase(letters, length, sent);		  //call function changeCase and pass array
	
	outputSentence(letters, length, sent);	  //call function outputSentence and pass array
	
	delete [] letters;
	
	system("pause");
	return 0;
}

void changeCase(char *letters, int length, string sent)
{
	for (int i = 0; i < length; i++, letters++)
		if (static_cast<int>(sent.at(i)) >= 97 && 
			static_cast<int>(sent.at(i)) <= 122)
			*letters = static_cast<char>(static_cast<int>(sent.at(i)) - 32);
}

void outputSentence(char *letters, int length, string sent)
{
	cout <<endl <<"Your sentence is now: " <<endl;
	
	for (int i = 0; i < length; i++, letters++)
		cout <<*letters;
		
	cout <<endl <<endl;	
}
