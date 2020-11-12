# Chapter 1 Exercises

Exercises with a tick mark :ballot_box_with_check: represent exercises that must be submitted for the Programming Skills Portfolio as a minimum expectation. Completing more exercises provides the opportunity to attain higher marks. For each exercise you should create a _**new project**_ with the name of the exercise and save it to this exercises folder in your local repository.

Once you have completed your solution you should make sure you commit and push your solutions to your remote repository on GitHub. You can commit and push as many changes to your solutions as you wish, only those pushed before the chapter deadlines will be marked for the Programming Skills Portfolio.  

---
&nbsp;

## Exercise 1 - Print :ballot_box_with_check:

Write a C++ program that prints the following messages

*You are 10 years old*  
*You are too young to play the game*

&nbsp;
&nbsp;

## Exercise 2 - Arrows

Write a C++ program to print the asterisk pattern shown below

```
     *
    ***
   *****
  *******
 *********
    ***  
    ***
    ***
```

&nbsp;
&nbsp;

## Exercise 3 - PI

Create a program to calculate the circumference and area of a circle from the radius. The program should ask the user to enter the desired radius of the circle.

PI is defined as: ```3.14159```
Area is defined as: ```PI * radius * radius```
Circumference is defined as: ```PI * Radius * 2```

&nbsp;
&nbsp;

## Exercise 4 - User Input / Output

Write a C++ program to prompt the user to input her/his name, age and hometown and print these details on the screen. The format of text should look like the sample output below but you can only use a **single cout** when outputting the information.

```
Your Name is: Alpha
Your Age is: 22
Your Hometown is: Ras Al Khaimah
```

&nbsp;
&nbsp;

## Exercise 5 - Number Input / Output

Write a C++ program to prompt the user to input 3 integer values and print these values in forward and reversed order in a similar format to the below.

```
Please enter your 3 numbers: 12 45 78

Your numbers forward:
12
45
78


Your numbers reversed:
78
45
12
```

&nbsp;
&nbsp;

## Exercise 6 - Maths

Write a C++ program to produce a table in the output as shown below. You should use the maths operators on the x and/or y variable to achieve the results. One math operator should be used for each line in the following order: Addition, Subtraction, Multiplication, Division, Modulus.

| x value | y value | results |
| ------- | --------| ------- |
| 10      | 5       | 8       |
| 10      | 5       | 3       |
| 10      | 5       | 25      |
| 10      | 5       | 2       |


The tab escape character "\t" might be useful to format the console output table e.g:
```C++
cout << "x value" << "\t" etc...
```

&nbsp;
&nbsp;

## Exercise 7 - More Maths

Write a C++ program to produce a table in the output as shown below. You should use the maths operators on the x and/or y variable to achieve the results. One math operator should be used for each line in the following order: Addition, Subtraction, Multiplication, Division, Modulus.

| x value | y value | results |
| ------- | --------| ------- |
| 10      | 5       | 15      |
| 10      | 5       | 7       |
| 10      | 5       | 250     |
| 10      | 5       | 5       |
| 10      | 5       | 2       |

&nbsp;
&nbsp;


## Exercise 8 - So Much Maths :ballot_box_with_check:

Write a program that evaluates the following calculations for two int numbers obtained from the user and outputs the results to the console:

Sum (+)  |  Diff (-)  |  Product (x) |  Quotient (/) |  Remainder (%)

&nbsp;
&nbsp;

## Exercise 9 - Is it a Triangle? :ballot_box_with_check:

Write a program that checks if 3 angles given can make a triangle (the angles should add up to 180). The program should ask the user to enter values for 3 angles then output appropriate feedback.

#### Extension Problem (Optional):

If valid, as the user for the length of the sides and have the program correctly classify the type of triangle as either: Equilateral, Isosceles or Scalene ([see here](https://www.mathsisfun.com/triangle.html))

&nbsp;
&nbsp;

## Exercise 10 - Is it even? :ballot_box_with_check:

Write a program that allows the user to input a number and checks whether the number is even or not using the Ternary operator.

&nbsp;
&nbsp;

## Exercise 11 - Is it a Letter?

Write a program to input a character and check whether the character is in the alphabet or not using the Ternary operator.

&nbsp;
&nbsp;

## Exercise 12: What’s the Max

Write a program to input two numbers and out which is largest using the Ternary Operator.

#### Extension Problem (Optional):

Extend the program so that it accepts the input of three numbers and outputs the largest using the Ternary operator.

*Hint - You will need to use multiple ternary operators in a single statement*

&nbsp;
&nbsp;

## Exercise 13 - Days of the Week :ballot_box_with_check:

Write a program that accepts a number (1-7) then using a switch statement outputs what day of the week it is (e.g. 1 = Monday).

#### Extension Problem (Optional):

Handle invalid input (e.g. letters and numbers outside specified range).

&nbsp;
&nbsp;

## Exercise 14 - Would you Like to Continue? :ballot_box_with_check:

Write a program that implements a while loop. This program should ask the user if they would like to continue and use the while loop to keep looping as long as they enter the letter Y. Once the while loop has terminated output the number of times it executed.

&nbsp;
&nbsp;

## Exercise 15 - Fizz Buzz

Write a program that prints the numbers from 1 to 100. But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. For numbers which are multiples of both three and five print “FizzBuzz”.

&nbsp;
&nbsp;

## Exercise 16 - Fix This While You're Here :ballot_box_with_check:

Fix and improve this while loop code so the user can only enter valid data.

```C++
#include <iostream"
using namespace;

int main() {
	int counter = 0;
	char Endnow = 'N';

	while (counter < 5 & endnow != 'Y')
	{
		counter-+
		cout < "counter" < counter  < " /n";
		cout < "Do you want to end the loop now, enter Y or N ?"
		cin > EndNow;
	}
	return 0;
}
```

&nbsp;
&nbsp;

## Exercise 17 - Case Switcher

Write a program that swaps the upper and lower case letters in the sentence below:

```
CoDeLaB iS gReAt. I lOvE c++
```

Desired result:
```
cOdElAb Is GrEaT. I LoVe C++
```

*Hint: Make use of [isupper](http://www.cplusplus.com/reference/cctype/isupper/) and [islower](http://www.cplusplus.com/reference/cctype/islower/) to achieve this*

&nbsp;
&nbsp;

## Exercise 18 - Simple Calculator :ballot_box_with_check:

Write a C++ program that will display the following calculator menu:

1. Add
2. Subtract
3. Multiply
4. Divide
5. Modulus

The program will prompt the user to choose the operation choice (from 1 to 5). Then it asks the user to input values for the calculation. The program outputs the results of the calculation.

#### Extension Problem (Optional):

* Allow the user to keep entering values until they enter Q to quit.
* Handle incorrect input
