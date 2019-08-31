#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void inputData(string& sent, int& length);
void changeCase(int length, string sent);

ifstream fin;
ofstream fout;

int main()
{
	string sent;
	int length;
	
	fin.open("_Document.txt");
	fout.open("_Code.txt");
	
	inputData(sent, length);

	changeCase(length, sent);
	
	fin.close();
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
	getline(fin, sent);
	length = sent.length();
}
