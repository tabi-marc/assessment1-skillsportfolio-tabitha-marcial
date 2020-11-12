#include <iostream>
using namespace std;

int main()
{
    //A header to give the user the idea of the program.
    cout << "! ! ! ! ! ! ! ! ! ! ! !" << endl;
    cout << "!      FIX THIS       !" << endl;
    cout << "!       WHILE         !" << endl;
    cout << "!     YOU'RE HERE     !" << endl;
    cout << "! ! ! ! ! ! ! ! ! ! ! !" << endl;

    int counter = 0; //Variable for counting loops.
    char endNow = 'N'; //Variable to know if user wants to end program.

    while (counter < 5 && endNow != 'Y') //Loops until counter is less than five.
    {
        counter++; //Increments counter by 1.
        cout << "\nLoop iteration count =  " << counter << "\n"; //Produces the output of number of loops.
        cout << "--------------------------" << endl;

        cout << "\nWould you like to terminate program? \nEnter Y for Yes or N for No: " << endl; //User input to determine whether to close the program or continue to loop.
        cin >> endNow; //Acquires the user input to store in char.
        endNow = toupper(endNow); //Allows answer to be converted to uppercase.

        while (cin.fail() || (endNow != 'Y' && endNow != 'N')) //Another while loop to examine invalid user input.
        {
            cout << "\nIncorrect input! \nEnter Y or N again: " << endl; //Asks user to enter answer again. 
            cin >> endNow;
            endNow = toupper(endNow);
            cin.clear(); //Clears the errors on cin.
            cin.ignore(100, '\n'); //Skips to the next line.
        }
    }

    return 0;
}

