#include <iostream>
using namespace std;

int main()
{
	//A header to give the user the idea of the program.
	cout << "* * * * * * *  * * * * * * *" << endl;
	cout << "*     DAYS OF THE WEEK     *" << endl;
	cout << "* * * * * * *  * * * * * * *" << endl;

	int d; //Declaration of variable for days to get user input.
	cout << "\nEnter a number from (1-7): " << endl;
	cin >> d;

	//Switch statement to print output of days of the week.
	switch (d)
	{
	case 1:
		cout << "\nIt's Monday!" << endl;
		break;
	case 2:
		cout << "\nIt's Tuesday!" << endl;
		break;
	case 3:
		cout << "\nIt's Wednesday!" << endl;
		break;
	case 4:
		cout << "\nIt's Thursday!" << endl;
		break;
	case 5:
		cout << "\nIt's Friday!" << endl;
		break;
	case 6:
		cout << "\nIt's Saturday!" << endl;
		break;
	case 7:
		cout << "\nIt's Sunday!" << endl;
		break;
	default:
		cout << "\nNot included on the days of the week!" << endl;
	}

	return 0;
}

