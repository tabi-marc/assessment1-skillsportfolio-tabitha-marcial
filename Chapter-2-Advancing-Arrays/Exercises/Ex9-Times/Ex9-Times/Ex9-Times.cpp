#include <iostream>
using namespace std;

int main()
{
	int arr[12][12]; //Declaration of the multidimensional array.

	for (int i = 1; i < 13; i++) //An outer loop for rows.
	{
		for (int j = 1; j < 13; j++) //An inner loop for columns.
		{
			(i + 1)* (j + 1); //The multiplication table will start with value 1.
		}
	}

	//Output of the multiplication table.
	for (int i = 1; i < 13; i++)
	{
		//Header for the multipication table.
		cout << i << " " << "Multiplication" << " " << "Table" << endl;
		cout << "- - - - - - - - - - - -" << endl;

		//Result of the product calculation.
		for (int j = 1; j < 13; j++)
		{
			cout << i << " x " << j << " = " << i * j << " \n";
		}
		cout << endl;
	}

	return 0;
}
