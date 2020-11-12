#include <iostream>
using namespace std;

int dTrouble(int var) //A return function in single parameter.
{
    //A header to give the user the idea of the program.
    cout << " --------------------" << endl;
    cout << "-     D O U B L E    -" << endl;
    cout << "-    T R O U B L E   -" << endl;
    cout << " --------------------" << endl;

    var = var * 2; //Value is multiplied by 2.
    cout << "\nThe original value is: "; //A return statement.
    return var;
}

int main()
{
    int b = 88; //Declaration of integer variable. 
    cout << dTrouble(b) << endl; //A return value output.
    cout << "\nThe output value is: " << b << endl;  //An output statement.
    return 0;
}
