#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("_Code.txt");
	
	int num;
	fin >>num;
	
	while (fin)
	{
		cout <<static_cast<char>(num);
		fin >>num;
	}
	
	cout <<endl <<endl;
	
	system("pause");
	return 0;
}
