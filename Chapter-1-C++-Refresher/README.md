# Chapter 1 - C++ refresher

You should be familiar with the contents covered in this chapter, which serves as a refresher to the material covered in CodeLab I. If you find yourself struggling with any of the concepts and/or exercises included in this chapter you should make the time to revisit the module CodeLab I. A solid understanding of these concepts is essential in order to advance with the concepts introduced in CodeLab II. Don't hesitate to arrange a 1-2-1 tutorial if you are struggling to understand these fundamental programming techniques.

* [The Basics](#the-basics)
   * [Coding Conventions](#coding-conventions)
   * [Variables and Data Types](#variables-and-data-types)
   * [Constants](#constants)
   * [Non-Primitive Data Types](#non-primitive-data-types)
   * [Input / Output Stream](#input-output-stream)
   * [Structure of a C++ Program](#structure-of-a-c-program)
   * [Operators](#operators)
* [If Statements](#if-statements)
   * [Compound Conditions](#compound-conditions)
* [New Concept: Ternary Operators](#new-concept-ternary-operators)
* [Switch Statements](#switch-statements)
* [Loops](#loops)
   * [While Loop](#while-loop)
   * [Do While](#do-while)
   * [For Loop](#for-loop)

## The Basics

### Coding Conventions

The importance of Coding Conventions is crucial (*and not always followed last year in CodeLab!!*). Keeping your code neat and tidy not only helps you find your way around, but helps others understand your work when looking for help. Neat code can save you hours when trying to fix errors and its importance should not be underestimated (which is why its part of the marking criteria for the Data Driven App assessments!). As a reminder here are six tips that should help you keep your code organised so you can make sense of it when you return to it at a later date.


#### 1 - Program Descriptors

Add a couple of commented lines right at the very top of your programme that describes, in the simplest terms, what the program does.


#### 2 - Comments

Beginners should annotate their code with comments to remind them what certain commands do. For example, the first time you type

```C++
cout << "Hello World" << endl;
```

it wouldn’t hurt to place a comment next it that says…

```C++
// This is how you print to the console in C++.
```

As your programmes become more complex, you can use comments to make it easier to find certain code blocks, or remind you to finish certain coding tasks. Comments act like bookmarks in this sense.


#### 3 - Variable Names

Variable names should be unambiguous and where possible, short. For example if I was writing a programme that asks for a user's name, I would save their input in a variable called usersName. Seems obvious, but you’d be surprised how often variable names such as ‘a’ or ‘x’ are used. This is lazy and makes understanding what is happening in the program much harder.


#### 4 - CamelCase

If you use more than one word for a variable name (e.g. myInteger), make sure you capitalise each word. Most people only capitalise from the second word onwards (e.g. myFavouriteFood).


#### 5 - Whitespace

Write code as if you were writing an instruction manual. Keep everything in line (unless you have to indent - more on this later), and only break up code blocks with blank lines if it makes sense to do so. Think of code blocks as paragraphs with short sentences that should be kept together until the next sentence is clearly the beginning of a new set of instructions.


#### 6 - Indentation

Indentation helps identify where code blocks begin and end. Code blocks in C++ are wrapped in a pair of curly braces { }, and the code inside the block should be indented by 1 tabbed space. If nesting a code block inside another this would be tabbed again. See the example below.

```C++
#include <iostream>
using namespace std;

int main() { // this is the start of the main program code block

    //code inside the block is indented by one tabbed space
    cout << "Hello, World!" << endl;
    cout << "This is a simple C++ program" << endl;

    if(6 < 7){//this is the start of a second code block
        //code inside this block is indented a further tabbed space
        cout << "6 is less than 7" << endl;
    }

    return 0;

} //this is the end of the main program code block
```

&nbsp;
&nbsp;
&nbsp;

### Variables and Data Types

Variables are a place where we store pieces of information for use in our programs. We provide variables with names we can recall later to either access or modify the values stored in the variable. By the nature of their name the information stored in a variable can change. However, whilst the value can change in C++ it must remain the same data type.

C++ has four main primitive data types

* Int (whole numbers)
* Double (decimal number)
* Char (single character)
* Bool (True or False)

When declaring a variable we must state what type of data it will store and give it a name. We can give variables (almost) any name, but do ensure you give it a sensible name that relates to the job it performs. When declaring a variable we can initialise its value by using the assignment operator ( = ), followed by the value we wish to assign.

```C++
//declare & initialise variables
int wholeNum = 6;
double decNum = 5.345;
char singleCharacter = 'd';
bool booleanValue = true;
```

Variables can be left uninitialised, simply by leaving out the value assignment. However, you must ensure it is initialised before accessing it later in the program

```C++
int myNum; //declare variable but don't initialise

//some code
//some more code

myNum = 6; //initialise variable later in the program
```

&nbsp;
&nbsp;
&nbsp;

### Constants

When we want to store some information in our program we create a variable. As their name suggests the values stored in a variable can change (they can vary!). If you have a value that shouldn’t be altered you can declare this as a constant by using the ```const``` keyword at the beginning of the variable declaration. Variables declared as a constant cannot have their value changed.


#### An Example

Let’s say we wanted to create a simple maths program and wanted to store the value of PI in a variable. The value of PI is   the same so we don’t want this to change, else it could interfere with other calculations in our program. Therefore, it would make sense to declare our PI variable as a constant.

```C++
const int PIVALUE = 3.14159265359;
```

Constant variable names are typically written in all capital letters to easily identify them as constants in the program.

&nbsp;
&nbsp;
> **Advanced Note** - In C++11 the auto keyword was included to allow a variable data type to be inferred from the value its initialised with.
>
>  ```C++
>  int myFirstInt = 5; //explicitly declared integer variable
>  auto mySecondInt = 6; //variable data type automatically inferred from the value assigned
>  ```
> For the declaration of simple variables with one of the core data types (int, char, double), it is best to be explicit and you would not use auto. Auto is typically used when your programs become much more complex and you are using complex types available in C++.
>
>Further Information
>
>https://en.cppreference.com/w/cpp/language/auto  
>
>https://www.learncpp.com/cpp-tutorial/4-8-the-auto-keyword/
&nbsp;
&nbsp;

&nbsp;
&nbsp;
&nbsp;

### Non-Primitive Data Types

In C++ we also have access to non primitive data types. These are different to the above mention primitive types as they are objects obtained from core library classes (or custom made ones). These objects usually contain enhanced functionality beyond primitive data types that allow the objects to be manipulated.


#### Strings

Strings are one of the most widely used objects in programming. They hold a sequence of characters surrounded by double quotation marks “ on both sides and can contain any characters.

```C++
string str1 = "Hello"
string str2 = "Hello World"
string str3 = "CodeLab"
```

When you want to begin manipulating strings in your program you will need to include the string header.

```C++
#include <string>
```

As noted above, as strings are an object stemming from the String Class they offer access to enhanced functionality that allows the objects to be manipulated or obtain information about them. For example:

```C++
string str1 = "Hello";
cout << str1.length() << endl; //will output 5

str1.append(" World"); //adds World to original string
cout << str1 << endl; //will output Hello World

//replace contents of string beginning a 6th character
str1.replace(6, 5, "CodeLab");
cout << str1 << endl; //will output Hello CodeLab
```

Further reading: http://www.cplusplus.com/reference/string/string/

Other non-primitive types we will use in future sessions are Arrays and Vectors, which act as containers for multiple variables/objects. We will also learn how to create our own data types and objects when begin explore Object Oriented Programming (OOP).

&nbsp;
&nbsp;
&nbsp;

### Input / Output stream

The ```#include <iostream>``` directive written at the top of a C++ program provides us access to the C++ standard library input and output stream. We can use this functionality to get user input from the console and output information to the console.

We use ``cin`` and the extraction operator ```>>``` to get user input from the console

We use ``cout`` and the insertion operator ```<<``` to output information to the console.

&nbsp;
&nbsp;
&nbsp;

### Structure of a C++ Program

Every C++ program starts with the same main structure, including some preprocessor directives and the beginning of the program and importantly the main function. Hopefully this is all fresh in the memory from last year, but as a reminder refer to the comments and code breakdown for an explanation of the main elements of the program.

```C++
#include <iostream> // preprocessor directive - include iostream file
using namespace std; // declare use of the standard namespace

int main(){ // define main function
	cout << "Hello World" << endl; // output statement

	return 0; //return statement
}
```

&nbsp;
&nbsp;

#### Code breakdown

##### Preprocessor directive

```C++
#include <iostream> // preprocessor directive - include iostream file
```
Anything beginning with a #hash is a preprocessor directive that instructs the compiler to process this information before compiling of the rest of the code. The #include instruction acts like a copy and paste command and tells the compiler to copy and paste the contents of the iostream header file to the top of our program. The iostream header file contains the declarations for the standard input-output library in c++. We need this to gain access to things like cout which is the standard library output command for outputting content to the console.

&nbsp;
&nbsp;

##### Using Namespace Std

```C++
using namespace std; // declare use of the standard namespace
```
The contents of iostream that we’ve just added are part of the standard C library which includes lots of useful predeclared functionality for c++ programs. All the elements of this library are declared within a namespace in this case the std namespace. To access its functionality we need to let the compiler know we are using this standard namespace. With the namespace declared if the compiler encounters any undeclared identifiers in the code (e.g. cout), it will check to see if they are present within the namespace. If it is the program will proceed, otherwise it will throw an error. Declaring the use of the standard namespace saves us having to explicitly declare its use every time we use functionality from the library. For example if without declaring use of the std namespace our cout statement in our Hello World program would need to be written like the example below with std explicitly declared before both cout and endl as the functionality for come from the standard library:

```C++
std::cout << "Hello, World!" << std::endl;
```

&nbsp;
&nbsp;
> **Advanced Note** When starting out with small programs declaring using namespace std at the beginning of our programs saves times as we can avoid the constant explicit declaration as described above. However, when you become more proficient and begin writing more advanced programs it is advised that you avoid its declaration at the start of the program and do explicitly declare the namespace before operations like cout each time. This helps avoid potential conflicts between different libraries you might be using that are using the same names for different operations.

&nbsp;
&nbsp;

##### The Main Function
```C++
int main(){ // define the main function
      cout << "Hello World" << endl; // output statement
	return 0; //return statement
}
```
All C++ programs start with the execution of a **main function**. It is essential to have a main function otherwise your program simply will not work, this is the first thing the compiler looks for when executing C++ code. The word main is followed by a pair of parentheses followed by the body of the main function which will be enclosed by curly braces. The function body includes all the code that we want our program to run. C++ programs are executed line by line in order. Each line is a statement which is an expression that can produce a result. Statements are always terminated by a semicolon. Omitting the semicolon is probably the most common error when writing code. Try removing the semicolon at the end of the hello world statement, a red line should appear on that line in the IDE to indicate an error. These red lines are useful for helping find errors when writing your code.


The first line in our main function is an output statement. ```cout``` is the standard output stream in c++. Our ```cout``` statement is saying insert the sequence of characters for “Hello world” into the output stream. You will notice the two less than signs ```<<```  this is called the insertion operator. So we are inserting Hello World into the output stream.

We then insert something called ```endl```. This is an instruction to insert a newline then flush the contents of the output stream.

&nbsp;
&nbsp;
> **Advanced Note** - A new line can also be created by inserting the newline character ```\n``` within a string. The difference between ```endl``` and ```\n``` is ```endl``` flushes the output stream after adding the newline. Flushing the stream ensures the contents are outputted to the console in a timely manner. If you have several  ```cout``` statements one after the other, it may not be necessary to flush the stream at the end of each ```cout``` statement. Therefore you could use the newline character instead and then on the final line use ```endl``` to ensure the stream is flushed.
>```C++
> cout << "Hello, World! This is the first line \n";
> cout << "Here is a second line \n";
> cout << "Here is a third line \n";
> cout << "This fourth line will flush afterwards" << endl;
>```
>*Further Information:* https://www.geeksforgeeks.org/endl-vs-n-in-cpp/

&nbsp;
&nbsp;

##### Return Statement

The final line of the main function is the return statement. The return statement causes the main function to finish. Usually this is followed by a return code in our case 0, which is generally interpreted as the program worked as expected without errors.

&nbsp;
&nbsp;
> **Visual Studio Note** - When running the program on Visual Studio you may think it is not working. This is because the console window exits as soon as the return statement is reached, which happens so quickly it appears the program does not run. To force the console window to stay open include the following line before the return statement. This line of code waits for input e.g. pressing enter.
>
>  ```C++
>  system("pause");
>  ```

&nbsp;
&nbsp;

&nbsp;
&nbsp;
&nbsp;

### Operators

An operator in computer programming is a symbol that tells the compiler to perform specific mathematical, relational or logical operations.

#### Assignment Operator

The assignment operator is used to assign values to variables

```C++
string myString = "Hello World"; //assign value to myString
myString = "CodeLab"; //re-assign value to myString
```

#### Mathematical Operators

Used for performing mathematical calculations. These include the following operators:

```
	+ 	(additional)
	- 	(subtraction)
	/ 	(division)
	* 	(multiplication)
	% 	(modulus or ‘find remainder’)
```

```C++
int num1 = 5;
int num2 = 6;
int sum = num1 + num2;
cout << "Sum of numbers added: " << sum << endl; //should output 11

sum = num1 - num2;
cout << "Sum of numbers subtracted" << sum << endl; //should output -1
```

#### Relational Operators

Relational operators are used to create conditional expressions and will either evaluate to TRUE (1) or FALSE (0). This means relational operators can be used to make decisions in computer programs, e.g. if something is true do this, otherwise if its false do that

The following example illustrates the use of the less than relational operator: 7 < 10

This expression in words is saying “7 is smaller than 10”. This is a TRUE statement.

There are a number of relational operators:

```
	<	(less than)
	\> 	(greater than)
	\>= 	(greater than or equal to)
	<=	(less than or equal to)
	== 	(equality - is the same as)
	!= 	(inequality - is not the same as)
```

```C++
string str1 = "Hello";
string str2 = "World";

/* if statement uses the equality operator to create a condition that checks if the two strings are the same length */
if(str1.length() == str2.length()){
    cout << "Strings are the same length" << endl;
}
```

&nbsp;
&nbsp;

## If Statements

The if statement is the most common conditional statement and a cornerstone technique in computer programming. If statements allow us to make decisions in our programs. In its most basic form the if statement will execute a block of code if a condition is true, as seen in the previous string comparison example.

```
if(condition){
    //statements
}
```

We can extend the basic IF statement with an ELSE block, which will execute if the condition is FALSE.

```
if(condition){
    //statements
}else{
    //statements
}
````

We can see this branched decision making in the following flowchart diagram for the IF statement

<p align="center">
  <img src="https://jakehobbs.co.uk/markdown_images/IF-ELSE-Flowchart.png">
</p>

We can continue to extend the IF statement by using ELSE IF conditional checks. By using ELSE IF we add further conditions that will be evaluated if the previous ones are false. Take note that the conditions are evaluated in order and as soon as one evaluates to TRUE the corresponding code block will run and the IF statement will stop.

```C++
int x = 8;

if (x == 7){ //condition is FALSE corresponding code ignored
    cout << "x IS equal to 7" << endl;
}else if (x == 8){ //condition is TRUE run corresponding code
    cout << "x IS equal to 8" << endl;
    //execution ends here, all other conditions are ignored
}else if (x == 9){
    cout << "x IS equal to 9" << endl;
}
```

As shown above there may be multiple ELSE IF’s, each with their own conditional expression. Once one condition is met subsequent conditions are ignored. So beware of your ordering in some instances.

In the IF / ELSE IF structure either one (if a condition is true) or no blocks of code (if all conditions are false) will be executed. Terminating an IF / ELSE IF structure with an ELSE will ensure a statement is executed if no condition is met. For example:

```C++
int x = 9;

if (x == 7){
    cout << "x IS equal to 7" << endl;
}else if (x == 8){
    cout << "x IS equal to 8" << endl;
}else if (x == 9){
    cout << "x IS equal to 9" << endl;
}else{
    cout << "x IS NOT 7, 8 or 9" << endl;
}
```

&nbsp;
&nbsp;

### Compound Conditions

Each of the above examples only evaluate a single condition per IF (or ELSE IF) statement. Sometimes an IF statement needs more than one condition. For example, if two things have to be TRUE for some code to run. For this we need to make use of logical operators.


#### Logical Operators

Logical operators allow us to combine conditional expressions and create compound conditions. For example if we need two things to be true to perform an action, or need at least one of two things to be true.


#### Logical AND (&&)

If we need multiple things to all be true we use logical AND (&&). When using logical AND all the conditions need to evaluate to true. For example In the code below, if zombieAttack is true AND numBullets is equal to zero you should run!

```C++
bool zombieAttack = true;
int numBullets = 0;

if(zombieAttack == true && numBullets == 0){
    cout << "Run you fool!!!" << endl;
}
```


#### Logical OR (||)

If we need one OR another condition to be TRUE for a set of instructions to execute we use the logical OR operator. In a compound condition using logical OR the conditions will be evaluated until one results in TRUE. For example in our below example if the player has either armor or more than 5 bullets they can fight.

```C++
int numBullets = 0;
bool hasArmor = true;

if(hasArmor == true || numBullets > 5){
    cout << "Let's get ready to rumble!" << endl;
}
```


#### Multiple Logical operators

We can continue to extend our compound conditions with multiple logical operators. For example there is no point in entering into a fight unless there is something to attack. So our previous code has been extended to check three expressions. Now in order to fight there must be a zombie and the player must have either armour or more than five bullets.

```C++
bool zombieAttack = true;
int numBullets = 0;
bool hasArmor = true;

if( (zombieAttack == true) && (hasArmor == true || numBullets > 5) ){
    cout << "Prepare to feel my wrath!" << endl;
}
```

#### Logical NOT (!)

Logical NOT inverts the result of a condition. For example, if you put an exclamation mark in front of TRUE, it becomes FALSE. For example below we have two if statements to check the weather. The first uses the shorthand to check if isSunny is true. The second uses the logical NOT operator to invert this expression and checks if isSunny is NOT true.

```C++
bool isSunny = true;

if(isSunny){
    cout << "It's sunny, wear suncream" << endl;
}

if(!isSunny){
    cout << "It's not sunny, maybe take an umbrella" << endl;
}
```

&nbsp;
&nbsp;
&nbsp;

## New Concept: Ternary Operators

The ternary operator (or conditional operator as it is also known) offers a way of condensing IF ELSE statements.

```
expression ? trueValue : falseValue
```

It works by first evaluating the expression before the question mark operator. If the expression is true then the first value (before the colon) is assigned as the result. Else, if the first expression is false the second (after the colon) value is assigned as the result

This offers benefits over the IF statement whose results cannot be immediately assigned.

You will often see the ternary operator being used to assign max values, or set highscores among other tasks where you want to immediately assign the result of value comparisons.

Our example below demonstrates how a max value can be assigned more efficiently with the ternary operator than the equivalent IF statement.

```C++
int a = 10, b = 12;
int max = (a > b) ? a : b;
cout << max << endl;
```

vs

```C++
int a = 10, b = 12;
int max;
if(a > b){
    max = a;
}else if(a < b){
    max = b;
}
cout << max << endl
```

This second example shows how it might be used to set a high score. Imagine there are two variables in a game, one to store the players current score and another to store their previous high score. When the game is over we want to check if their current score is more than their high score. If it is we assign overwrite the previous high score with the current score, else it remains the same.

```C++
highScore = currentScore > highScore ? currentScore : highScore;
```

The results of the ternary operator don’t always need to be assigned, we could use the ternary operator to output messages based on the response. In the example below we use the ternary operator to output “Pass” if mark is more than 40, otherwise output fail.

```C++
int mark = 45;
(mark > 40) ? cout << "Pass" << endl : cout << "Fail" << endl;
```


## Switch Statements

The switch statement offers similar functionality to the IF statement but instead of evaluating a condition it evaluates a single value expression. The switch statement will then execute the case with the value that matches the expression. Note in C++ the switch can only accept single exact values (e.g. int or char).

```
switch (expression) {
    case Value1:
        //do something        	
        break;    
    case Value2:
        //do something        	
        break;   
    default:
       //do something   
}
```

Default cases can be included that will execute if the expression does not match any of the case values (like an ELSE in an IF statement).

The switch statement ends when it reaches a break. If no break is found following case statements will also be executed until a break is reached. Therefore, beware of accidentally leaving out a break as this may lead to unexpected results. However, there may also be times where you purposely want to leave out the break in order to group case values together that should execute the same lines of code, rather than duplicating the code in the cases. For example our example below groups together the upper and lower case letter values.

```C++
cout << "Game Over!! Would you like to play again (Y/N)?" << endl;
char input;
cin >> input;

switch (input) {
    case 'Y':
    case 'y':
        cout << "Game Restarting..." << endl;
        break;    
    case 'N':
    case 'n':
        cout << "Game Quitting..." << endl;
        break;
    default:
        cout << "Input not recognised..." << endl;
}
```

&nbsp;
&nbsp;

### Why use a switch instead of an IF statements

When you have many options you need to check the switch statement can provide greater clarity and readability of code. It can also offer some minor performance improvements compared to a long IF-ELSE statement.

However, as the switch statement can only accept single exact values in the expression there will be instances where you will have to use an IF-ELSE statement instead (e.g. for evaluating ranges).

&nbsp;
&nbsp;
&nbsp;

## Loops

Loops are used when we want to execute a code statement or several code statements multiple times. This saves us from repeating code in our programs, which should always be a core aim; to be as efficient as possible and reduce duplication. We can chose to execute a loop a given number of times, or we can keep looping repeatedly until a certain condition is met. C++ has three loops to serve these purposes.

* While Loop
* Do While Loop
* For Loop

&nbsp;
&nbsp;

### While Loop

The while loop is useful when we don’t know how many times we want the loop to run and just want it to keep repeating as long as a condition is TRUE. Therefore, the while loop has similarities to the IF statement, but instead of just executing once if a condition is TRUE the while loop keeps going (or iterating) until the condition is FALSE.

```
while ( condition ) {
	// do something WHILE the condition is true;
}
```

The below example shows the while loop in action, making use of ```cin.fail( );``` in the condition, which is a great way of doing some simple error checking.

The input stream (```cin```), knows what type of data it is expecting when awaiting user input. If a letter is entered when it's expecting an ```int``` then an error flag will be placed on the input stream and the result of ```cin.fail( );``` will evaluate to true. Therefore the while loop below will keep checking user input until valid data is entered.

```C++
cout << "Enter your age" << endl;
int age;
cin >> age;
while(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input.\nPlease enter a valid age:" << endl;
    cin >> age;
}
cout << "Your age is: " << age;
```

In the body of the while loop we then need to clear the error flag ```cin.clear( );``` and ignore what is left in the input stream as the invalid data will still be there. ```cin.ignore(1000, '\n');``` tells the input stream to ignore the next 100 characters, or the first new line character it encounters (whichever comes first). As the user will have hit enter when inputting the data it should encounter the new line character first. Now you are safe to ask the user for new data.

&nbsp;
&nbsp;

### Do While

The do while loop is a variant of a while loop, which evaluates the condition at the bottom of the loop instead of the top. This guarantees the block of code included in the loop will execute at least once. We can see the do while in comparison to the while loop below

```
while ( condition ) { //condition check at the top of loop
	// do something WHILE the condition is true;
}
```

vs

```
do {  
	// do something then check the condition;
} while ( condition ); //condition check at the bottom of loop
```

Note with the do while loop how the condition is included at the end of the loop after the code block to be executed which still appears within curly braces. Also note the semicolon at the end of the condition.

In our example below we know we always want the user to enter their password at least once, but if its invalid keep asking them. Therefore, with a do while loop we guarantee asking and receiving the users password before then checking to see if it matches the stored password.

```C++
string password = "1234password";
string userInput;

do{
    cout << "Enter your Password" << endl;
    cin >> userInput;
}while(password != userInput);

cout << "Welcome to the super secure banking area" << endl;
```

&nbsp;
&nbsp;

### For Loop

The for loop is very similar to the while loop, however its syntax means we can specify how many times we would like it to run for. When writing a for loop we have space for the *initialisation*, *condition* and *incrementation*.

```
for(initialisation; condition; incrementation){
	//statements
}
```

In the *initialisation* we declare a counting variable (typically named i) and set its value for use in the rest of the loop

In the *condition* we evaluate the counting variable against a certain condition. If it's true we run the loop, otherwise we exit the loop. Typically this condition will check if the counting variable is less than the number of times we want it to run.

In the *incrementation* we increase the counting variable to ensure the condition will eventually evaluate to false (e.g. it is no longer less than the number of times we want it to run).

For instance, if we want a for loop to run ten times we can create a variable called ```i``` in the *initialisation* and set it to ```0```, create a *condition* to check if ```i``` is less than ```10```, then use the *incrementation* to add 1 to ```i``` on each iteration. In the example below the statement inside the for loop simply outputs the value of i each time (e.g. 0 - 9).

```C++
for(int i = 0; i < 10; i++){
        cout << "I is" << i << "\n";
}
```

&nbsp;
&nbsp;

### Which loop when?

Each loop has unique traits that should make it easy to decide which to use in different scenarios. In simplest terms if you know how many times you want the loop to run you should use a for loop. This means for loops are typically used in combination arrays (or other container types) as we want to run the loop equal to the number of items stored in the array.

In opposition if you don’t know how many times you want the loop to run, make use of the while loop - picking the do while if you need to guarantee the execution of the code block once before checking the condition.
