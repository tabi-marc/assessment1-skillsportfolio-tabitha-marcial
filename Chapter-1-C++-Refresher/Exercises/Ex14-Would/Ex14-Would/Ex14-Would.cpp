#include <iostream>
using namespace std;

int main()
{
    //A header to give the user the idea of the program.
    cout << "......................." << endl;
    cout << ".      WOULD YOU      ." << endl;
    cout << ".       LIKE TO       ." << endl;
    cout << ".      CONTINUE?      ." << endl;
    cout << "......................." << endl;

    //Declaration of variable for user input and number of times the program executed.
    char a;
    int num = 0;

    //Do while loop statement to repeat loop as long as the condition is true.
    do
    {
        cout << "\nWould you like to continue (Y/N)? " << endl; //A question to collect user input.
        num++; //Increments num by 1.
        cin >> a;
        a = toupper(a); //Converts character to uppercase.
    }
    //If 'Y' is chosen, it will just continue to loop whereas if 'N' is chosen, program will exit with the count of how many times the program executed.
    while (a == 'Y');
    cout << "\nLoop is terminated and it ran " << num << " times." << endl; //Shows count of loop.

    return 0;
}

