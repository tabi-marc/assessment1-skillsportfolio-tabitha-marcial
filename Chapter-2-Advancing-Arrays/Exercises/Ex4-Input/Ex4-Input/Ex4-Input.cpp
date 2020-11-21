#include <iostream>
#include <array> //Include array header.
using namespace std;

int main()
{
	//A header to give the user the idea of the program.
	cout << " ____________________" << endl;
	cout << "|  STANDARD LIBRARY  |" << endl;
	cout << "|____ARRAY___INPUT___|" << endl;
	cout << "  ------------------" << endl;

	array <int, 5> userInput; //Declaration of variable for array.
	cout << "\nEnter five integer values: \n" << endl; //Asks user to enter five numbers.

	//A for loop to get user input five times.
	for (int a = 0; a < 5; a++)
	{
		cout << "Integer value= \n";
		cin >> userInput[a];
	}

	//Another for loop to display output five times.
	for (int b = 0; b < 5; b++)
	{
		cout << "Display [" << userInput[b] << "]" << ". ";
	}

	return 0;
}
