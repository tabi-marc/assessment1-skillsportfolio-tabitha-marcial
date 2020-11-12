#include <iostream>
using namespace std;

int tDoubled(int& val) //A return function with the use of reference.
{
    //A header to give the user the idea of the program.
    cout << " --------------------" << endl;
    cout << "-    T R O U B L E    -" << endl;
    cout << "-    D O U B L E D    -" << endl;
    cout << " --------------------" << endl;

    val = val * 2; //Value is multiplied by 2.
    cout << "\nThe original value is: "; //A return statement.
    return val;
}

int main()
{
    int i = 99; //Declaration of integer variable. 
    cout << tDoubled(i) << endl; //A return value output.
    cout << "\nThe output value is: " << i << endl;  //An output statement.
    return 0;
}
