# Chapter 3 - Furthering Functions

In this chapter we continue refreshing our knowledge from last year by recapping the basics of functions before focusing on the more advance aspects and introducing some new concepts relating to functions. The use of functions was not required in your Utility app assessments in CodeLab I, however the form an essential part of the Data Driven App assessment in CodeLab II. Thus, getting to grips with functions and understanding how to use them effectively by making use of parameters and return values should be a key learning objective.

* [Recapping the Basics](#recapping-the-basics)
  * [Function Structure](#function-structure)
  * [Invoking Functions](#invoking-functions)
  * [Declaring and Defining Functions](#declaring-and-defining-functions)
    * [Declaring](#declaring)
    * [Defining](#defining)
  * [Passing Parameters](#passing-parameters)
  * [Returning Values](#returning-values)
* [Variable Scope](#variable-scope)
* [Passing by Value vs Passing by Reference](#passing-by-value-vs-passing-by-reference)
  * [Passing by Value](#passing-by-value)
  * [Passing by Reference](#passing-by-reference)
  * [Const References](#const-references)
* [Default Parameters](#default-parameters)
* [Function Overloading](#function-overloading)
* [Static Function Variables](#static-function-variables)

&nbsp;
&nbsp;

## Recapping the Basics

Functions allow us to break our programs down into specific tasks, which can be called again and again when needed. This makes our program easier to understand as larger problems can be broken down into its small logical component parts. Functions also make our programs more efficient as we reduce duplicate code; rather than writing out the same code over and over again, we can place the task in a function and call it when we need to.

Every C++ program has at least one function, which is the main. Our goal when programming should be to make the main function as simple as possible by passing control to other functions to perform their respective tasks.

&nbsp;
&nbsp;

### Function Structure

The structure of a function is as follows

```
return_type function_name( parameter list ) {
   //body of the function
}
```

*Return type:* specifies the type of data the function should return (e.g. int, bool, double, string etc) back to the main program. If the function does not return anything void can be used as the return type


*Function name:* Name of the function, this can be anything but usually we specify a name that relates to the task the function performs. E.g. a function named displayMenu would be sensible for a function that displays a menu of options to the user.


*Parameter list:* When calling a function you can pass it some values that the function can then use to perform its task. We define the parameters a function can be passed in the parameter list. We can specify multiple parameters for use in a function in a comma separated list. For each one we must specify its data type (e.g. int, double, string etc). Parameters are optional, they can be left blank.


*Function body:* The function body is where we include our set of statements that define the functions task.

&nbsp;
&nbsp;

#### Simple example

```C++
void sayHello(){
    cout << "Hello World" << endl;
}
```

In our above example the structure of our function is as follows:

*Return type:* we specify void as our function doesn’t return a value

*Function name:* Name of the function, this can be anything but usually we specify a name that relates to the task the function performs. So in this example we use helloWorld(). For a function that displays a menu we might use the name displayMenu();

*Parameter list:* When calling a function you can pass it some values that the function can then use to perform its task. In this basic example aren’t passing in any values so we leave this parameter list blank.

*Function body:* The function body is where we include our set of statements that define the functions task. This functions task is to simply output Hello World to the console so we have a single output statement

&nbsp;
&nbsp;

### Invoking Functions

To pass control to a function it must be called, or *“invoked”*. We do this by specifying the function name immediately followed by the parameter list enclosed in parentheses. Even if the function takes no parameters you must include the parameter list parentheses, but these can be left empty. For example to invoke our sayHello() function our full program would look like this:

```C++
#include <iostream>
using namespace std;

void sayHello(){
    cout << "Hello World" << endl;
}

int main(){
    sayHello();
    return 0;
}
```

&nbsp;
&nbsp;

### Declaring and Defining Functions

Functions should always be written outside of the ```main()``` function. If you have multiple functions, you should place them underneath one another in a logical order. The main function also needs to know that a function exists before it is called, otherwise it will throw an error. Therefore you should place functions before the program's main function. You to keep your code organised and keep your main function towards the top you can declare and define the function separately.

#### Declaring

Declaring a function refers to letting the compiler know that a function exists within the program. When declaring a function we let the compiler know the return type, the name of the function and any parameters the function takes when being invoked / called. Declaring should always be done ahead of the main function


#### Defining

Defining a function means we specify the full task the function will perform, so alongside all the information included when we declare a function, we also include the function body with the code statements required for our function to perform its task. Defining is typically done after the main function.

Previously the ```helloWorld();``` example was declared and defined at the same time. Below however, is an example of how we might declare our function ahead of the main, then define the function later on.

```C++
#include <iostream>
using namespace std;

void sayHello();

int main(){
    sayHello();
    return 0;
}

void sayHello(){
    cout << "Hello World" << endl;
}
```

Declaring and defining functions separately is the most basic form of code organisation we can perform when we first start using functions. [NEED LINK HERE] Later in the module we will look at how we can further organise our code across multiple files by making use of header files.  

&nbsp;
&nbsp;

### Passing Parameters

Functions become really useful when you begin passing parameters and returning values. This is what can make your programs more efficient as you can slightly alter the task being performed by the function by the parameter being passed without needing duplicate code.

For example, instead of a basic function that simply says Hello World all the time (which lets face it is fairly useless), instead we will create a function that takes a string parameter and outputs the message passed to it.

```C++
#include <iostream>
using namespace std;

void logMessage(string msg);

int main(){
    logMessage("Hello CodeLab");
    return 0;
}

void logMessage(string msg){
    cout << msg << endl;
}
```

Our previous ```helloWorld()``` function has only been modified slightly in the above example:

* The function name has been altered to ```logMessage()``` as this is now more appropriate to describe the task being performed
* A parameter has been added to the parameter list (string msg), so that the function can accept values being passed to it. Note you can pass as many parameters as you wish into a function and these can be of any data type. The only rules are you specify the data type and provide a variable name that can be used when referring to that parameter in the function (*Note: the name of the parameter does not need to match that of the value being passed in - remember we can pass any value of the parameters type to the function and reuse it multiple times).*
* When invoking the function we now need to include a value in the parameter list parentheses as the function is expecting a parameter. When invoking functions with parameters you need to pass values to all the parameters included in the function declaration. In our above example the value “Hello CodeLab” will get passed to the string msg variable in the function
* The output statement in the function body now outputs the msg variable that gets passed in when the function is invoked.

As this function now accepts parameters we can change the value being passed in each time it is invoked and therefore change the message being displayed to the console. For instance take a look at the code below which now makes use of the ```logMessage()``` function three times. The first two times we pass in a string value directly and the program will output “Hello CodeLab” followed by “I love programming”.

Before we invoke the function a third time, we ask the user what they would like to say and store this input into the string variable userInput. The value the user inputs is then used to set the logMessage parameter. Therefore what the user enters will then get displayed back to the console.

```C++
#include <iostream>
using namespace std;

void logMessage(string msg);

int main(){
    logMessage("Hello CodeLab");
    logMessage("I love programming");

    cout << "What would you like to say" << endl;
    string userInput;
    getline(cin, userInput);
    logMessage(userInput);
    return 0;
}

void logMessage(string msg){
    cout << msg << endl;
}
```

&nbsp;
&nbsp;

### Returning Values

So far when invoking the functions above all the functionality has been performed within the function body and nothing has been returned back to the main program. This is why we have been using void as the function return type.

However there may be instances where we want the function to perform a task and return a value back to the main program (or back to another function it has been invoked from). The returned value may then be used to influence what happens next in the program.

&nbsp;
&nbsp;

#### Greetings Example

Take the example below, in it we have a greetings function that takes an integer parameter. This integer is used within the function to determine if it is morning or afternoon and return a string message back to where the function has been invoked accordingly. Note string has been specified as the function return type as this is the type we want to return from the function

We make use of this function In the main program where we ask the user what the time is and pass the entered value when invoking the function. Notice the invoking of the function has been included within a ```cout``` statement as the value being returned is a string and can be directly inserted into the output stream. In essence the call to the ```greetings()``` function gets replaced by the returned value.

When running this program any values below 12 will output *Good Morning*, whilst values above 12 will output *Good Afternoon*

```C++
#include <iostream>
using namespace std;
// return type set to string as this function will return a string value back to main program
string greetings(int time){
    //evaluate int value passed in and set return message
    if(time < 12){
        return "Good Morning";
    }else{
        return "Good Afternoon";
    }
}
int main(){
    cout << "What time is it?" << endl; //ask the user for time
    int userInput; //variable to store user response
    cin >> userInput; //get user input

    //output string returned by function
    cout << greetings(userInput) << endl;     
    return 0;
}
```

&nbsp;
&nbsp;

#### Display Menu Example

This second example uses the returned value from the displayMenu function to then determine what happens next in the program. Note that the displayMenu function has int as its return type as this is the data type returned to the main program after the user has selected an option.

As the return type is an int you will notice the call to the function has been included as the switch statement expression. Remember this function call will get replaced by the returned value so ```displayMenu()``` will become either 1, 2, 3, or 4 based on the user input.

This value can then be evaluated in the switch statement and the program will progress accordingly. Whilst only simple output statements have been used in the switch statement as an example it is easy to see how further functions could be called from here to control the program, e.g. ```displayHighscores()```.

```C++
#include <iostream>
#include <string>
using namespace std;
/* return type set to int as this function will return int value back to main program */
int displayMenu(){     
     //output menu options
    cout << "What would you like to do?" << endl;
    cout << "1: Play Game" << endl;
    cout << "2: View Highscores" << endl;
    cout << "3: Edit Options" << endl;
    cout << "4: Exit" << endl;
    int option; //variable for user input
    cin >> option; //get user input
    return option; //return value user enters back to main program
}
int main() {
    //switch statement to evaluate value returned from display menu function
    switch(displayMenu()){ //call to display menu will become value returned by function (e.g. 1, 2, 3, or 4)
        case 1://if displayMenu value matches case run the code inside case
            cout << "Playing Game" << endl;
            //loadGame(); ← example function that could be called next
            break;
        case 2:
            cout << "Viewing Highscores" << endl;
            //displayHighscores(); ← example function that could be called next
            break;
        case 3:
            cout << "Editing Options" << endl;
            break;
        case 4:
            cout << "Exiting" << endl;
            break;
    }
    return 0;
}
```

&nbsp;
&nbsp;

## Variable Scope

Not a programming technique itself, but an important concept to understand; scope relates to the visibility of the variables we declare in our programs. Where variables are declared influences which parts of the program can then access said variables. There are two types of scope:

* Local - declared inside a block of code { } and only accessible to that block (and any nested blocks).
* Global - declared outside the main function and accessible to the entire program.

Last year a number of you declared lots of variables globally to make them easily accessible to the entirety of your program. However, you should aim to limit the amount of global variables you declare and instead make use of function parameters to pass values to different parts of your program. This helps aid the ‘security’ of your code. Review the example code and comments below to understand the visibility of different local and global variables within the sample program.

```C++
#include <iostream>
using namespace std;

int globalVar = 10; //global variable available within rest of program;

void func1(){
    int localVar = 20; //local variable only available within this function
    localVar += globalVar; //notice the use of global variable here
    cout << "Func1: " << localVar << endl;
}

int main() {
    int localVar2 = 12; // local variable only available within whole main function
    localVar2 += globalVar; // notice can also use global variable here
    cout << "Main: " << localVar2 << endl;
    cout << localVar << endl;
    //above line will throw an error as localVar is only available in func1()

    func1(); // call to func1
    int num1 = 10; // num1 available within whole main function
    if(num1 > 9){
        num1++;
        cout << num1 << endl;
        int num2 = 20; // num2 available only with if statement block;
    }
    cout << num2 << endl;
    //above line will throw an error as num2 only available in block it was
    //declared.


    for(int i = 0; i < 20; i++){
        cout << i << endl; //i is declared in the loop so only accessible here      
    }
    cout << "i after loop is" << i << endl; //i is not accessible here            

    return 0;
}
```

&nbsp;
&nbsp;

## Passing by Value vs Passing by Reference

So far when we have been passing parameters to functions we’ve been passing these by value. What this means is that when a value is passed to the function, rather than passing the actual value itself a copy is made. Any task performed on the parameter in the function is therefore performed on a copy rather than the value passed in when the function was invoked.

In the majority of instances this is fine, especially with basic data types such as int and char, which have a low memory footprint. However when using larger data types, or passing containers such as arrays passing by value can result in unnecessary overhead as there will be two copies of the parameter in existence while the function is running. There may also be instances where you want any modification on the value passed into the function to persist after the function finished running, which won’t happen if passing by value as the modifications occur on a copy.

Instead what we can do is pass by reference, which means instead of making copies of passed in parameters, the function works directly on the original parameter values. Therefore reducing any potential overhead.

The syntax difference for passing by value versus passing by reference is subtle. To pass by reference we use the address of operator (&) when specifying the parameters in the function declaration. For instance the address operator ahead of msg in the below example means any value passed to this function will now be passed by reference and not copied, but accessed directly

```C++
void logMessage(string &msg);
```

So far the difference between passing by value and passing by reference may be confusing. However, take a look at the following code to see it in action.

&nbsp;
&nbsp;

### Passing by Value

```C++
#include <iostream>
using namespace std;

// pass-by-value
void increment(int num) {
    num = num + 1;
    cout << "num in increment " << num << endl; // num is altered here
}

int main() {
    int num = 3;
    increment(num);
    cout << "num in main " << num << endl; // num is not altered here

    return 0;
}
```

This above example passes by value just like we are currently used to. If you run the code you should find that num gets increased to 4 in the increment function, but num remains 3 in the main program. This is because a copy of num has been modified in the increment function

&nbsp;
&nbsp;

### Passing by Reference

```C++
#include <iostream>
using namespace std;

// pass-by-reference
void increment(int &num) { // note the & operator appended before the parameter variable
    num = num + 1;
    cout << "q in increment " << num << endl; // num is altered here
}

int main() {
    int num = 3;
    increment(num);
    cout << "num in main " << num << endl; // num is altered here too

    return 0;
}
```

The only difference with this example and the previous one is the inclusion of the address of operator ahead of the num parameter in the increment function. This declares that the parameter will be passed by reference instead of by value. This means the value passed to the function will be acted upon directly. Therefore if you run this code you will notice that num is incremented to 4 in the function and this modification persists on num in the main program is this was the variable directly modified.

&nbsp;
&nbsp;

### Const References

There may be times where you want to pass parameters by reference but don’t want these parameters to be modified. To ensure they don’t get modified in the function you can declare them as const.

For example the below function takes two strings as parameters and returns the result of concatenating them (adding them together). Rather than make copies of the strings being passed in, we can reduce the overhead by passing by reference. However, we want to guarantee that the values passed in (str1 and str2 in this case), don’t get modified.

We can do this by declaring these parameters as const in the function declaration, which prevents the function from modifying them but offers direct access to them. Thus, const references function similar to passing by value, but with efficiency benefits for parameters of larger types.

```C++
#include <iostream>
using namespace std;

string concatenate (const string &s1, const string &s2){
    //any attempt to modify s1 and s2 in the function will cause an error
    //e.g. s1 = "Hello" <-- this won't work
    return s1+s2;
}
int main(){
    string str1 = "Code";
    string str2 = "Lab";
    cout << "Concatenated strings: " << concatenate(str1, str2) << endl;
    return 0;
}
```

## Default Parameters

In C++ we can include default values for function parameters. This means that if no values are specified when invoking the function the default values will be used. To include a default value for a parameter you just use the assignment operator and provide the desired value when declaring the function. Lets use our earlier logMessage function for an example.

Here you will see “Hello Word” has been assigned as the default value for the msg parameter. In the main program the function is then invoked twice. The first time “Hello CodeLab” is passed in as a value, therefore this will override the default and be output to the console. The second time the function is invoked no parameter is passed and therefore the default will be used.

```C++
#include <iostream>
using namespace std;

void logMessage(string msg = "Hello World"){ //default value included
    cout << msg << endl;
}
int main(){
    logMessage("Hello CodeLab");//passed in value, will override default

    logMessage(); //no parameter passed, default will be used

    return 0;
}
```

You can give some parameters default values and others not in the same function. However, if doing so defaults should be assigned right to left. For example in the program below we have a simple sum function, which has two parameters, both of which have been given defaults.

```C++
#include <iostream>
using namespace std;

int sum(int a = 10, int b = 5){ //function with default int values
    return a+b;
}

int main(){
    //passing in 20 here overrides first default value (e.g. 10)
    int result = sum(20);
    cout << result << endl; //will output 25
    return 0;
}
```

If we were to add another parameter to the sum function (e.g. int c), we would have to specify a default argument as the preceding parameter has on. Similarly int b must have a default value in this example because int a has one. We could however not specify a default for ```a``` and keep the default on int ```b```.

This is shown in the example below where a third parameter is added and given a default value. The defaults are then assigned right to left, with the left most value not given a default. Therefore, when invoking the function at least one value must be passed in for int a, the others can be omitted and the defaults will be used.

```C++
#include <iostream>
using namespace std;

int sum(int a, int b = 5, int c = 40){ //function with some defaults
    return a+b+c;
}

int main(){
    /*
    - Have to pass first value for a as there is no default,
    - Second value passed in overrides b
    - No third value provided so default of 40 used
    \*/
    int result = sum(11, 10);
    cout << result << endl; //will output 61
    return 0;
}
```

&nbsp;
&nbsp;

## Function Overloading

C++ allows you to have two or more functions that use the same name. This is called function overloading. In order to do so the different functions must have either different parameter types or a different number of parameters. Functions cannot be overloaded by just changing the return type.

When invoking overloaded functions the compiler will determine which function to use based on the parameter values used when calling the function. Overloading saves you from having to come up with multiple different names for functions that perform very similar tasks. For instance our example below includes 4 functions that all display information to the console. However each displays slightly different data. Rather than name them all slightly differently we can use the same function name and the compiler will work out which to use based on the data passed in.

```C++
#include <iostream>
#include <string>
using namespace std;
void display(int a){
    cout << "Integer value is: " << a << endl;
}
void display(double a){
    cout << "Double value is: " << a << endl;
}
void display(string a){
    cout << "String values is: " << a << endl;
}
void display(string name, int age){
    cout << "My Name is: " << name;
    cout << ", I am " << age << " years old." << endl;
}
int main(){
    display(10); //will use integer function (first one)
    display(5.435); //will use double function (second one)
    display("Hello World"); //will use string function (third one)
    display("Jake Hobbs", 30); //will use function with string and int
    return 0;
}
```

## Static Function Variables

The static keyword has different meanings in C++ depending where its used. The first example we are going to look at is static variables inside functions.

When a variable is declared as static in a function space for the variable gets allocated only once for the duration of the program. Therefore, even if the function is called multiple times the variable does not get reallocated and thus the value will persist through to subsequent function calls. You can think of declaring something static as saying that the variable sticks around, maintaining its value, until the program completely ends. Therefore the use of static can be useful for preserving information.

This is demonstrated in the following two simple programs. The first doesn’t declare the ```count``` variable in the ```demo()``` function as static. Therefore, every time the function gets called the count variable gets reallocated in memory and released as soon as the function ends. The resulting output is therefore:

```
0 0 0 0 0
```

```C++
#include <iostream>
using namespace std;

void demo()
{
    // standard int variable
    int count = 0;
    cout << count << " ";
    // value is incremented
    // however the value is released from memory at end of function
    count++;
}

int main(){
    for (int i=0; i<5; i++){
        demo();
    }
    return 0;
}
```

The second example declares count as static in the function. Therefore the variable gets allocated once for the duration of the program and its value persists through multiple calls. As the value gets incremented each time the function is called the output will therefore be:

```
0 1 2 3 4
```

```C++
#include <iostream>
using namespace std;

void demo()
{
    // static variable
    static int count = 0;
    cout << count << " ";

    // value is updated and
    // will be carried to next
    // function calls
    count++;
}

int main(){
    for (int i=0; i<5; i++){
        demo();
    }
    return 0;
}
```

