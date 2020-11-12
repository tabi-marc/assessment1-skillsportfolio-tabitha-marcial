#include <iostream>
using namespace std;

//Declare functions.
void add();
void subtract();
void multiply();
void divide();
void modulus();

int main()
{
	char enter; //Declare variable to continue looping the program.

	//A do while loop to get input from the user.
	do
	{
		//A display header to give the user the idea of the program.
		cout << "\n><><><><><><><><><><><><><><" << endl;
		cout << "><      CALCULATOR        ><" << endl;
		cout << "><   CHOOSE AN OPERATION  ><" << endl;
		cout << "><><><><><><><><><><><><><><" << endl;

		cout << "\n><><><><><><><><><><><><><><" << endl;
		cout << "1. (+) Addition\n";
		cout << "2. (-) Subtraction\n";
		cout << "3. (x) Mutiplication\n";
		cout << "4. (/) Division\n";
		cout << "5. (%) Modulus\n";
		cout << "><><><><><><><><><><><><><><" << endl;

		int calCulator; //Declare variable for user input.
		cin >> calCulator; //Acquires the user's answer.

		//A switch statement to examine user input and also an error handler.
		switch (calCulator)
		{
		case 1:
			add();
			break;
		case 2:
			subtract();
			break;
		case 3:
			multiply();
			break;
		case 4:
			divide();
			break;
		case 5:
			modulus();
			break;
		default:
			cout << "\nError! Please try again!\n";
		}

		//An option to continue using the program.
		cout << "\nEnter 'C' to continue: ";
		cin >> enter;
	} while (enter == 'c' || enter == 'C'); //The program will continue to loop as long as the user answers yes.

	return 0;
}


void add() //Calculation for addition of the two numbers.
{
	double a, b;
	cout << "\nEnter the first number: ";
	cin >> a;
	cout << "\nEnter the second number: ";
	cin >> b;
	cout << "\nThe sum of the two integers: " << a + b << endl;
}

void subtract() //Calculation for subtraction of the two numbers.
{
	double a, b;
	cout << "\nEnter the first number: ";
	cin >> a;
	cout << "\nEnter the second number: ";
	cin >> b;
	cout << "\nThe difference of the two integers: " << a - b << endl;
}

void multiply() //Calculation for multiplication of the two numbers.
{
	double a, b;
	cout << "\nEnter the first number: ";
	cin >> a;
	cout << "\nEnter the second number: ";
	cin >> b;
	cout << "\nThe product of the two integers: " << a * b << endl;
}

void divide() //Calculation for division of the two numbers.
{
	double a, b;
	cout << "\nEnter the first number: ";
	cin >> a;
	cout << "\nEnter the second number: ";
	cin >> b;
	cout << "\nThe quotient of the two integers: " << a / b << endl;
}

void modulus() //Calculation to get the remainder of the two numbers.
{
	double a, b;
	cout << "\nEnter the first number: ";
	cin >> a;
	cout << "\nEnter the second number: ";
	cin >> b;
	cout << "\nThe remainder of the two integers: " << int(a) % int(b) << endl;
}
