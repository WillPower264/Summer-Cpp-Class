/*William Li
CSC 133-GW
Lab9a.cpp*/

#include <iostream>
#include <fstream>

using namespace std;

bool isVowel(char);					//declare function prototype

int main()
{
	ifstream fin;					//declare input stream variable
	ofstream fout;					//declare output stream variable
	
	fin.open("Lab9ain.txt");		//open input stream
	fout.open("Lab9aout.txt");		//open output stream
	
	char letter;					//declare letter as char
	
	fin >>letter;					//read letter from file
	
	if (isVowel(letter) == true)	//call function in an if statement
	   	//if function returns true, output the letter is a vowel					   
		fout <<"The letter '" <<letter <<"' is a vowel.";
	else
		//if function returns false, output the letter is not a vowel
		fout <<"The letter '" <<letter <<"' is not a vowel.";
	
	fin.close();					//close input stream
	fout.close();					//close output stream
	
	system("pause");
	return 0;
}

//function to determine if vowel or not
bool isVowel(char letter)	
{
 	//if the letter inputted is any of these characters, return true
	if (letter == 'A' || letter == 'a' || letter == 'E' || letter == 'e' || 
	    letter == 'I' || letter == 'i' || letter == 'O' || letter == 'o' || 
 		letter == 'U' || letter == 'u')
		return true;
	//if letter inputted is not any of the previous characters, return false	
	else
		return false;
}
