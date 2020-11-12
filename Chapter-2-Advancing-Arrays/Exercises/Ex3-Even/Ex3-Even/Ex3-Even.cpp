#include <iostream>
using namespace std;

int main()
{
    //A header to give the user the idea of the program.
    cout << " --------------------" << endl;
    cout << "|        EVEN        |" << endl;
    cout << "|    H I G H E R     |" << endl;
    cout << " ---------------------" << endl;

    int a; //Declaring of variable.
    int largestValue = 0; //Declaring of variable to store the value.
    int testingArray[7] = { 15, 2, 6, 11, 12, 13, 9 }; //Declaring of variable in array.

    //Display the testingArray integers.
    cout << "\nThe integers are: ";
    for (const int& n : testingArray)
    {
        cout << n << " | ";
    }

    //A for loop to create a condition.
    for (int a = 0; a < 7; a++)
    {
        //An if statement to examine the even numbers amongst the testingArray integers using a modulus operator.
        if (testingArray[a] % 2 == 0 && testingArray[a] > largestValue) //Checks the remainder when divided by 2 and also inspects if the testingArray integers are more than the largestValue.
        {
            largestValue = testingArray[a]; //If that's the case then both the largestValue and integer must be equal.
        }
    }
    cout << "\nThe highest even number amongst the integers: " << largestValue << endl; //Displays the largest even number.

    return 0;
}
