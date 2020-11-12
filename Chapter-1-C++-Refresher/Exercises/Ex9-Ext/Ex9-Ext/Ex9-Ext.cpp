#include <iostream>
using namespace std;

int main()
{
	//A header that shows the idea of the program.
	cout << "          *" << endl;
	cout << "        *   *" << endl;
	cout << "       *     *" << endl;
	cout << "      * IS IT *" << endl;
	cout << "     *    A    *" << endl;
	cout << "    *  TRIANGLE *" << endl;
	cout << "   *      ?      *" << endl;
	cout << "  * * * * * * * * *" << endl;

	int a1, a2, a3; //Declaration of variables for the three angles of the triangle.
	int side1, side2, side3; //Declaration of variables for the three sides of the triangle.

	//Calculation of the three angles to check whether it is valid or not.
	cout << "\nEnter the first angle: " << endl;
	cin >> a1;
	cout << "\nEnter the second angle: " << endl;
	cin >> a2;
	cout << "\nEnter the third angle: " << endl;
	cin >> a3;

	//Check whether the the three angles add up to 180.
	if (a1 + a2 + a3 == 180)
	{
		cout << "\nIt is qualified as a triangle.\n" << endl;

		//A header that shows the idea of the program.
		cout << "          * *" << endl;
		cout << "        *     *" << endl;
		cout << "       *       *" << endl;
		cout << "      *   WHAT  *" << endl;
		cout << "     *  TRIANGLE *" << endl;
		cout << "    *   IS THIS   *" << endl;
		cout << "   *        ?      *" << endl;
		cout << "  * * * * * * * * * *" << endl;

		//User input for the three lengths of each side of the triangle.
		cout << "\nEnter the length of first side: ";
		cin >> side1;
		cout << "\nEnter the length of second side: ";
		cin >> side2;
		cout << "\nEnter the length of third side: ";
		cin >> side3;

		//Calculation of the three sides of the triangle to determine whether it is an equilateral, isosceles, or scalene triangle.
		if (side1 == side2 && side2 == side3 && side3 == side1)
		{
			cout << "\nThis is an Equilateral Triangle!";
		}
		else if (side1 == side2 || side1 == side3 || side2 == side3)
		{
			cout << "\nThis is an Isosceles Triangle!";
		}
		else
		{
			cout << "\nThis is a Scalene Triangle!";
		}
	}
	else
	{
		cout << "\nIt is not a triangle!";
	}

	return 0;
}

