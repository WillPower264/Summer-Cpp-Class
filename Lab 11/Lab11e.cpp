/*William Li
CSC 133-GW
Lab11e.cpp*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int QUESTION_AMOUNT = 20;		   //declare const int QUESTION_AMOUNT as 20
const int ID_SIZE = 8;				   //declare const int ID_SIZE as 8

void getAnswers(char tOrF[]);		   //declare function prototypes	
void outputHeaders();
void activateLoop(char tempID[], char tempAnswers[], char answerKey[], 
	 			  int& tempScore, char& tempGrade);
void getID(char tempID[]);
int checkAnswers(char key[], char tOrF[]);
char getGrade(int score);
void outputResults(char ID[], char answers[], int score, char grade);


ifstream fin;							//declare input stream variable
ofstream fout;							//declare output stream variable

int main()
{
	fin.open("Lab11ein.txt");			//open input stream
	fout.open("Lab11eout.txt");			//open output stream
	
	char answerKey[QUESTION_AMOUNT];	//declare array answerKey size 20
	char tempAnswers[QUESTION_AMOUNT];	//declare array tempAnswers size 20
	char tempID[ID_SIZE];				//declare array tempID with ID_SIZE
	int tempScore;						//declare int tempScore
	char tempGrade;						//declare char tempGrade
	
	getAnswers(answerKey);				//call function getAnswers
	
	outputHeaders();					//call function outputHeaders
	
	//call function activate loop
	activateLoop(tempID, tempAnswers, answerKey, tempScore, tempGrade);
	
	fin.close();						//close input stream
	fout.close();						//close output stream
	
	system("pause");
	return 0;
}

//function to read the T/F answers from key and students
void getAnswers(char tOrF[])
{
	//read the first answer and store in first element
	fin >>tOrF[0];
	
	//while i is less than the question amount, loop and increment i
	for (int i = 1; i < QUESTION_AMOUNT; i++)
		//read the next char, whether it is a space or not
		fin.get(tOrF[i]);
}

//function to output the headers of the output file
void outputHeaders()
{
	//output headers
	fout <<"Student ID \t Student Answers \tScore \tGrade" <<endl <<endl;
}

//function to activate loop to proccess however many student's answers
void activateLoop(char tempID[], char tempAnswers[], char answerKey[],
	 			  int& tempScore, char& tempGrade)
{
	//loop while there is still input
	while (fin)
	{
		getID(tempID);					//call function getID
		getAnswers(tempAnswers);		//call function getAnswers
		//assign returned value of function checkAnswers into tempScore
		tempScore = checkAnswers(answerKey, tempAnswers);
		//assign returned value of function getGrade into tempGrade
		tempGrade = getGrade(tempScore);
		
		//call function outputResults
		outputResults(tempID, tempAnswers, tempScore, tempGrade);
	}
}	

//function to get the ID of each student
void getID(char tempID[])
{
	//while i is less than the ID size, loop and increment i
	for (int i = 0; i < ID_SIZE; i++)
		//read the characters of the ID into array tempID
		fin >>tempID[i];
}

//function to check the answers of the student against those in the key
int checkAnswers(char key[], char student[])
{
	int score = 0;						//declare score as int and set to 0
	
	//while i is less than QUESTION_AMOUNT, loop and increment i
	for (int i = 0; i < QUESTION_AMOUNT; i++)
	{
		//if the student skips an answer, add nothing to score
		if (student[i] == ' ');
		//if the student answers correctly, add 2 points to score
		else if (key[i] == student[i])
			score += 2;
		//if the student is incorrect, subtract 1 point from score	
		else 
			score -= 1;		
	}
	//return score back to main
	return score;
}

//function to calculate the letter grade based on score
char getGrade(int score)
{
	//declare percentage as a double and assign the value of the score as a 
	//double divided by the points available, and multiply the quotient by 100
	double percentage = 100 * (static_cast<double>(score) / 
						(QUESTION_AMOUNT * 2));
	
	//if the percentage is greater than 90, then return A
	if (percentage >= 90.0)
		return 'A';
	//if the percentage is greater than 80, then return B	
	else if (percentage >= 80.0)
		return 'B';
	//if the percentage is greater than 70, then return C	
	else if (percentage >= 70.0)
		return 'C';
	//if the percentage is greater than 60, then return D	
	else if (percentage >= 60.0)
		return 'D';
	//if the percentage is less than 60, then return F	
	else
		return 'F';				
}

//function to output the student ID, answer, score, and graderesults
void outputResults(char ID[], char answers[], int score, char grade)
{
	//while i is less than ID size, loop and increment i
	for (int i = 0; i < ID_SIZE; i++)
		//output student ID
		fout <<ID[i]; 
	
	fout <<"\t";
	
	//while i is less than QUESTION_AMOUNT, loop and increment i
	for (int i = 0; i < QUESTION_AMOUNT; i++)
		//output the student answer at each index
		fout <<answers[i];
		
	//output the score and the grade of the student	
	fout <<"\t" <<score <<"/40 \t  " <<grade <<endl;	
}
