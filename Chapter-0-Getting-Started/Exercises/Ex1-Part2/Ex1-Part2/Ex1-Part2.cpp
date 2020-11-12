#include <iostream>
using namespace std;

int main()
{
    //Declaring of variable and user input for first name.
    string firstname;
    cout << "What is your first name? ";
    cin >> firstname;

    //Declaring of variable and user input for last name.
    string lastname;
    cout << "What is your family name? ";
    cin >> lastname;

    //Declaring of variable and user input for hometown.
    string hometown;
    cout << "Where is your hometown? ";
    cin >> hometown;

    //Console output from the user input.
    cout << "\nMy full name is " << firstname << " " << lastname << "." << endl << "I grew up in the " << hometown << ".";

    return 0;
}
