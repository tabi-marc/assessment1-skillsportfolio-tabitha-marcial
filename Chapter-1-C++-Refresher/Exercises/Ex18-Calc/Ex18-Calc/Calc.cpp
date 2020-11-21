#include <iostream>
using namespace std;

int main()
{
	//A header to give the user the idea of the program.
	cout << "><><><><><><><><><><><><><><" << endl;
	cout << "><    SIMPLE CALCULATOR   ><" << endl;
	cout << "><   CHOOSE AN OPERATION  ><" << endl;
	cout << "><><><><><><><><><><><><><><" << endl;

	int op; //Declared a variable for the mathematical operations.
	float a, b; //Declared two variables for the two operands.

	//Prompts user to choose an operation.
	cout << "\nPress a number to start." << endl;
	cout << "\n1. (+)Add\n";
	cout << "\n2. (-)Subtract\n";
	cout << "\n3. (*)Multiply\n";
	cout << "\n4. (/)Divide\n";
	cout << "\n5. (%)Modulus\n";
	cout << "<><><><><><><><><><><><>" << endl;
	cin >> op; //Gets the user's choice of operation to store in int op.

	//Prompts user to enter two numbers to operate from.
	cout << "\nEnter the first value: " << endl;
	cin >> a; //Gets the first number to store in float a.
	cout << "\nEnter the second value: " << endl;
	cin >> b; //Gets the second number to store in float b.

	//An if else statement to meet all conditions of the operations.
	if (op == 1)
	{
		cout << "\nThe sum of two numbers: " << a << " " << "+" << " " << b << " " << "=" << " " << a + b << endl;
	}
	else if (op == 2)
	{
		cout << "\nThe difference of two numbers: " << a << " " << "-" << " " << b << " " << "=" << " " << a - b << endl;
	}
	else if (op == 3)
	{
		cout << "\nThe product of two numbers: " << a << " " << "x" << " " << b << " " << "=" << " " << a * b << endl;
	}
	else if (op == 4)
	{
		cout << "\nThe quotient of two numbers: " << a << " " << "/" << " " << b << " " << "=" << " " << a / b << endl;
	}
	else if (op == 5)
	{
		cout << "\nThe modulus of two numbers: " << a << " " << "%" << " " << b << " " << "=" << " " << (int)a % (int)b << endl;
	}

	return 0;
}
