/*William Li
CSC 133-GW
Lab8e.cpp*/

#include <iostream>

using namespace std;

struct comma_facet : public std:: numpunct<char>				//to use commas
{protected: string do_grouping() const {return "\003" ; } };

int main()
{
 	//declare variables for num, iterations, largestIteration, and largest, 
	//which is set to 0
	int num, iterations, largestIteration, largest = 0;
	
	//prompt user to enter the first number of the sequence
	cout <<"Please enter the first number of the sequence: ";
	cin >>num;							//read number into var num
	cout <<endl;
	
	cout.imbue( locale( cout.getloc(), new comma_facet ) );		//to use commas

	//output the statement before listing the numbers in the sequence
	cout <<"The sequence is: " <<num;
	
	//while num is not 1, continue loop
	//increment iterations by 1 after each iteration
	for (int iterations = 0; num != 1; iterations++)
	{
 	 	//if number is even, then divide by 2 for the next number
		if (num % 2 == 0)
		    num = num / 2;
		    
		//if number is odd, then multiply by 3 and add 1    
		else
  			num = 3 * num + 1;
  			
  		//if the number is larger than the current largest number execute following statements
  		if (num > largest)
  		{
		   //assign number into largest
  		   largest = num;
  		   //assign largestIteration to value of iteration + 1
  		   largestIteration = iterations + 1;
  		}
  		cout <<" " <<num;
	}
	
	//output the largest number of the sequence and which place it appeared in 
	//the sequence
	cout <<"\n\nThe largest number is " <<largest <<" and it "
		 <<"is the " <<largestIteration <<" number in the sequence." <<endl;
	//output which place in the sequence the number 1 appeared
	cout <<"\nThe number 1 was the " <<iterations <<" number in the"
		 <<" sequence." <<endl <<endl;
	
	system("pause");
	return 0;
}
