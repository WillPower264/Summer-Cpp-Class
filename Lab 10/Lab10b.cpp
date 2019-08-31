/*William Li
CSC 133-GW
Lab10b.cpp*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sentence;				//declare global variable sentence as sting

void countVowels(int&, int&, int&, int&, int&);	//declare function prototype
void outputData();

ifstream fin;						//declare input stream variable
ofstream fout;						//declare output stream variable

//declare variables for the amounts of each vowel, and set all to 0
int aAmount = 0, eAmount = 0, iAmount = 0, oAmount = 0, uAmount = 0;

int main()
{
	
	fin.open("Lab10bin.txt");			//open input stream
	fout.open("Lab10bout.txt");			//open output stream
	
	
	//get entire sentence from file into var sentence
	getline(fin, sentence);
	
	//call function countVowels with amounts of vowels as actual parameters
	countVowels(aAmount, eAmount, iAmount, oAmount, uAmount);	
	
	//call function outputData
	outputData();	 
	
	fin.close();						//close input stream
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}

//function which counts the number occurences of each vowel,
//and it takes 5 reference parameters
void countVowels(int& numOfA, int& numOfE, int& numOfI, int& numOfO, 
 	 			 int& numOfU)
{
	//loop as long as the place holder i is less than the number of digits
	for (int i = 0; i < sentence.length(); i++)
	{
		//set switch structure to read the character at the 'i'th position
		switch (sentence.at(i))
		{
			case 'a': case 'A':		//if a, then add 1 to numOfA
				numOfA += 1;
				break;
			case 'e': case 'E':		//if e, then add 1 to numOfE
				numOfE += 1;
				break;
			case 'i': case 'I':		//if i, then add 1 to numOfI
				numOfI += 1;
				break;
			case 'o': case 'O':		//if o, then add 1 to numOfO
				numOfO += 1;
				break;	
			case 'u': case 'U':		//if u, then add 1 to numOfU
				numOfU += 1;
				break;
			default:				//if not a vowel, exit switch
				break;	
		} 

	}
}

//function to output results
void outputData()
{
	//output entered sentence
	fout <<"The vowels in the sentence \"" <<sentence
		 <<"\" are:" <<endl <<endl;
		 
	//output amount of A/a's found	 
	fout <<"A/a:\t" <<aAmount <<endl;
	//output amount of E/e's found
	fout <<"E/e:\t" <<eAmount <<endl;
	//output amount of I/i's found
	fout <<"I/i:\t" <<iAmount <<endl;
	//output amount of O/o's found
	fout <<"O/o:\t" <<oAmount <<endl;
	//output amount of U/u's found
	fout <<"U/u:\t" <<uAmount <<endl <<endl;
	
	//output total amount of vowels found
	fout <<"Total: \t" <<aAmount + eAmount + iAmount + oAmount + uAmount;
	fout <<endl <<endl;
}
