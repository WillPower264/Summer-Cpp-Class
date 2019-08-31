/*William Li
CSC 133-GW
Lab11d.cpp*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void inputData(string& sent, int& length);
void changeCase(int length, string sent);

ofstream fout;

int main()
{
	string sent;
	int length;
	
	fout.open("_Code.txt");
	
	inputData(sent, length);

	changeCase(length, sent);
	
	fout.close();
	
	return 0;
}

void changeCase(int length, string sent)
{
	for (int i = 0; i < length; i++)
		fout <<static_cast<int>(sent.at(i)) <<" ";
}

void inputData(string& sent, int& length)
{
	cout <<"Please enter a sentence to be converted into numbers: " <<endl;
	
	getline(cin, sent);
	length = sent.length();	
}
