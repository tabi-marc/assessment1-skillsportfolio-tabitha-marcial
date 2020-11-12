#include <iostream>
using namespace std;

int main()
{
	//A header that shows the idea of the program.
	cout << " ________________________________________" << endl;
	cout << "|                                        |" << endl;
	cout << "| + - % FUNDAMENTAL MATH OPERATORS % * / |" << endl;
	cout << "|________________________________________|" << endl;

	//Declaration of variables to acquire user input.
	int a, b;
	cout << "\nEnter the first number: ";
	cin >> a;
	cout << "\nEnter the second number: ";
	cin >> b;

	//The basic mathematical operations.
	cout << " ________________________________________" << endl;
	cout << "|                                        |" << endl;
	cout << "| + Sum of the two numbers: " << a + b << endl;
	cout << "| - Difference of the two numbers: " << a - b << endl;
	cout << "| * Product of the two numbers: " << a * b << endl;
	cout << "| / Quotient of the two numbers: " << a / b << endl;
	cout << "| % Remainder of the two numbers: " << a % b << endl;
	cout << "|________________________________________|" << endl;

	return 0;
}
