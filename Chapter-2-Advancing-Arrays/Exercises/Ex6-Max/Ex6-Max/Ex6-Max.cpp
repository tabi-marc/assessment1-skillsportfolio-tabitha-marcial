#include <iostream>
using namespace std;

int main()
{
    //A header to give the user the idea of the program.
    cout << "* * * * * * * * * * * *  " << endl;
    cout << "*         MAX         *" << endl;
    cout << "*     V A L U E S     *" << endl;
    cout << "* * * * * * * * * * * *" << endl;

    int arr[10], i, most, least; //Declaration of variables.
    cout << "\nEnter ten integer values: \n"; //Asks user to input a maximum of ten numbers.

    //A for loop to get input 10 times.
    for (i = 0; i < 10; i++)
        cin >> arr[i];

    //A for loop to get the highest number.
    most = arr[0];
    for (i = 0; i < 10; i++)
    {
        if (most < arr[i])
            most = arr[i];
    }

    //A for loop to get the lowest number.
    least = arr[0];
    for (i = 0; i < 10; i++)
    {
        if (least > arr[i])
            least = arr[i];
    }
    cout << "\nSmallest integer value: " << least; //Display the least value amongst the numbers.
    cout << "\nGreatest integer value: " << most; //Display the most value amongst the numbers.

    return 0;
}
