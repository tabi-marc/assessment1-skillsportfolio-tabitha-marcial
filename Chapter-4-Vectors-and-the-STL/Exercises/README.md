# Chapter 4 - Exercises

Exercises with a tick mark :ballot_box_with_check: represent exercises that must be submitted for *Option 1* of the Programming Skills Portfolio as a minimum expectation. Completing more exercises provides the opportunity to attain higher marks. For each exercise you should create a _**new project**_ with the name of the exercise and save it to this exercises folder in your local repository.

Once you have completed your solution you should make sure you commit and push your solutions to your remote repository on GitHub. You can commit and push as many changes to your solutions as you wish, only those pushed before the chapter deadlines will be marked for the Programming Skills Portfolio.

&nbsp;
&nbsp;

## Exercise 1 - Input Vectors :ballot_box_with_check:

Write a program that puts 5 integer values provided by the user into a vector. Output the vector to the console.

&nbsp;
&nbsp;

## Exercise 2 - Vector Workout :ballot_box_with_check:

Write a program that does the following:

* Create an int vector with 10 values
* Output the list using a for loop
* Output the highest and lowest value
* Resize the vector 20 elements
* Output the list
* Assign values to the ten new elements
* Output the list
* Push two new elements to the list
* Output the list
* Pop two elements off the list
* Output the first and last elements of the list
* Clear the vector
* Output the size of the vector
* Check if the vector is empty

You will need to make use of the vector class methods to complete this task. For reference:
https://en.cppreference.com/w/cpp/container/vector

&nbsp;
&nbsp;

## Exercise 3 - Shopping List

Write a program that does the following

* Create an empty string vector.
* Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list.
* Output the list.
* Sort the list into alphabetical order.
* Output the list
* Remove the first element from the list.
* Output the list.
* Insert the item, "coffee" at the beginning of the list.
* Output the list.
* Find the item, "sugar" and replace it with "honey."
* Output the list.
* Insert the item, "baking powder" before "milk" in the list.
* Output the list.

You will need to make use of the vector class methods to complete this task. For reference:  
https://en.cppreference.com/w/cpp/algorithm

&nbsp;
&nbsp;

## Exercise 4 - Duplicate Checker

The following shopping list was written in a rush and may contain duplicates. Using appropriate algorithm and vector methods write a program that finds and removes duplicate elements from the list. Once the duplicates have been removed output the new shopping list to the console.

```C++
vector<string> shoppingList = {"Milk", "Bread", "Coffee" , "Tea", "Sugar", "Bananas", "Apples", "Milk", "Coffee"};
```

&nbsp;
&nbsp;

## Exercise 5 - Weather Data Vector

Chapter 2 included an exercise for [storing weather data in an array](../../Chapter-2-Advancing-Arrays/Exercises#exercise-10---weather-data). Convert this program so that it uses vectors and suitable algorithm functions to output max, min & averages.

&nbsp;
&nbsp;

## Exercise 6 - Sports League

A sporting league is divided into four divisions, each division has eight teams and each team is named after its home town, e.g:

| Division 1    | Division 2    | Division 3   | Division 4   |
|---------------|---------------|--------------|--------------|
| Southampton   | Portsmouth    | Basingstoke  | Newbury      |
| ...           | ...           | ...          | ...          |
| ...           | ...           | ...          | ...          |
| ...           | ...           | ...          | ...          |
| ...           | ...           | ...          | ...          |
| ...           | ...           | ...          | ...          |
| ...           | ...           | ...          | ...          |
| ...           | ...           | ...          | ...          |

Write a program to store the names of the teams in a two-dimensional table and code a menu driven system to interrogate the table and display the following information:

* On the input of a division number, list the teams in that division.
* On the input of a division number and team position, give the name of the team.
* Upon entering the league position, list the teams in that position in all four divisions.

&nbsp;
&nbsp;

## Exercise 7 - Pairs & Tuples :ballot_box_with_check:

Create a program that declares, initialise and outputs the values stored in a pair and tuple.

* The pair should include the name of a football team (string) and their league position (int).
* The tuple should include the name of a city (string), its temperature (double) and wind speed (int).

&nbsp;
&nbsp;

## Exercise 8 - Vending Machine Upgrade

Create a simple vending machine that makes use of either pairs or tuples to group together the product information. The program should:

* Present the available products to the user
* Allow them to select the product
* Ask them to input their money
* Handle change / Error message if not enough money entered.

&nbsp;
&nbsp;

## Exercise 9 - Student Map :ballot_box_with_check:

Create a map that stores at least 5 student numbers as the keys (int) and student names as the elements (string). The program should ask the user to enter a student number and then output the name of the student associated with that number. If no student is found you should output an error message.

&nbsp;
&nbsp;

## Exercise 10 - Map Quiz

Using a map create a quiz program. The key should contain the question and the element should include the answer. For example:

```C++
map<string, string> quiz{
    { "Q1: Who is the Chancellor of Bath Spa University", "Jeremy Irons"},
    { "Q2: Who created the C++ Programming Language", "Bjarne Stroustrup"},
 };
```

The program should allow the user to answer the questions and recieve a score at the end.

