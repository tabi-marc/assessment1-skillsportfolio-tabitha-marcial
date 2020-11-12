#include <iostream>
using namespace std;

int main()
{
	//A header to give the user the idea of the program.
	cout << " ________________________________" << endl;
	cout << "|             IS IT              |" << endl;
	cout << "|             EVEN               |" << endl;
	cout << "|_______________?________________|" << endl;

	int i; //Declaration of variable for the number.

	//Allows user to enter an integer.
	cout << "\nGive a number: ";
	cin >> i;

	//Calculation using a modulus operator to determine if the number is either even or odd.
	(i % 2 == 0) ? cout << i << " is an even number." : cout << i << " is an odd number.";

	return 0;
}

