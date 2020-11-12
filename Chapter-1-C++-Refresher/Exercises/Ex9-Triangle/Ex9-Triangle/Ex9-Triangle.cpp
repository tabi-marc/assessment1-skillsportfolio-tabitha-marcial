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

	int angle1, angle2, angle3; //Declaration of variables for the three angles of the triangle.

	//Input of three angles to check whether it is valid or not.
	cout << "\nEnter the first angle: " << endl;
	cin >> angle1;
	cout << "\nEnter the second angle: " << endl;
	cin >> angle2;
	cout << "\nEnter the third angle: " << endl;
	cin >> angle3;

	//Check whether the the three angles add up to 180.
	if (angle1 + angle2 + angle3 == 180)
	{
		cout << "\nIt is qualified as a triangle.";
	}
	else
	{
		cout << "\nIt is not a triangle!";
	}

	return 0;
}

