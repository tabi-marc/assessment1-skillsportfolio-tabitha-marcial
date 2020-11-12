#include <iostream>
using namespace std;

int main()
{
	//A header to give the user the idea of the program.
	cout << " --------------------" << endl;
	cout << "|        INPUT        |" << endl;
	cout << "|     A R R A Y S     |" << endl;
	cout << " ---------------------" << endl;

	int printArray[5]; //Declaring of variable for array.
	int a, b; //Declaring a variable for user input and display output.
	cout << "\nEnter five numbers: " << endl; //Asks user input of five integers.
	cout << "--------------------" << endl;

	//For loop to get five values from the user.
	for (int a = 0; a < 5; a++)
	{
		cout << "\nInteger= ";
		cin >> printArray[a];
	}

	//For loop to display the five values.
	for (int b = 0; b < 5; b++)
	{
		cout << "Print [" << printArray[b] << "]" << ". ";
	}

	return 0;
}
