#include <iostream>
#include <vector> //Added vector header to access its functions.
using namespace std;

int main()
{
	//A header for users to see the main idea of the program..
	cout << "\t --------------------------" << endl;
	cout << "\t  I N P U T  V E C T O R S " << endl;
	cout << "\t --------------------------\n" << endl;  

	vector<int> myIntValues(5); //Initializing values inside the vector.
	cout << "\tEnter five integer values: " << endl;
	for (int i = 0; i < 5; i++) //A for loop conditioned to execute the program five times.
	{
		cout << "\tValue" << "[" << i + 1 << "]" << ": " << " ";
		cin >> myIntValues[i];
	}

	cout << "\n\tVector list: " << endl;
	for (int i = 0; i < 5; i++) //A for loop conditioned to output the program five times.
	{
		cout << "\tVector" << "[" << i + 1 << "]" << ": " << myIntValues[i] << endl; //Retrieves the data from user input.
	}
}

