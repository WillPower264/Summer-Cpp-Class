/*William Li
CSC 133-GW
Lab12a.cpp*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_OF_CAND = 5;				//declare NUM_OF_CAND as const int set 5

void getData(string lastNames[], int votes[]);	//declare function prototypes
int sumVotes(const int votes[]);
void findPercentages(double total, const int votes[], double percentages[]);
void findWinner(int votes[], string lastNames[], string& winner);
void outputResults(string lastNames[], int votes[], double percentages[], 
	 			   double total, string winner);

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

ifstream fin;							//declare input stream variable
ofstream fout;							//declare output stream variable

int main()
{	
	fin.open("Lab12ain.txt");			//open input stream
	fout.open("Lab12aout.txt");			//open output sream
											   		  	   
	string lastNames[NUM_OF_CAND];	//declare array lastNames size NUM_OF_CAND
	int votes[NUM_OF_CAND];			//declare array votes size NUM_OF_CAND
	double percentages[NUM_OF_CAND];//declare array percentages size NUM_OF_CAND
	int total;						//declare var total as int
	string winner;					//declare var winner as string
	
	getData(lastNames, votes);			//call function getData
	
	total = sumVotes(votes);			//call function sumVotes
	
	findPercentages(total, votes, percentages);	//call function findPercentages
	
	findWinner(votes, lastNames, winner);		//call function findWinner
	
	//call function outputResults
	outputResults(lastNames, votes, percentages, total, winner);
	
	system("pause");
	return 0;
}

//function to input data into arrays
void getData(string lastNames[], int votes[])
{
	//while i is less than NUM_OF_CAND, loop and increment i
	for (int i = 0; i < NUM_OF_CAND; i++)
		//read lastname and vote amount into parallel arrays at index i
		fin >>lastNames[i] >>votes[i];
}

//function to find the total of the votes
int sumVotes(const int votes[])
{
	double sum = 0.0;					//declare sum as double and set to 0.0
	
	//while i is less than NUM_OF_CAND, loop and increment i
	for (int i = 0; i < NUM_OF_CAND; i++)
		//add the number of votes to sum
		sum += votes[i];
	
	//return sum to main	
	return sum;	
}

//function to find the percentage of votes held by each candidate
void findPercentages(double total, const int votes[], double percentages[])
{
	//while i is less than NUM_OF_CAND, loop and increment i
	for (int i = 0; i < NUM_OF_CAND; i++)
		//assign value of the votes divided by the total times 100 
		//into array percentages
		percentages[i] = 100 * (votes[i] / total);
}

//function to find the winner of the election
void findWinner(int votes[], string lastNames[], string& winner)
{
	winner = lastNames[0];				//set the winner as the first candidate
	
	//while i is less than NUM_OF_CAND, loop and increment i
	for (int i = 1; i < NUM_OF_CAND; i++)
		//if a candidate gets more votes than the previous candidate, his or her
		//name is stored in winner
		if (votes[i] > votes[i - 1])
		   winner = lastNames[i];
}

//function to output the results of the election
void outputResults(string lastNames[], int votes[], double percentages[], 
	 			   double total, string winner)
{
	//output headers
	fout <<"Candidate \t    Votes Received   % of Total Votes" <<endl <<endl;

	//format output to show 3 sig digits
	fout <<fixed <<showpoint <<setprecision(3);
	fout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas
	
	//while i is less than NUM_OF_CAND, loop and increment i
	for (int i = 0; i < NUM_OF_CAND; i++)
		//output the candidate's name, amount of votes received, and percent 
		//of total votes casted
		fout <<lastNames[i] <<"   \t\t" <<votes[i] <<"\t\t" <<percentages[i] 
			 <<endl;
	
	//output the total amount of votes
	fout <<"Total   \t\t" <<static_cast<int>(total) <<endl <<endl;
	
	//output the winner of the election
	fout <<"The winner of the election is " <<winner <<".";
}
