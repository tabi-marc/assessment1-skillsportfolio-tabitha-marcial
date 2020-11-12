# Chapter 8 - Structures

* [What are Structures?](#what-are-structures)
    * [Declaring a Structure](#declaring-a-structure)
    * [Creating Structure Objects](#creating-structure-objects)
    * [Initialising Object Data Members](#initialising-object-data-members)
    * [Containers of Structure Objects](#containers-of-structure-objects)
    * [Structures as Function Parameters](#structures-as-function-parameters)
* [Combining File Handling and Structures](#combining-file-handling-and-structures)

## What are Structures?

Structures are user defined data types than can be used to group multiple pieces of data together. Unlike containers such as arrays which can only hold data of the same type, structures can contain data of different types under one name.

Once a structure has been declared we can create multiple objects (variables) of this structure type and each one can have unique values for the data contained inside. Structures are useful for storing records of data and working with databases, thus can be used in combination with file handling introduced in the last chapter.

Let’s take an example to begin visualising the usefulness of structures. Imagine a library database that stores records of all the books the library has. Obviously each book has a title, so we could record all the books in a string array. However, books have much more information than just a title, including author (string), the number of pages (int), price (double), ISBN number (int), genre (string), etc…). We wouldn't want to create arrays for all these different pieces of information as it would be too difficult to keep all the records in sync.

Instead we can make use of a structure which can contain all of this information in a single type in what is known as its data members. The structure defines the characteristics of an object and from this we can create multiple objects (variables) each with unique data.

&nbsp;
&nbsp;

### Declaring a Structure

To declare a structure type we use the keyword ```struct```. We then give it a name and specify the required members (individual data) between curly braces. The terminating curly brace must be followed by a semi-colon. The structure should be declared outside the main function and convention is to start the structure name with a capital letter.

```C++
struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};
```

Above we can see an example of the earlier described book structure. Here you can see how a single structure can hold data of different types inside a single named type. The data inside a structure are known as its members. We can include as many members as required to define the characteristics of the object we wish to represent in the program.

&nbsp;
&nbsp;

### Creating Structure Objects

There are two ways of creating individual objects (or variables) from a structure. The first is to declare them when the structure type is declared. To do this we include the variable names for the individual objects in a comma separated list after the terminating curly brace of the structure (but before the semi colon). For example the code below would create three individual book objects from the book structure

```C++
struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
} myBook, secondBook, finalBook;
```

The second method is to declare them in main just like other basic variables. For this you need to specify the structure type (e.g. Books), followed by the variable name for the individual objects. The code below demonstrates this method by again creating three individual book objects.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

int main(){

    Books myBook, secondBook, thirdBook;

    return 0;
}
```

&nbsp;
&nbsp;

### Initialising Object Data Members

Currently the three books created in the previous example have no values assigned to their data members. There are two ways we can assign values. The first is via an initialisation list that can be included alongside the object declaration. When using the initialisation list the values should be provided in the same order as the data members are declared in the structure.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

int main(){

    Books myBook{ "Lord of the Rings", "J.R.R. Tolkien", "Fantasy",
                   12345, 1454, 7.99 };

    return 0;
}
```

The above creates an object (myBook) from the Books structure and assigns the following values to its data members

```
Title:		Lord of the Rings
Author:		J.R.R Tolkien
Subject:	Fantasy
Book Id:	12345
Pages:		1454
Prices:		7.99
```

The second method for assigning values is to access each data member of the object individually using the member access operator ( ```.``` ). This method can be used to first initialise values, but would also be used if we need to reassign values (e.g. reduce the price). The below example uses this method, providing the same values as the previous example.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

int main(){

    Books myBook;
    myBook.title = "Lord of the Rings";
    myBook.author = "J.R.R. Tolkien";
    myBook.subject = "Fantasy";
    myBook.book_id = 12345;
    myBook.pages = 1454;
    myBook.price = 7.99;
    return 0;
}
```

The data member access operator would also be used if we wanted to access and output the values stored in an object. For example, continuing with our book structure below initialises the data members with the initialisation list method, then outputs each value.

```C++
int main(){

    Books myBook{ "Lord of the Rings", "J.R.R. Tolkien", "Fantasy",
                   12345, 1454, 7.99 };

    cout << "Title: " << myBook.title << endl;
    cout << "Author: " << myBook.author << endl;
    cout << "Subject: " << myBook.subject << endl;
    cout << "ID: " << myBook.book_id << endl;
    cout << "Pages: " << myBook.pages << endl;
    cout << "Price: " << myBook.price << endl;

    return 0;
}
```

&nbsp;
&nbsp;

### Containers of Structure Objects

Just like a basic data type such as an int, we can create containers (e.g. arrays or vectors) of structure objects. This can make it easy to handle large sets of data and iterate through them using loops. Declaring a container of structures is the same as it would be for a basic data type, you just need to specify the structure name as the type of data you want the array to store. The examples below show how to declare a standard library array, standard library vector, and basic array of Books objects, each set to store 5 objects.

```C++
array<Books, 5> library; //using standard library arrays
vector<Books> library(5); //using standard library vectors
Books library[5]; //using basic arrays
```

We can initialise these books using an initialisation list with the container declaration. The below example demonstrates this with a standard library array:

```C++
array<Books, 5> library{ {
  {"Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 12345, 1454, 7.99},
  {"Harry Potter", "J.K. Rowling", "Fantasy", 12346, 323, 4.69},
  {"The Beach", "Alex Garland", "Travel", 12347, 435, 2.99},
  {"Veg", "Jamie Oliver", "Cookery", 12348, 249, 17.50},
  {"A Christmas Carol", "Charles Dickens", "Drama", 12349, 532, 2.48}
 } };
//Note the double curly braces before and after the initialisation of the structure values.
```

We could then use a for loop to iterate over the array and output the values of each book

```C++
for(int i = 0; i < library.size[i]; i++){
        cout << "Book " << i << endl;
        cout << "=======" << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Subject: " << library[i].subject << endl;
        cout << "ID: " << library[i].book_id << endl;
        cout << "Pages: " << library[i].pages << endl;
        cout << "Price: " << library[i].price << endl;
        cout << endl;
}
```

&nbsp;
&nbsp;

### Structures as Function Parameters

As structures are just user defined data types we can also pass them as function arguments like we would any other type of data. To do so we simply specify the structure name followed by a variable name in the parameter list of the function declaration

For an example let’s modify our previous example that output the values of an array of books and move the printing task into its own function. We will then pass the book we want to print as an argument when invoking the function. It's usually a good idea to pass a structure by reference (&) to reduce potential overheads of passing by value and making a copy of the object being passed.

```C++
#include <iostream>
#include <array>
#include <string>
using namespace std;

struct Books{ // declare book structure
    string title;
    string author;
    string subject;
    int book_id;
    int pages;
    double price;
};

/* function which takes books object as parameter. Note the book is passed as const reference.This is because don’t want the expense of copying it, but want to ensure it doesn’t get modified. */
void printBook(const Books &b){     
    cout << "Requested Book" << endl;
    cout << "==============" << endl;
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Subject: " << b.subject << endl;
    cout << "ID: " << b.book_id << endl;
    cout << "Pages: " << b.pages << endl;
    cout << "Price: " << b.price << endl;
    cout << endl;
}
int main(){
    //initialise 5 books objects into array
    array<Books, 5> library{ {
      {"Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 12345, 1454, 7.99},
      {"Harry Potter", "J.K. Rowling", "Fantasy", 12346, 323, 4.69},
      {"The Beach", "Alex Garland", "Travel", 12347, 435, 2.99},
      {"Veg", "Jamie Oliver", "Cookery", 12348, 249, 17.50},
      {"A Christmas Carol", "Charles Dickens", "Drama", 12349, 532, 2.48}
    } };

    printBook(library.at(1));//print Harry Potter Book

    printBook(library.at(4));//print A Christmas Carol

    return 0;
}
```
The above program will output the following:

```
Requested Book
==============
Title: Harry Potter
Author: J.K. Rowling
Subject: Fantasy
ID: 12346
Pages: 323
Price: 4.69

Requested Book
==============
Title: A Christmas Carol
Author: Charles Dickens
Subject: Drama
ID: 12349
Pages: 532
Price: 2.48
```

&nbsp;
&nbsp;

## Combining File Handling and Structures

As noted at the beginning of this chapter, structures work well in combination with file handling as they provide us with a method of storing records read from files efficiently. For example, in the File Handling chapter we had an example where we read in some customer information from a file:

```
Joe Bloggs	43	BS2 4CV
Karen Smith	23	EM1 5XY
Garry Jones	18	FG4 8NP
Phil Legg	54	BS1 5NE
```

The example program we created read this data into the program and stored it inside a string array, reading in each piece of data to a different array index through the use of getline and specifying the tabbed space character as a seperator. Whilst this program performed the task we wanted, it's not the most desirable approach as:

The data is not grouped in anyway just indexed at consecutive array positions
All the data has been stored as string values, yet the age column would be better stored as an int.

We can improve the program by reading the data on each line into a structure that has data members for the information included in the file:

```C++
struct customers{
    string name;
    int age;
    string postCode;
}
```


In our example we will use a vector to store each of the customer objects. This is because later down the line we might add or lose customers, thus we want to be able to resize the container. At the start of the program we use ```.reserve()``` on the vector so the program saves space for at least 10 customers initially.

As we move through the customers.txt file line by line we create a new Customers object and read the data from the file to the object data members. To do this we make use of ```getline()``` and extraction operators to read in the data to specified points in the file.

Once all the data has been read in we use a range based for loop to output each piece of data. In this for loop we access each element by const reference, else when each element is accessed a copy will be made (similar to passing by value vs passing by reference in functions.

The use of structures in this instance makes the code much cleaner and individual customers are easier to handle as their data is grouped together in a single named object. The entire code is included across the following pages, make sure you study the comments to understand what is happening at each step.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <sstream>
#include <string>
#include <vector>
using namespace std;
//structure to store customer data
struct Customers{
    string name;
    int age;
    string postCode;
};
int main(){
    //vector to store customer objects
    vector<Customers> ourCustomers;
    //save space for 10 objects initially
    ourCustomers.reserve(10);

    //declare input file stream
    ifstream inputFile("customers.txt");
    stringstream sStream;

    //check file is open
    if(inputFile.is_open()){
        //while not at end of file keep reading
        while(!inputFile.eof()){
            /* create new customer object this only remains in scope
               for 1 iteration of the while loop. Gets recreated on
               each iteration. */
            Customers newCustomer;
            /*read first piece of data into customer object name
              stop reading at tab character /*
            getline(inputFile, newCustomer.name, '\t');
            /* read second piece of data into customer object age
               as this value is an int we can't use getline
               instead directly extract from inFile into age data member
               extraction will stop if invaild data is reached
               (e.g. next tab character)
            */
            inputFile >> newCustomer.age;

            //ignore the next character (tab) to get to postcode
            inputFile.ignore(1);
            //read final piece of data into customer object postcode
            getline(inputFile, newCustomer.postCode);

            //push newCustomer into vector
            ourCustomers.push_back(newCustomer);
            /*End of while loop so newCustomer released from memory,
              however copy is safely stored in vector after push_back*/
        }
        //close the file
        inputFile.close();
    }else{
        //output message if file not read
        cout << "File cannot be accessed. Terminating program" << endl;
        //exit program
        return -1;
    }
    //OUTPUT DATA FROM VECTOR
    cout << "Customers" << endl;
    cout << "=========\n" << endl;
    /* for loop to run through vector
       Note we access this by const reference to avoid copy overhead
       use of const ensures it can’t be modified in loop as just want
       to print the data.
    */
    for(const Customers &c : ourCustomers){
        cout << "Name: " << c.name << endl;
        cout << "Age: " << c.age << endl;
        cout << "Postcode: " << c.postCode << endl;
        cout << endl;
    }
    return 0;
}
```

