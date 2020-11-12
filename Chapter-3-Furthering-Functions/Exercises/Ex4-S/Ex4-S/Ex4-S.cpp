#include <iostream>
using namespace std;

void square();
void circle();
void triangle();

int main()
{
	//A menu header for users to choose an operation from.
	cout << "\nChoose an operation!" << endl;
	cout << "* * * * * * * * * * * * * * * * * * *" << endl;
	cout << "1: Calculate the area of a square.\n";
	cout << "2: Calculate the area of a circle.\n";
	cout << "3: Calculate the area of a triangle.\n";
	cout << "* * * * * * * * * * * * * * * * * * *" << endl;

	int calArea; //Declare variable to store user's answer.
	cin >> calArea; //Acquires user's answer.

	//A switch statement to check user input and handle errors.
	switch (calArea)
	{
	case 1:
		square();
		break;
	case 2:
		circle();
		break;
	case 3:
		triangle();
		break;
	default:
		cout << "\nError! Try again!" << endl;
		break;
	}

	return 0;
}

void square() //Calculation for the area of square.
{
	double num1;
	cout << "\nEnter length of square side: "; //Asks user to enter side length of the square.
	cin >> num1;
	cout << "\nThe area of square: " << num1 * num1 << endl; //Operation to get area of square: length of side x length of side.
}

void circle() //Calculation for the area of circle.
{
	double radius;
	double pi = 3.14159265359;
	cout << "\nEnter radius: "; //Asks user to enter radius of the circle.
	cin >> radius;
	cout << "\nThe area of circle: " << pi * (radius * radius) << endl; //Operation to get area of circle: pi x (radius x radius).
}

void triangle() //Calculation for the area of triangle.
{
	double b, h;
	cout << "\nEnter base: "; //Asks user to enter base of the triangle.
	cin >> b;
	cout << "\nEnter vertical height: "; //Asks user to enter height of the triangle.
	cin >> h;
	cout << "\nThe area of triangle: " << (b * h) / 2 << endl; //Operation to get area of triangle: one-half x base x height.
}
