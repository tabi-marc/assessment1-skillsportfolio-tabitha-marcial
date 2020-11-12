# Chapter 4 - Vectors and the STL

This chapter expands our knowledge of container types in C++ by looking at Vectors and other aspects of the C++ Standard Template Library.

* [What is a Vector](#what-is-a-vector)
  * [Declaring a Vector](#declaring-a-vector)
  * [Initialising a Vector](#initialising-a-vector)
  * [Accessing a Vector](#accessing-a-vector)
  * [Resizing a Vector](#resizing-a-vector)
  * [Vector Class Methods](#vector-class-methods)
  * [Multidimensional Vectors](#multidimensional-vectors)
* [Iterators](#iterators)
* [The STL](#the-stl)
  * [Pair](#pair)
    * [Using Auto to Declare a Pair](#using-auto-to-declare-a-pair)
    * [Example - Products](#example---products)
  * [Tuple](#tuple)
    * [Get](#get)
    * [Tie](#tie)
  * [Returning Multiple Values from Functions](#returning-multiple-values-from-functions)
  * [Maps](#maps)
    * [Declaring a map](#declaring-a-map)
    * [Initialising and Adding Map Elements](#initialising-and-adding-map-elements)
    * [Accessing Map Elements](#accessing-map-elements)
    * [Iterating Through a Map](#iterating-through-a-map)
    * [Erasing Elements from a Map](#erasing-elements-from-a-map)
    * [Finding Elements in a Map](#finding-elements-in-a-map)
* [Further STL Reading](#further-stl-reading)


&nbsp;
&nbsp;

## What is a Vector?

Vectors are very similar to arrays and are a container that can store multiple values of the same type. The difference with vectors over arrays is that they can be resized, meaning we can add new values or delete existing ones.

Vectors are part of what's known as the standard template library, which includes a variety of different container types. To access vector functionality we need to add the vector header file at the top of our program

```C++
#include <vector>
```

&nbsp;
&nbsp;

### Declaring a Vector

Declaring a vector is very similar to declaring a standard library array. We specify we want to access the vector class, then in angle brackets specify the type of data the vector will store, before finally providing a variable name for our vector

```C++
vector<int> myIntVector; //declares vector of integers
```

Note unlike declaring a standard library array we do not need to specify the size of the vector, due to the fact it can be resized.

&nbsp;
&nbsp;

### Initialising a Vector

There are different ways we can initialise the values inside a vector. We can use the initialisation list we will be familiar with from arrays and include the values we wish to assign in a comma separated list wrapped in curly braces.

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
```

Or we can initialise a vector with the same value a specified number of times, or with just empty values that can be assigned later by accessing the vector indexes.

```C++
vector<int> myInts(10, 6);//creates a vector with 10 int values all set to 6
vector<int> myInts(10);//creates a vector with 10 int values all set to 0
vector<string> myString(10); //creates a vector with 10 empty string values
```

&nbsp;
&nbsp;

### Accessing a Vector

You can access the values in a vector, to retrieve or modify the data, in the same way you would a standard library array, either using the subscript operators:

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
cout << myIntVector[1] << endl; //outputs 2
```

Or by using the ```.at()``` method:

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
cout << myIntVector.at(4) << endl; //outputs 66
```

&nbsp;
&nbsp;

### Resizing a Vector

Adding values to a vector can be done in different ways. We could reassign values using the initialisation list and either increase or reduce the number of values in the vector:

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
myIntVector = { 1, 2, 4, 55, 66, 43, 8, 100, 22 }; //adds three more values
myIntVector = { 55, 4, 18 }; //alters values and shrinks vector
```

Alternatively we could use the ```.resize()``` method. When calling ```.resize()``` you specify the size you would like to alter the vector two in the method arguments. Specifying a value larger than the current size of the vector would add empty values to the end, whilst specifying a value smaller than the current size would delete values off the end.

```C++
vector<int> myIntVector = { 1, 2, 4, 55, 66, 43 };
myIntVector.resize(10); //adds 4 empty values to the end (e.g. 0's)
myIntVector.resize(2); //removes all values from end leaving only 1 and 2
```

Finally, we could utilise the ```.push_back()``` method to add a single value to the end of the vector, or ```.insert()``` method to add a value at the position specified.

```C++
vector<int> myIntVector = {100, 200, 300};
myIntVector.push_back(500); //add 700 to end of vector

//insert 400 at index 3 in myIntVector
myIntVector.insert(myIntVector.begin()+3, 400);

for(int i : myIntVector){
    cout << i << " ";
    //Expected output: 100 200 300 400 500 600 700
}
```

&nbsp;
&nbsp;

### Vector Class Methods

Like the standard library array vectors contain various useful methods that we can utilise to manipulate and work with the vectors we create. We’ve already seen ```.at()``` (used to access the value at a particular index), ```.resize()``` (used to increase/decrease the size of the container), ```.push_back()``` (adds element to end of vector) and ```.insert()``` (adds element(s) at position specified), but there are several other methods that provide us with useful functionality:

* *Reserve:* reserves enough memory for the specified number of elements (e.g. .reserve(40); would reserve enough memory for 40 elements to be contained. This can be helpful if we know the size of our vector to prevent numerous reallocations of memory by the vector itself.
* *Capacity:* specifies the number of elements a vector can hold before memory will need to be reallocated.
* *Size:* returns the size of the vector
* *Push Back:* adds a new element to the end of the vector
* *Pop Back:* removes the last element from the vector and reduces size by one
* *Swap:* Swaps values of one vector with another vector.
* *Clear:* Clears all the elements from within the vector
* *Empty:* Returns true if the vector is empty, else it returns false.
* *Front:* Returns value of element at first position in vector
* *Back:* Returns value of element at last position in vector
* *Begin:* Returns iterator pointing to first element
* *End:* Returns iterator pointing to one past the last element
* *Erase:* Removes value at position pointed to by an iterator.

Vectors can also be used with many of the algorithm class methods.

Further Reading: https://en.cppreference.com/w/cpp/container/vector

&nbsp;
&nbsp;

### Multidimensional Vectors

Like arrays we can add additional rows and columns to create multidimensional vectors. The syntax is similar to declaring a multidimensional standard library array, minus the need to specify the row and column size. In this example we create a 2D int vector with three rows and three columns.

```C++
vector< vector<int> > v = {{1,2,3}, {4,5,6}, {7,8,9}};
```

In this more complex example we have a 2D string vector with three rows and four columns. The values stored in this vector list the ‘top teams’ in different European football leagues. We then insert a new row of values to the end of the list to now include teams from an additional country. These values are then output using a nested for loop; the outer loop iterates over the rows, while the inner loop iterates over the columns.

```C++
vector<string> country = {"England", "Spain", "Italy"};//store countries
vector< vector <string> > teamList = {
    {"Newcastle", "Man Utd", "Arsenal", "Chelsea"},
    {"Real Madrid", "Barcelona", "Athletico", "Deportivo"},
    {"Juventus", "Roma", "Inter", "Napoli"}
};
//Add new row of teams and insert at end of team list;
teamList.insert(teamList.end(), {"PSG" , "Nice" , "Monaco" , "Metz"} );
country.push_back("France"); //Push back new country value
for(int i = 0; i < country.size(); i++){
    cout << country[i] << ": ";
    for(int j = 0; j < teamList[0].size(); j++){
        cout << teamList[i][j] << " ";
        if(j == 3)
            cout << "\n============\n";
    }
}
```

&nbsp;
&nbsp;

## Iterators

Iterators provide a means for accessing data stored in containers such as arrays and vectors. However, rather than directly returning the value they return the address of the data in memory, this address can then be dereferenced (using the dereference operator ```*```) to obtain the value.  

To declare an iterator variable you state which type of container we want to iterate upon (e.g. array), followed by the type of data stored in the container (e.g. string) and then scope to the iterator object using the scope resolution operator (```::```).

#### Vector Iterator Declaration

```C++
vector<string>::iterator itr;
```

#### Array Iterator Declaration

```C++
array<string, 4>::iterator itr;
```
*Note from the above example that if declaring an array iterator you also need to specify the array size after specifying the data type, just as you would when declaring a standard library array.*

As noted above the ```.begin()``` and ```.end()``` method calls return iterators pointing to the start or end of ranges such as arrays. Therefore we can use these calls to assign values to the iterator.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
array<string, 4>::iterator itr = snacks.begin(); //points to Mars Bar
```

The syntax for declaring an iterator is fairly clunky, so this does offer a good use case for using auto. The type of the iterator variable will be automatically deduced from the value assigned.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
auto itr = snacks.begin(); //points to Mars Bar
```

Using the increment and decrement operators we can then easily move the iterator through containers and access the elements.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
auto itr = snacks.begin(); //iterator that points to Mars Bar
itr = snacks.begin() + 2 //reassigns the iterator to point to bounty
cout << itr << endl; //outputs the address of bounty
cout << *itr << endl; //dereferences the iterator to output bounty
```

Our above example declares a string array, then declares an iterator variable and assigns the address of the first value in the array using ```.begin()```. The iterator value is then reassigned to bounty by using ```.begin()``` but moving this along 2 by using basic math operators. We then output the address where bounty is stored in memory, followed by outputting bounty by dereferencing the iterator. Notice the difference on this last line is the use of the dereference operator (```*``` ).

Similar logic can be used to iterate through the entire array using an iterator instead of standard counting variables in the for loop as shown in the example below. Note the use of auto to easily infer that the ```itr``` variable will be an iterator. This iterator is given its start point using ```.begin()``` in the *initialisation*, the *condition* then checks to ensure the iterator does not go beyond the end, and the increment operators are used to move the iterator to the next address in memory each time the loop runs. This increment works as container values are always stored next to each other in memory.

```C++
array<string, 4> snacks = {"Mars Bar", "Snickers","Bounty","Wispa"};
for(auto itr = snacks.begin(); itr != snacks.end(); itr++){
        cout << *itr << endl; //dereference iterator to access value
}
```

As discussed in the earlier chapter on Arrays, iterators are used with many of the algorithm library methods. For instance the below example shows an iterator being used with the ```.find()``` method to see if an element is present in a string array. If the element is found before the end of the vector the IF statement dereferences the iterator to output the element in the ```cout``` statement.

```C++
vector<string> shoppingList = {"Milk", "Bread", "Coffee" , "Tea", "Sugar", "Bananas", "Apples"};
auto it = find(shoppingList.begin(), shoppingList.end(), "Coffee");
if (it != shoppingList.end()){
    cout << "Found " << *it << "In shopping list \n";
}else{
    cout << "Did not find " << *it << "In shopping list \n";
}
```

&nbsp;
&nbsp;

Further Reading:

* https://en.cppreference.com/w/cpp/iterator/iterator
* [Iterator overview from LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-standard-template-library/iterators-overview)
* [Accessing Iterators from LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-templates-and-the-stl/accessing-iterators?)

&nbsp;
&nbsp;

## The STL

The C++ Standard Template Library provides access to a comprehensive set of ready made generic classes that can be used to implement data structures and algorithms. The STL has three core components; containers, algorithms, iterators. Thus, we have seen some aspects of the STL already as vectors, iterators, the algorithm library and standard library arrays are all part of the STL.

Beyond containers like vectors and arrays that we have already seen, the STL includes many more classes that provide useful features for everyday programming applications. The extent of which is too much to cover here (we could have an entire module on it), yet the following pages will introduce some key elements of the STL and point towards useful further reading resources.

&nbsp;
&nbsp;

### Pair

In C++ a pair can hold a pair of values of different types in a single named container. These values can then be accessed by using the access operator (```.```) on the named container followed by either first or second.

To declare a pair in our program we need to specify we want to use the pair template class, then in angle brackets specify the types the pair will hold. Finally we give the pair a name.

```C++
pair<int, string> person;
```

We can include the initialisation of the pair values alongside the declaration by including the values in parentheses after the pair name

```C++
pair<int, string> person(31, "Jake");
```

or by accessing the ```first``` and ```second``` positions after declaration.

```C++
pair<int, string> person;
person.first = 31;
person.second = "Jake";
```

Similarly to output pair values we would use first and second:

```C++
pair<int, string> person(31, "Jake");
cout << "Persons age is: " << person.first << endl;
cout << "Persons name is: " << person.second << endl;
```

Expected output:
```
Persons age is: 31
Persons name is: Jake
```

&nbsp;
&nbsp;

#### Using Auto to Declare a Pair

You could also use the auto keyword to declare your pair in combination with the make_pair() method. The auto keyword will automatically infer that the type your are creating is a pair based on the use of make_pair(). The make_pair() function accepts the values you wish to insert into the pair as values

```C++
auto person = make_pair(31, "Jake");
```

&nbsp;
&nbsp;

#### Example - Products

Think back to last year's vending machine problem. You needed to store the name and price of a series of products. One way of solving this is to store these in individual variables or two sets of arrays. However, with a pair we could group the product name and price values together in one named container.

```C++
pair<string, double> product("Pear", 0.59);
cout << "Product name: " << product.first << endl;
cout << "Product price: £" << product.second << endl;
```

We could extend this further by creating an array of pairs to store multiple products:

```C++
pair<string, double> choc[4] = {
    {"Twix", 0.69}, {"Mars", 0.59}, {"Snickers", 0.99}, {"Bounty", 0.69}
};
```

When initialising an array of pairs we wrap each individual set of pair values in their own curly braces within the initialisation list. We could then use a for loop to easily output these values

```C++
//range based for loop
for(auto &item : choc){
    cout << item.first << " £" << item.second << endl;
}

//standard for loop
for(int i = 0; i < 4; i++){
    cout << choc[i].first << " £" << choc[i].second << endl;
}
```

The example above provides an example of outputting each item in the choc pair array using a range based for loop and a standard for loop.

The above choc array could also be declared using the standard library array and specifying the pair as the type in the array declaration. Also note when initialising the values you need a double set of opening and closing curly braces wrapping the values.

```C++
array<pair<string, double>, 4> choc = {
   { {"Twix", 0.69}, {"Mars", 0.59}, {"Snickers", 0.99}, {"Bounty", 0.69} }
};
```

&nbsp;
&nbsp;

Full documentation on the pair can be found here:
https://en.cppreference.com/w/cpp/utility/pair

&nbsp;
&nbsp;

### Tuple

A tuple is similar to a pair in that it can hold differ types in a single named container. However it has the advantage that we can include more than just two different types. To use tuples we need to include the tuple header.

```C++
#include <tuple>
```

The declaration of a tuple is similar to a pair, with the type of each value to be included specified in the angle brackets after the tuple keyword

```C++
tuple<string, int, char> student("Joe Blogs", 1234, 'B');
```

The auto keyword can also be used in combination with make_tuple

```C++
auto student = make_tuple("Joe Blogs", 1234, 'B');
```

&nbsp;
&nbsp;

#### Get

In order to access the individual values in a tuple to either modify or outputting we need t use the ```get``` function. The syntax for the get function is slightly unusual in that the ```get``` keyword is followed by angle brackets ```<>```, inside which the index of the value you want to get is specified, this is then followed by parentheses () that includes which tuple you want to get this value from. For example the below would output Joe Blogs by getting this element from the student tuple that is declared in the previous example.

```C++
cout << get<0>(student) << endl;
```

&nbsp;
&nbsp;

#### Tie

We can unpack elements from a tuple by using the tie function, which enables us to get the values and immediately assign them to other variables.

```C++
auto student = make_tuple("Joe Blogs", 1234, 'B');
string name;
int id;
char grade;
tie(name, id, grade) = student;
cout << "Name: " << name << " ID: " << id << " Grade: " << grade << endl;
```

If you only want to unpack certain values from the tuple you can use the keyword ignore when calling tie(). For instance, unlike the previous example which unpacks each value from the student tuple, the below example ignores the first two and only unpacks the last

```C++
auto student = make_tuple("Joe Blogs", 1234, 'B');
char grade;
tie(ignore, ignore, grade) = student;
cout << " Grade: " << grade << endl;
```

&nbsp;
&nbsp;

Full documentation on the tuple can be found here:
https://en.cppreference.com/w/cpp/utility/tuple

&nbsp;
&nbsp;

### Returning Multiple Values from Functions

The use of tie makes tuples useful for returning multiple values from functions. This can be done by specifying tuple as the function return type and then using tie to unpack the values from the tuple that gets returned. For example, below we can see a modified version of our previous code that demonstrates the tuple being returned from a function and unpacked to the individual variables with the use of tie.

```C++
tuple<string, int, char> returnStudent(){ //function to return tuple
    auto student = make_tuple("Joe Bloggs", 1234, 'A'); //make tuple
    return student; //return tuple
}

int main (){

    string name;
    int id;
    char grade;
    //unpack values from returned tuple and tie to variable declared above
    tie(name, id, grade) = returnStudent();
    //output values
    cout << "Name: " << name << " ID: " << id << " Grade: " << grade << endl;

    return 0;
}
```

The above example *‘hard codes’* the tuple that gets returned but this could easily be extended so the function returns a student found from a database of students (e.g. either from a file or within a container of data such as a vector).

If you just had two values you wanted to return from a function you could utilise a pair as the function return type.

```C++
pair<string, double> returnProduct(){ //function to return pair
    auto p = make_pair("Twix", 0.59); //create pair
    return p; //return pair
}

int main (){
    auto product = returnProduct(); //get pair from function
    string name = product.first; //assign name from first pair value
    double price = product.second; //assign price from second pair value
    cout << "Product: " << name << " Price: " << price << endl; //output info

    return 0;
}
```

&nbsp;
&nbsp;

### Maps

Maps are containers for pairs. The first value in the map is the key, which can be used to retrieve elements associated with that key from the map. To use maps we need to include the map header. Maps are similar to dictionaries that exist in other languages such as python.

```C++
#include <map>
```

&nbsp;
&nbsp;

#### Declaring a Map

Maps are declared by typing the ```map``` keyword followed angle brackets within which the types for the keys and associated elements are specified. We then provide a name for the map.

```C++
map<string, string> capitals;
```

&nbsp;
&nbsp;

#### Initialising and Adding Map Elements

Map elements can be initialised alongside declaration by wrapping each individual map pair in their own curly braces within the initialisation list.

```C++
map<string, string> capitals{
    { "Poland", "Warsaw"},
    { "USA", "Washington"},
    { "France", "Paris"},
    { "UK", "London"},
    { "Germany", "Berlin"}
 };
 ```

Map elements can also be initialised after declaration using the following syntax:

```C++
capitals["Spain"] = "Madrid";
capitals["Italy"] = "Rome";
```

The above would add two further elements to the map. The value in the square brackets is the key, which we assign the element to.

The ```insert()``` method can also be used on maps to add new elements. When calling the ```insert()``` method on the map you can use ```make_pair``` within the parameter brackets to add the key and associated element.

```C++
capitals.insert(make_pair("Wales", "Cardiff"));
```
The keys in maps must be unique, so adding an element with a duplicate key will be ignored. For maps with duplicate keys a [multimap](https://en.cppreference.com/w/cpp/container/multimap) can be used.

&nbsp;
&nbsp;

#### Accessing Map Elements

We can access elements in the map similar to how we access elements in an array. However, rather than specify the index of the element we wish to obtain, we specify the key.

```C++
cout << "The capital of Germany is " << capitals["Germany"] << endl;
```

The above will result in the following output:

```
The capital of Germany is Berlin
```

&nbsp;
&nbsp;

#### Iterating Through a Map

We can make use of a range based for loop to easily iterate through the map

```C++
for(auto &c: capitals){
    cout << c.first << " " << c.second << endl;
}
```

This will output all the elements in the map. In order to access the key and associated element of each map value we use first and second like on a pair. Note that map elements get sorted based on their key value. In the case of our capitals example this means the output of our above for loop would be as follows:

```
France Paris
Germany Berlin
Italy Rome
Poland Warsaw
Spain Madrid
UK London
USA Washington
Wales Cardiff
```

If you want an unsorted map, for example one that retains the order elements were initialised in, then you can use the ```unordered_map``` instead. This requires the unordered map header.

```C++
#include <unordered_map>
```

&nbsp;
&nbsp;

#### Erasing Elements from a Map

To erase map elements we can call the ```erase()``` method and specify the key of the element we wish to erase.

```C++
capitals.erase("France");
```

&nbsp;
&nbsp;

#### Finding Elements in a Map

To look for an element in a map we can use the ```find()``` method and specify the key of the element we wish to find. The ```find()``` method returns and iterator to the position where the element is found. We compare the value returned from find against the one returned from the end method (which gives us an iterator to the end of the map). If they are the same this means we have reached the end of the map without finding the element. Therefore, we want the ```.find()``` and ```.end()``` values to **NOT** be equal.  

```
auto finder = capitals.find("China");
if(finder != capitals.end()){
    cout << "The capital of China is" << finder->second << endl;
}else{
    cout << "Capital of China not yet in our database" << endl;
}
```

In the above example you will notice we assign the value returned from the ```.find()``` method to our own iterator called finder (declared using ```auto``` for brevity). We then access this element via the iterator hence the use of the arrow operator (```->second```) as we are not directly accessing the value and cannot use the dot notation like in previous examples.

&nbsp;
&nbsp;

Full documentation on maps can be found at: https://en.cppreference.com/w/cpp/container/map/

&nbsp;
&nbsp;

## Further STL Reading

As noted earlier, the features of the STL are extensive and there are many more container types, iterators and algorithm functions than can be covered here. A number of resources for further exploration have been included below

* [Quick STL Overview on LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-essential-training-2/overview-of-the-stl)
* [Quick STL Overview on Study Tonight](https://www.studytonight.com/cpp/stl/stl-introduction)
* [C++ STL Course with exercises on LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-standard-template-library)
* [C++ Templates and the STL course on LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-templates-and-the-stl/)

