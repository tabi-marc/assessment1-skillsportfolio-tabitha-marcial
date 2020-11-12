# Chapter 2 - Exercises

Exercises with a tick mark :ballot_box_with_check: represent exercises that must be submitted for the Programming Skills Portfolio as a minimum expectation. Completing more exercises provides the opportunity to attain higher marks. For each exercise you should create a _**new project**_ with the name of the exercise and save it to this exercises folder in your local repository.

Once you have completed your solution you should make sure you commit and push your solutions to your remote repository on GitHub. You can commit and push as many changes to your solutions as you wish, only those pushed before the chapter deadlines will be marked for the Programming Skills Portfolio.

---
&nbsp;

## Exercise 1 - Input Arrays :ballot_box_with_check:

Write a program that requests five numbers from the user and adds these into an array. Once the values have been inputted display them to the user in a nicely formatted list.

#### Extension Problem (Optional):

Prevent the user from entering invalid data.

&nbsp;
&nbsp;

## Exercise 2 - The Mad Hatter

The Mad Hatter likes to reverse words. Write a program that allows him to print out any given String in reverse. The user should be able to enter the word and the resulting output should say:

```
The Mad Hatter Says: word in reverse
```

&nbsp;
&nbsp;

## Exercise 3 - Even Higher :ballot_box_with_check:

Find and display the value that is the highest even number in an integer array. For testing the array should use the following values:

```
15, 2, 6, 11, 12, 13, 9
```

&nbsp;
&nbsp;

## Exercise 4 - Standard Library Array input :ballot_box_with_check:

Write a program that puts 5 integer values provided by the user into a *standard library array*. Once the values have been inputted display them to the user is a nicely formatted list.

#### Extension Problem (Optional):

Prevent the user from entering invalid data.

&nbsp;
&nbsp;

## Exercise 5 - Fix the World

I’ve got my letters all jumbled up! Make the below range based for loop output “Hello World” without altering the char array directly.

```C++
char letters[] {'I', 'f', 'm', 'm', 'p', '!', 'X', 'p', 's', 'm', 'e'};
for(auto i : letters){
    cout << i;
}
```

&nbsp;
&nbsp;

## Exercise 6 - Max Values :ballot_box_with_check:

Write a C++ program that will prompt the user to input ten integer values. The program should then determine the smallest and greatest of those values and display these to the console. You should complete this task using basic arrays.

#### Extension Problem (Optional):

* Adapt the solution to make use of Standard Library Arrays and appropriate algorithm functions

&nbsp;
&nbsp;

## Exercise 7 - 2D Average

Writes a program to find the average value of each column of a 2D array of type double

&nbsp;
&nbsp;

## Exercise 8 - Address Storage

Use a string multidimensional array to store the names and respective postcodes of 3 or more people you know. The data should be inputted by the user. Next have the program print out the details of each person on a new line, e.g.

  | Name   | Postcode |
  |--------|----------|
  | Bob    | A59 1LK  |

  &nbsp;
  &nbsp;

## Exercise 9 - Times Tables :ballot_box_with_check:

* Write a program that declares and empty 12 x 12 multidimensional array.
* Next make use of a nested for loop to assign the values of the 12 times table into the multidimensional array.
* Now use a second nested for loop to output the values in the multidimensional array. You should aim to neatly format the outputted values

Example Output:

```
1 times table:
---------------

1 x 1 = 1
1 x 2 = 2
1 x 3 = 3
1 x 4 = 4
1 x 5 = 5
1 x 6 = 6
1 x 7 = 7
1 x 8 = 8
1 x 9 = 9
1 x 10 = 10
1 x 11 = 11
1 x 12 = 12

2 times table:
---------------

2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20
2 x 11 = 22
2 x 12 = 24

etc
```

&nbsp;
&nbsp;

## Exercise 10 - Weather Data

Write a program that takes temperature data for the last 7 days for two emirates (e.g. Dubai and Ras Al Khaimah) and stores the data into a 2D array. Once the data is inputted do the following:

* Output the data to the console
* Display the highest, lowest and average temperature for each emirate.
* Display the highest, lowest and average temperature for the emirates combined

You can use either a built in array or a standard library array for this task. If using a standard library array remember the syntax for declaring a 2D array is:

```C++
array<array<int,7>, 2> temperatures;
```

