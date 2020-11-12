# Chapter 2 - Advancing arrays

In this chapter we continue refreshing our knowledge from last year by recapping the basics of arrays before focusing on the more advance aspects and introducing some new concepts relating to arrays.

* [Recapping the Basics](#recapping-the-basics)
   * [Why use an Array?](#why-use-an-array)
   * [Declaring and Initialising an Array](#declaring-and-initialising-an-array)
   * [Accessing the Array](#accessing-the-array)
   * [Iterating Through the Array](#iterating-through-the-array)
* [Range Based For Loop](#range-based-for-loop)
* [Auto Keyword](#auto-keyword)
* [Multidimensional Arrays](#multidimensional-arrays)
   * [Declaring a 2D Array](#declaring-a-2d-array)
   * [Initialising a 2D Array](#initialising-a-2d-array)
   * [Accessing a 2D Array](#accessing-a-2d-array)
   * [Iterating Through a 2D Arrayy](#iterating-through-a-2d-array)
* [Standard Library Arrays](#standard-library-arrays)
   * [Declaring the Array](#declaring-the-array)
   * [Accessing and Iterating Through the Array](#accessing-and-iterating-through-the-array)
   * [Standard Library Class Methods](#standard-library-array-class-methods)
* [Using the Algorithm Library](#using-the-algorithm-library)
* [2D Standard Library Array](#2d-standard-library-array)

&nbsp;
&nbsp;

## Recapping the Basics

An array is a type of storage container that can hold a fixed set of values of a single type. While basic variable only store a single value an array stores a series of them. Just like variables arrays must have a data type (int, double, char, etc), and can only store values of this type. Also once the size of an array has been set it cannot be changed.

### Why use an Array?

Arrays provide a more efficient solution of storing multiple pieces of data than variables.

Take for example this stack of variables that stores five student numbers:

```C++
int studentNumber1 = 323412;
int studentNumber2 = 373622;
int studentNumber3 = 387261;
int studentNumber4 = 318273;
int studentNumber5 = 362719;
```

Now consider we want to store the student number of every individual in Bath Spa University. Using variables alone, we would need over 7000 independent and unique variables! This is unmanageable.

Going back to our five student numbers, we could use one array to store each piece of data. The array could then be represented like this:

| <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|-------------|-------------|
| 323412 | 373622 | 387261 | 318273 | 362719 |

&nbsp;
&nbsp;

### Declaring and Initialising an Array

The below code shows how to declare an array. An array’s dimension is the number of elements it will contain.

```
dataType arrayName[dimension];
```

Notice the only difference between declaring a normal variable and an array is the addition of square brackets to the end of the name, which are used to declare the array size.

Here is an actual example of an array declaration:

```C++
int ages[5];
```

This declares an array that can hold 5 integer values.

There are a few components here that we need to address:

* *Data Type:* The type of data we wish to store (e.g. int, char, String etc)
* *The ```[ ]``` symbols:* This states that what we wish to declare is an array
* *Number of Elements:*  We need to tell the array object how many values we want to store in it. This is so it can allocate computer memory to store the values

The above array has only been declared and is currently an empty array of integers with 5 placeholders for integers available:

| <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|-------------|-------------|-------------|
| Index (position) | 0 | 1 | 2 | 3 | 4 |
| Value            |   |   |   |   |   |

*NB: The index (position) of elements in an array starts at 0 and not 1 as you might expect*

There are two ways we can initialise the array and assign values. The first is to access each array index and individually assign a value to each index using the assignment operator.

```C++
ages[0] = 19;
ages[1] = 23;
ages[2] = 22;
ages[3] = 30;
ages[4] = 18;
```

The second and more efficient method is to initialise the values at the same time as declaring the array. To do so we include a comma separated list of the values we wish to assign enclosed in curly braces after the array declaration.

```C++
int ages[] = { 19, 23, 22, 30, 18 };
```

When using the shorthand method the array size inside the square brackets is optional, as the program will simply workout how big the array should be based on the number of values assigned.

&nbsp;
&nbsp;

### Accessing the array

We can access an array in a similar way to accessing a variable, by supplying the name. However, the difference being we need to specify the index we wish to access inside square brackets (known as the subscript operator) after the array name. We did this in the longhand initialisation example above, where each index was accessed individually to assign a value. The below code shows an example of how we might output an array value

```C++
cout << "The age stored at index 2" is << ages[2] << endl;
```

Based on the array declared and initialised previously this should output the value 22.

&nbsp;
&nbsp;

### Iterating Through the Array

If we wanted to access each array value we could of course do this one by one

```C++
cout << "The age stored at index 0" is << ages[0] << endl;
cout << "The age stored at index 1" is << ages[1] << endl;
cout << "The age stored at index 2" is << ages[2] << endl;
cout << "The age stored at index 3" is << ages[3] << endl;
cout << "The age stored at index 4" is << ages[4] << endl;
```

Yet, this creates duplicate code and as a programmer we want to strive for efficiency and reduce duplication as much as possible. As we saw at the end of the first chapter we can make use of loops in order to reduce the need for repeating code, and as noted in this chapter for loops are typically used in combination with arrays.

This is because we use the for loop when we know how many times we want the loop to run, and in an array we know how many values there are. Therefore, we can limit the loop to the amount of values contained in the array.

Therefore we can access all 5 values in the ages array more efficiently by using a for loop.

```C++
for (int i = 0; i < 5; i++){
      cout << ages[i] << endl;
}
```

Remember the for loop includes an *initialisation*, *condition* and *increment*. We use the *initialisation* to create a counting variable to run through our array indexes (this variable is typically named ```i``` to stand for index). The *condition* is used to set the limit of our array and the *increment* adds one to our counting variable each time so we can run through all the array indexes. Inside the for loop body we can then access each array value by using our ```i``` counting variable to set the index. As this ```i``` variable increases by 1 on each iteration we will be able to access each value.

In our above example we initialise the ```i``` variable at 0 as this is where array indexes starts. The condition is set to *not* go above 4 (runs as long as i is less than 5), as the ages array has 5 values with indexes running from 0 to 4.

Work through this for loop one iteration at a time until you fully understand how it works.

&nbsp;
&nbsp;

## Range Based For Loop

In C++ the for loop has another syntax that we’ve not yet looked at. This syntax creates a for loop that is used exclusively with ranges. Ranges are sequences of elements such as arrays. The range based for loop is similar to for each loops which are present in other programming languages. The syntax for this type of loop is more condensed than the standard one we’ve been working with so far and includes a declaration and a range, which are separated by a colon.

```
for( declaration : range){
    //do something
}
```

The declaration is a variable that will store each value from the range as it iterates, and the range is the container you want to access (e.g. the name of an array). Therefore to create a range based for loop for the ages array we were looking at previously the syntax would be as follows:

```C++
for(int i : ages){
      cout << i << endl;
}
```

Note in the declaration the variable has been given the data type int, as this is the type of data that is stored in the ages array. When using this type of for loop make sure the data type of the variable in the declaration matches that of the container you are accessing. For example:

```C++
string staff[] = {"Lee", "Sam", "John", "Ron", "Jake", "Coral"};
for(string name : staff){
    cout << name << " ";
}
```

&nbsp;
&nbsp;

## Auto Keyword

In C++11 the auto keyword was included to allow a variable data type to be inferred from the value it's initialised with.

```C++
int myFirstInt = 5; //explicitly declared integer variable
auto mySecondInt = 6; //variable data type automatically inferred from the value assigned
```

For the declaration of simple variables with one of the core data types (int, char, double), it is best to be explicit and you would not use auto. Auto is typically used when your programs become larger and it can help reduce the verbosity of complex data type names (we will see examples of this later in the module), or in some cases you may not know what type you are dealing with.

A typical use case for the auto keyword is within the range based for loop as the declaration variable should have the same type as the range elements. By using the auto keyword you can let C++ deduce the type of the range elements.

```C++
char letters[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
for(auto i : letters){
     cout << i;
}
```

**Further Information**

https://en.cppreference.com/w/cpp/language/auto
https://www.learncpp.com/cpp-tutorial/4-8-the-auto-keyword/

&nbsp;
&nbsp;

## Multidimensional Arrays

We can think of arrays as a row of data stored next to each other in columns:

```C++
int ages[] = { 19, 23, 22, 30, 18 };
```

| <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    | <!-- -->    |
|-------------|-------------|-------------|-------------|-------------|-------------|
| ages| 19 | 23 | 22 | 30 | 18 |

However, we can add further rows and columns through the use of multidimensional arrays. The most common is a 2D array which adds additional rows to the array.

&nbsp;
&nbsp;

### Declaring a 2D Array

To declare a 2D array we just need to add an additional set of square brackets when declaring the array. The value given inside the first square brackets defines the number of rows in the array and the value inside the second set defines the number of columns.

Some of you last year used a 2D array to store your vending machine snacks in the Utility App assignment. Below we have declared an empty 2D string array with space for three rows of four columns each

```C++
string snacks[3][4];
```

&nbsp;
&nbsp;

### Initialising a 2D Array

You can initialise a 2D array in a similar fashion to a standard one dimensional array, either individually accessing each index using the subscript operators:

```C++
string snacks[0][0] = “Mars Bar”; //add item in first row & column
string snacks[0][1] = “Snickers”; //add item in first row, second column
string snacks[0][2] = “Bounty”; //add item in first row, third column
string snacks[0][3] = “Wispa”; //add item in first row, fourth column
string snacks[1][0] = “Doritos”; //add item in second row, first column
//etc..
```

Or by using the shorthand method and initialising using a comma separated list immediately after declaration.

```C++
string snacks[3][4] = {
    {“Mars Bar”, “Snickers”,“Bounty”,“Wispa”},//first row
    {“Doritos”, “Wheat Crunchies”,“Nik Naks”,“Quavers”}, //second row
    {“Apple”, “Banana”,“Orange”,“Pear”} //third row
};
```

Note in the example above the use of additional curly braces to wrap each row, these are optional but make it easier to identify the start and end of each row.

&nbsp;
&nbsp;

### Accessing a 2D Array

To access the array we need to specify the array name and index we want to access using the subscript operators. As it's a 2D array we need to specify both the row and the column we want to access.  

```C++
cout << snacks[2][3] << endl; //will output orange based on prior example initialisation
```

&nbsp;
&nbsp;

### Iterating Through a 2D Array

In order to iterate through the entire array we can again make use of for loops. However as there are multiple rows we will need to use a nested for loop. The outer loop will iterate over the rows, whilst the inner loop iterates through the columns.

```C++
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
        cout << snacks[i][j] << " ";
    }
    cout << endl;
}
```

In the above example, every time the outer loop iterates the inner one will iterate four times to output each of the snacks in that row. Note the use of each of the counting variables inside the subscript operators to denote which position we wish to access, using i for the rows and j for the column.

&nbsp;
&nbsp;

## Standard Library Arrays

The arrays we have been using so far are basic ‘inbuilt’ arrays. However, C++ also has an array class included in the standard library that offers additional functionality that can make handling arrays easier. To make use of the standard library arrays we must include the array header

```C++
#include <array>
```
&nbsp;
&nbsp;

### Declaring the Array

The syntax for declaring a standard library array is different to our basic arrays. To do so we must state we want to use the array class, followed by the data type and size of the array inside angle brackets ```< >```. We then name and initialise the array as we would the basic array. See the two examples below:

```C++
array<int, 5> ages = { 19, 23, 22, 18, 13 };//int array with 5 elements
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"}; //string array with four Elements
```

&nbsp;
&nbsp;

### Accessing and Iterating Through the array

Whilst declaring the array is different to basic arrays, accessing and iterating through a standard library array can be done in exactly the same way that we are used to.

```C++
cout << ages[0] << endl; // will output 19 based on array above

//standard for loop to output all snacks
for(int i = 0; i < 4; i++){
      cout << snacks[i] << endl;
}
//range based loop to output all snacks
for(string s : snacks){
     cout << s << endl;
}
```

&nbsp;
&nbsp;

### Standard Library Array Class Methods

As the standard library arrays are a class they come with various methods that make working with them easier (similar to the string class). Key ones that you will likely make use of are

* *At:* Can be used to access elements in the array, the same as using the subscript operators [ ]. The difference with using at is that it will throw an error at runtime, whilst using the subscript operator will just use a garbage value.
* *Size:* Returns the size of the array, e.g. if five elements the method will return 5. This can be useful for setting for loop conditions
* *Front:* Provides access to the first element
* *Back:* Provides access to the last element
* *Begin:* Returns an iterator pointing to the beginning of the array
* *End:* Returns an iterator pointing to the end of the array

#### An Example

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
cout << snacks.at(1) << endl;//returns value at index 1 e.g. snickers
cout << snacks[1] << endl; //does the same as the above

cout << snacks.front() << endl;//returns value at beginning of array (Mars Bar
cout << snacks.back() << endl;//returns value at end of array (Wispa)

// utilise a for loop to run through array
for(int i = 0; i < snacks.size(); i++){ //note use size() in condition
   cout << snacks[i] << ", ";
}
cout << endl;
```

*Further Reading:* http://en.cppreference.com/w/cpp/container/array

&nbsp;
&nbsp;

## Using the Algorithm Library

As well as access to its own class methods, a benefit of using the standard library arrays is that they can be used in conjunction with the algorithm library that includes methods for performing useful tasks on arrays such as sort, reverse and shuffle.

To access the algorithm library you need to include the algorithm header

```C++
#include <algorithm>
```

Many of the algorithm methods make use of iterators to move through the array using calls to .begin() and .end() to define the begin and end points of the range.

[Jump ahead to read more on iterators](../Chapter-5-Vectors-and-the-STL#iterators)

Some useful examples of iterators being used in conjunction with containers and methods from the algorithm header are included below:

### Sort - sorts into ascending order

```C++
array<int, 5> numbers = {33, 5, 7, 99, 83};
sort(numbers.begin(), numbers.end()); // ← call to sort here
for(int num : numbers){
   cout << num << " ";
}
```

### Reverse - reverses the order of the array

```C++
array<string, 6> staff = {"Lee", "John", "Ron", "Jake", "Coral", "Sam"};
reverse(staff.begin(),staff.end());
for(string s : staff){
    cout << s << " ";
}
```

### Random_shuffle - shuffles order of elements

```C++
array<int, 10> myInts = {1,2,3,4,5,6,7,8,9,10};
random_shuffle(myInts.begin(), myInts.end());
for(int i : myInts){
    cout << i << " ";
}
```

### Count - counts the number of times an element appears

```C++
array<string, 8> shoppingList = {"Milk", "Bread", "Coffee" , "Tea", "Sugar", "Bananas", "Apples", "Milk"};
int mycount = count(shoppingList.begin(), shoppingList.end(), "Milk");
cout << "Milk appears " << mycount << " times.\n";
````

For the full list of available methods in the algorithm library, including usage examples see:
https://en.cppreference.com/w/cpp/algorithm

&nbsp;
&nbsp;

## 2D Standard Library Array

One slight disadvantage of the standard library array is the verbosity of declaring 2D arrays. The syntax for which is as follows:

```C++
array<array<int, 7>, 2> myArray;
```

This will create an array with two rows and 7 columns, which can be confusing as unlike the built in 2D array declaration the column number comes first due to it being included within the declaration of the row array.

Aside from this slightly awkward syntax for declaring the array, handling the array itself is exactly the same as 2D built in arrays.

