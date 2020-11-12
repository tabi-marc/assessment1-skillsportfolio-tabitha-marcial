# Chapter 9 - Object Oriented Programming

* [What is OOP?](#what-is-oop)
  * [Creating a Class](#creating-a-class)
  * [Class Access](#class-access)
  * [Example Class](#example-class)
  * [Creating Class Instances](#creating-class-instances)
  * [Accessing Object Data Members](#accessing-object-data-members)
  * [Classes Versus Structures](#classes-versus-structures)
  * [Class Methods](#class-methods)
  * [Class Constructors](#class-constructors)
  * [Overloading Class Methods](#overloading-class-methods)
  * [This Pointer](#this-pointer)
  * [Class Destructors](#class-destructors)
* [Organising Code](#organising-code)
  * [Adding Files In Visual Studio](#adding-files-in-visual-studio)
  * [Adding Files In Xcode](#adding-files-in-xcode)
* [Static Class Members](#static-class-members)
* [Static Class Methods](#static-class-methods)
* [Classes and Pointers](#classes-and-pointers)
  * [Allocating Memory To Class Objects](#allocating-memory-to-class-objects)
* [Key OOP Concepts](#key-oop-concepts)
  * [Abstraction](#abstraction)
  * [Encapsulation](#encapsulation)
    * [An Example - Cars](#an-example---cars)
    * [Accessing Private Data](#accessing-private-data)
  * [Inheritance](#inheritance)
    * [Creating Subclasses](#creating-subclasses)
  * [Polymorphism](#polymorphism)
  * [Further Reading](#further-reading)
* [When Will I Use all of This?](#when-will-i-use-all-of-this)

&nbsp;
&nbsp;

## What is OOP?

When the C++ language was created the main aim of its original author Bjarne Stroustrup was to add object orientation to the C language. Object oriented programming is based around the concept of objects which can be viewed as user defined data types. In opposition to primitive data types (int, char, bool, etc), which can only contain one piece of information, these object can contain multiple bits of data, and perform various actions (or methods).

We have already been working with different objects by accessing different Classes from the standard C++ library. Strings are one example; when we create a string variable we are creating an object from the string class, upon which we can perform any of the various methods declared in the string class. We have also made use of the file stream class, from which we can create input and output file objects. Furthermore, in the last chapter we looked at the concept of Structures; a user defined data-type that can contain multiple bits of data and has many similarities with Classes that are the focus of this chapter.

In object oriented programming objects are created from Classes, which define what information an object is made up of and what it can do. This information is stored in:

* *Data members* - e.g. variables
* *Methods* - e.g. functions

As we saw in the chapter on structures, different structure objects can store different values in their data members and this data can be modified just like standard variables. The same is true of class objects.

Classes can be used to mimic real world objects and define their characteristics for the purposes of our programs. For example, we might use a class to define a set of enemy robots in a game, or to define products in a shopping app.

The central principles of Object Oriented Programming are thus:

* *Classes* - Hold the definitions of the data (e.g. variables) and procedures (e.g. functions, also known as methods) available to objects of the class
* *Objects* - The name given to individual instances that can be created from the class.

Object Oriented Programming is extremely useful and important in being able to make our code much more efficient as classes create reusable code that we can instantiate multiple objects from. Whilst these objects will each be based off the same underlying code, we can store unique values in their data members which might change how they are used and what they can do in the program. For example, we might have a products class in a supermarket database which includes data for weight and price, objects created from this class would then have very different values dependant on what type of product it is (e.g. banana vs beef).

Let’s think about an example to help visualise what classes are and why they are useful. Imagine we are making a program where we need a database of cars (e.g. Autotrader), or a game where we need different cars to race against each other (e.g. Need for Speed). Typing out the data that defines each car individually would become tiresome, so we need a way of speeding up the process. This is where classes come in...

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/car-class.png">
</p>

With a class we can define the main characteristics we want every car in our program to have. Then from this base class we can instantiate multiple objects and set unique values for the data members to create each individual car. For instance from our image above we might have a car class that defines the main characteristics for the cars in our program as Colour, Brand, Make and Fuel Type. From this class we can then begin creating many different types of car such as the three included above. The car class is then likely to include the functions a car can perform such as accelerate, brake, steer, check fuel and many more.

&nbsp;
&nbsp;

### Creating a Class

From our car example we can see that when we create classes we are defining the blueprint for user defined data types. Creating a class in C++ is very similar to creating a structure. We start with the keyword class followed by the class name (like with our variables and function names, we want to give the class a sensible and useful name). The class body is then wrapped in curly braces and the closing curly brace has a semicolon after it. One difference in comparison to creating a structure is that if we want to be able to access the data and methods of a class object elsewhere in our programs we need to specify it as being *“public”* (more on this shortly).

```C++
class ClassName{
    public:
        //data
        //methods
};
```

Classes should be declared outside of the main function and convention is to use a Capital letter when naming the class. A class can have as many data members and methods as required.

&nbsp;
&nbsp;

### Class Access

Above it was noted that we need to specify class data and methods as being public if we want to access them in other areas of our program. This is done as by default class data and methods are private. This means the data and methods can only be accessed from within the class itself. There are different types of class access, which can be specified using the access specifier (like public is set in the example below).

* *Public:* Data and Procedures can be accessed in other parts of the program within the scope of the class
* *Private:* Data and Procedures can only be accessed from within the class
* *Protected:* Data and Procedures can only be accessed from within the class and child (or derived classes)

You can mix and match access specifiers in a single class and make certain data and methods public, whilst keeping others private

```C++
class ClassName{
    public:
        //data & methods here will be public

    private:
        //data & methods here will be private

};
```

&nbsp;
&nbsp;

### Example Class

```C++
class Cat{
    public:
       string name;
       string colour;
       int age;
       double weight;
};
```

Here we have an example of a simple class in C++. This class defines the basic characteristics in a blueprint for Cat objects. Each cat in a program using this class would be able to have a name, colour, age and weight.

&nbsp;
&nbsp;

### Creating Class Instances

Creating objects from a class is done in the same way as creating structure objects and can be done in two ways. The first is to create objects alongside the class definition, by including the names for the objects in a comma separated list between the closing curly braces and semi-colon at the end of the class definition. For example below we create four objects from our Cat class.

```C++
class Cat{
    public:
       string name;
       string colour;
       int age;
       double weight;
}felix, tom, bagpuss, simba;
```

The second method is to declare the objects in the main function by specifying the class type followed by the instance name (similar to declaring other variables).

```C++
int main() {
    Cat felix;
    Cat tom;
    Cat bagpuss;
    Cat simba;
    return 0;
}
```

&nbsp;
&nbsp;

### Accessing Object Data Members

To access the data members of class objects we use the access operator (again similar to with structures). This allows us to set or modify the values stores in the data members.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;
};
int main() {
    Cat felix;
    felix.name = "Felix";
    felix.colour = "Black";
    felix.age = 14;
    felix.weight = 4.4;

    Cat bagpuss;
    bagpuss.name = "Bagpuss";
    bagpuss.colour = "Pink";
    bagpuss.age = 43;
    bagpuss.weight = 8.9;

    return 0;
}
```

In the above example we use the access operator ( ```.``` ) to set the data member values for two cat objects (felix and bagpuss).

&nbsp;
&nbsp;

### Classes Versus Structures

Currently you might be thinking classes look very similar to structures, and what is the difference between the two? The answer in C++ is little. Classes can do all the things we did in previous chapter with structures including creating containers of class objects and passing classing objects to functions.

The only real difference is data access. By default class data is private by default, whilst structure data is public (which is why we didn’t need the access specifier), although we could specify that we want structure data to be private.

Classes can also have methods (functions), however in C++ so can structures. Thus, as mentioned the difference is minimal. Typically however it is common practice to use structures when the object just contains data, and use classes when the object is more complex and is required to perform actions and thus includes methods.

&nbsp;
&nbsp;

### Class Methods

Class methods define the tasks that a class object can perform. They are created and act in the same way as standard functions that we might include in our program. Methods in a class can access all of the data defined within the class and can also be passed data from other parts of the program via parameters. To make an object perform the method we use the access operator ( ```.``` ) and invoke the function on the object.

For instance, our below example adds a simple method to make our cat object say hello and its name. In the main program after creating the object we invoke the ```sayHello()``` method on the felix object instantiated from the Cat class.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    void sayHello(){
        cout << "Hello my name is: " << name << endl;
    }
};
int main() {
    Cat felix;
    felix.name = "Felix";
    felix.colour = "Black";
    felix.age = 14;
    felix.weight = 4.4;

    felix.sayHello();

    return 0;
}
```

Just like standard functions we can declare then define class methods separately. When doing so we include the declaration inside the class body, then define the method outside of the class. When defining the method outside of the class we need to use the scope resolution operator ( :: ) to prepend the Class name ahead of the method name. We do this to say this is the definition for the method declared within the scope of the respectively named class. Without prepending this the compiler would be looking for a standard function not declared within a class.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    void sayHello();
};

void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}
```

&nbsp;
&nbsp;

### Class Constructors

Classes can be given special functions known as constructors that are automatically called when an object of the class is created. Constructors can be useful for initialising the data members of objects. For example it would be useful to have a constructor on our Cat class to initialise the values when it is first created. Constructors have no return type and are always named exactly the same as the class.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    void sayHello();
};

Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}

void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}


int main() {
    Cat myCat;
    myCat.sayHello();
    return 0;
}
```

In the above example we have added a constructor to our cat class. This has been declared and defined separately just like the ```sayHello()``` method. In the constructor we initialise the data members of the class object default values. Therefore when the object ```myCat``` is created and the ```sayHello()``` method is called on it the expected output will be

```
Hello my name is: Kitty
```

&nbsp;
&nbsp;

### Overloading Class Methods

Class methods and constructors can be overloaded just like normal functions and the compiler will work out which one to use based on the parameters passed in. For example below we have added an additional constructor to our Cat class. This one has parameters which are used to set the data members of the class object with the values passed in when the object is created.

We can pass parameters to a constructor by including the values in parentheses after instantiating the class object e.g:

```C++
Cat myCat2("Felix", "Brown", 12, 7.8);
```

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string n, string c, int a, double w);
    void sayHello();
};

Cat::Cat(string n, string c, int a, double w){
    name = n;
    colour = c;
    age = a;
    weight = w;
}

Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}

void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}

int main() {
    Cat myCat;
    myCat.sayHello();

    Cat myCat2("Felix", "Brown", 12, 7.8);
    myCat2.sayHello();
    return 0;
}
```

In this example we now have two cat objects being instantiated. This first uses the constructor with no parameters as none are passed in when the object is created. Therefore this object uses the default values (e.g. Kitty etc). The second object uses the constructor with parameters, meaning the values passed in via the parentheses are used to set the object's data members when its created. The expected output for this example is therefore:

```
Hello my name is: Kitty
Hello my name is: Felix
```

&nbsp;
&nbsp;

### This Pointer

In the previous example the constructor parameters have just been named with a single letter. This isn’t great practice as it's not very revealing as to what the parameters do. It would be better if these constructor parameters were names as the data members to which they will be assigned. When a class method or constructor has parameter arguments with the same name as a class data members we need to use the this pointer to explicitly refer to the class members. For example in a method ```this -> name```; would refer to the class member whilst ```name``` refers to the method parameter. Without the this pointer if we tried using ```name = name``` to set the class data member we would actually just be making the method parameter equal to itself. The below code updates our previous example to use the this pointer when the constructor parameters use the same names as the data members to which they will be assigned.

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string name, string colour, int age, double width);
    void sayHello();
};
Cat::Cat(string name, string colour, int age, double width){
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = w;
}
Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}
void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}

int main() {
    Cat myCat;
    myCat.sayHello();

    Cat myCat2("Felix", "Brown", 12, 7.8);
    myCat2.sayHello();
    return 0;
}
```

&nbsp;
&nbsp;

### Class Destructors

As well as constructors, classes can be given destructors, which are special functions that are called automatically when a class object gets destroyed (e.g. goes out of scope). The look very similar to constructors as they must also have exactly the same name as the class, however to differentiate them a tilde character (~) is included at the beginning. Unlike constructors, destructors cannot accept parameters, therefore you can only have one destructor per class as they cannot be overloaded.

Our simple example program with the cat class has been updated to include a destructor, which includes a basic output message. This will be executed when the myCat object that is instantiated in this example goes out of scope, which in this case with when the program ends (e.g the return statement is reached).

```C++
class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string name, string colour, int age, double width);
    ~Cat();
    void sayHello();
};
Cat::Cat(string name, string colour, int age, double width){
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = width;
}
Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}
Cat::~Cat(){
    cout << name << " has been destroyed" << endl;
}
void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}
int main() {
    Cat myCat;
    myCat.sayHello();
    return 0;
}
```

Expected output:

```
Hello my name is: Kitty
Kitty has been destroyed
```

&nbsp;
&nbsp;

## Organising Code

With the addition of classes our programs are becoming more complex and add to the number of things that need to be declared outside of the main function. As we begin to add more classes and functions it is easy to see how this might become difficult to navigate. For that reason we want to be able to organise our code effectively.

In C++ it is common practice to include classes across two files.

* *Header (.h)* - includes all the declarations (the interface)
* *Cpp (.cpp)* - includes all the definitions (the implementation)

For our previous cat example the header file (```.h```) would include the class declaration including the data members and method declarations. Note on Xcode the header might have the ```.hpp``` extension

```C++
//CAT.H
#include <iostream>
using namespace std;

class Cat{
public:
    string name;
    string colour;
    int age;
    double weight;

    Cat();
    Cat(string name, string colour, int age, double width);
    ~Cat();
    void sayHello();
};
```

The cpp file (```.cpp```) would then include the definitions of any class methods, constructors and destructors. Note at the top of the file we need to link to the header file using an include statement (just like you do with iostream and string). For user created files the include should specify the file name, which should be written inside double quotation marks

```C++
//CAT.CPP
#include "Cat.h" //include cat header file

Cat::Cat(string name, string colour, int age, double width){
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = width;
}

Cat::Cat(){
    name = "Kitty";
    colour = "Black";
    age = 1;
    weight = 2.0;
}

Cat::~Cat(){
    cout << name << " has been destroyed" << endl;
}
void Cat::sayHello(){
    cout << "Hello my name is: " << name << endl;
}
```

To gain access to these files in the main program we would then also need to link to the header file by using an include statement.

```C++
// MAIN.CPP
#include <iostream>
#include "Cat.h" //include cat header file
using namespace std;


int main() {
    Cat myCat;
    myCat.sayHello();

    return 0;
}
```

Making use of header files and accompanying .cpp files is not just limited for when you begin adding classes to your programs. They can be used to organise programs that make use of lots of functions. In this case you would include the function declarations in the header file and the full definitions in the .cpp file.

&nbsp;
&nbsp;

### Adding Files in Visual Studio

To add files to a project in Visual Studio, right click the source files folder in the solution explorer and select ```Add → New Item``` from the pop up menu

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/add-files-vs1.png">
</p>

In the popup window select C++ file, give this file a name and click ```Add```.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/add-files-vs2.png">
</p>

Repeat the process by again right clicking the source folder and selecting ```Add → New Item``` from the popup menu. This time when the popup window appears select Header File. Give this the same name as the C++ file you added but retain the .h file extension.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/add-files-vs3.png">
</p>

&nbsp;
&nbsp;

### Adding Files in XCode

To add files in XCode go to ```File → New File```

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/add-files-xc1.png">
</p>

Select ```C++ file```

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/add-files-xc2.png">
</p>

Give the file a name and leave ```Also create a header file``` checked. Click ```next``` and save the file alongside the main.cpp file of your project

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/add-files-xc3.png">
</p>

&nbsp;
&nbsp;

## Static Class Members

[In an earlier chapter](../Chapter-3-Furthering-Functions#static-function-variables) we introduced the static keyword and discussed its meaning in relation to functions. Now we will take a look at its meaning when used within classes. Static variables in a class are initialised just once, this means they are shared by all objects of the class. Thus, rather than every instance of the class being able to have assigned a unique value for the data member, if the variable is static the value remains the same for all instances.

When using a static class member you must initialise its value outside of the class using the scope resolution operator (```::```).

In the example below we have a basic class with a single static data member. This is then initialised to the value one outside the class using the scope resolution operator. We then create an instance of this class and assign the value 2 to the static data member. A second instance is created and the value 3 assigned to the static data member. Finally we access the num value via each object to output its value. In both output statements this value will be three as the static data member is shared by all class objects. Thus, the final value that was assigned is the one that currently persists. If the data member was not declared as static then the values output would be 2 and 3. As the static data members are independent of any of the class objects they can be accessed directly via the scope resolution operator (MyClass::num).

```C++
class MyClass{
public:
    static int num; //declare static variable
};
int MyClass::num = 1; //init static variable

int main() {
    MyClass obj1;
    obj1.num = 2; //assign 2 to static variable

    MyClass obj2;
    obj2.num = 3; //assign 3 to static variable

    cout << obj1.num << endl; //outputs 3
    cout << obj2.num << endl; //also output three

    return 0;
}
```

&nbsp;
&nbsp;

## Static Class Methods

Similar to static data members in a class, static methods also do not depend on an instance of the class and the function is shared by all objects and can even be invoked if an object has not been instantiated. Static methods cannot access non static data members and whilst they can be invoked via a class object they are typically invoked via the class name and scope resolution operator ( ```::``` ).

The following example uses a static variable to keep track of the total number of dog objects created, incrementing the value via a constructor and then outputting the value via a static function.

```C++
class Dog{
public:
    static int totalDogs; //declare static variable

    Dog(){
        totalDogs++;
    }
    static void getNumDogs(){
        cout << "Total dogs in program " << totalDogs << endl;
    }
};
int Dog::totalDogs = 0;

int main() {

    Dog::getNumDogs();

    Dog fido;
    Dog rex;
    Dog colin;

    Dog::getNumDogs();

    return 0;
}
```

The fact static functions operate independent of class objects is demonstrated by using the getNumDogs() method both before and after objects are instantiated. Thus the expected output of this program is:

```
Total dogs in program 0
Total dogs in program 3
```

&nbsp;
&nbsp;

## Classes and Pointers

Just like we can with other data types we can create pointers to class objects ([read the previous chapter on pointers for an overview](../Chapter-6-Pointers). To do so we just need to specify the class data type when declaring the pointer. Once we have a pointer to a class object we can access the objects data members and methods by using the arrow operator (```->```). You might see the arrow operator as ‘pointing to’ the object's member/method you want to access.

To demonstrate using pointers with class objects we have an example below which creates a pointer to an object of a basic Dog class and uses the arrow operator to access the members and methods of the object.

```C++
#include <iostream>
using namespace std;

class Dog{
    // encapsulate variables -> indirect access via functions
    string name;
    string breed;
    int age;
public:
    // class constructor, sets default name/breed/age
    Dog(){
        cout << "Dog created" << endl;
        name = "Unkown"; breed = "Unknown"; age = 0;
    }
    // overloaded constructor, sets name/breed/age with passed in values
    Dog(string name, string breed, int age){
        cout << "Dog created" << endl;
        this->name = name;
        this->breed = breed;
        this->age = age;
    }
    // class destructor
    ~Dog(){
        cout << "Dog Deleted" << endl;
    }
    // function to alter dog info
    void alterInfo(string name, string breed, int age){
        this->name = name;
        this->breed = breed;
        this->age = age;
    }
    // function to output dog info
    void outPutInfo(){
        cout << "Name: " << name << endl;
        cout << "Breed: " << breed << endl;
        cout << "Age: " << age << endl;
    }

};

int main() {
    //create dog using parameterised constructor
    Dog myDog("Fido","Collie",5);

    //create dog pointer and assign address of myDog
    Dog* dPtr = &myDog;

    //access object method via pointer using arrow operator
    dPtr->outPutInfo();
    //alter object members via pointer using arrow operator
    dPtr->alterInfo("Billy", "Boxer", 11);

    //output pointer address of dog
    cout << "Address of Dog: " << dPtr << endl;

    //create second dog using parameterised constructor
    Dog mySecondDog("Rex", "Poodle", 8);

    //reassign pointer to address of the second dog
    dPtr = &mySecondDog;

    //output pointer address
    cout << "Address of Dog: " << dPtr << endl;

    //access object method via pointer using arrow operator
    dPtr->outPutInfo();

    return 0;
}
```

If you were to type up and run this code the expected output should be similar to below. Note we can see the constructors being called in the output (“Dog Created”), as well as the destructors which get called when the objects go out of scope at the end of the program (“Dog Deleted”).

```
Dog created
Name: Fido
Breed: Collie
Age: 5
Address of Dog: 0x7ffeefbff580
Dog created
Address of Dog: 0x7ffeefbff4d0
Name: Rex
Breed: Poodle
Age: 8
Dog Deleted
Dog Deleted
```

&nbsp;
&nbsp;

### Allocating Memory To Class Objects

Using pointers we can also dynamically allocate memory for class objects. For instance take a look at the code below, this program uses the same dog class as the previous example but dynamically allocates the dog object to the heap rather than the stack.

```C++
int main()
    //allocate memory for object using new keyword
    Dog* dPtr = new Dog("Fido","Collie",5);
    //access object method via pointer using arrow operator
    dPtr->outPutInfo();
    //alter object members via pointer using arrow operator
    dPtr->alterInfo("Billy", "Boxer", 11);    
    //output pointer address of dog
    cout << "Address of Dog: " << dPtr << endl;   
    //deallocate memory
    delete dPtr;
    //Dog destructor should get called when delete is run
    cout << "Destructor should be called BEFORE this line" << endl;

    return 0;
}
```

The expected output here should be similar to the below, with the dog destructor being called when the object is deleted from memory

```
Dog created
Name: Fido
Breed: Collie
Age: 5
Address of Dog: 0x100573a10
Dog Deleted
Destructor should be called BEFORE this line
```

In the above examples we have used the new and delete keywords to perform the memory allocation. However as mentioned in the pointers chapter more modern C++ now has smart pointers such as ```unique_ptr``` which will automatically call delete for us and therefore help prevent memory leaks.

The following example uses a ```unique_ptr``` to perform the same task as the previous example. Note for the purposes of this example the code has been wrapped in its own scope using braces to demonstrate how the ```unique_ptr``` will automatically delete the object when the ptr goes out of scope.

Note you may need the memory header to access smart pointers:

```C++
#include <memory>
```

```C++
int main(){
    {//Start of additional scope

        //allocate memory for object using unique_ptr
        unique_ptr<Dog> dUniPtr = make_unique<Dog>("Fido","Collie",5);
        //access object method via pointer using arrow operator
        dUniPtr->outPutInfo();
        //alter object members via pointer using arrow operator
        dUniPtr->alterInfo("Billy", "Boxer", 11);
        //output pointer address of dog
        cout << "Address of Dog: " << dUniPtr << endl;

    }//End of additional scope - Destructor should get called

    cout << "Destructor should be called BEFORE this line" << endl;

    return 0;
}
```

The expected output here should be similar to the below, with the destructor called at the end of the scope the pointer has been created in:

```
Dog created
Name: Fido
Breed: Collie
Age: 5
Address of Dog: 0x10390aed0
Dog Deleted
Destructor should be called BEFORE this line
```

In comparison if we were to move the pointer outside of the additional scope that has been added to the above program but still include the object allocation inside you will see the destructor does not get called until the end of the program (e.g. the end of the scope the pointer is now in). This therefore demonstrates how dynamically allocating memory for objects/data can be useful if you need the memory to persist beyond the scope it is created in.

```C++
int main() {
    //declare unique pointer
    unique_ptr<Dog> dUniPtr;
    {//Start of additional scope

        //allocate memory for object and assign to unique_ptr
        dUniPtr = make_unique<Dog>("Fido","Collie",5);
        //access object method via pointer using arrow operator
        dUniPtr->outPutInfo();
        //alter object members via pointer using arrow operator
        dUniPtr->alterInfo("Billy", "Boxer", 11);
        //output pointer address of dog
        cout << "Address of Dog: " << dUniPtr << endl;
    }//End of additional scope - object should persist beyond here
    cout << "Destructor should be called AFTER this line" << endl;

    return 0;//end of unique_ptr scope object should now be destroyed
}
```

The output for this example should therefore be similar to the below

```
Dog created
Name: Fido
Breed: Collie
Age: 5
Address of Dog: 0x103904600
Destructor should be called AFTER this line
Dog Deleted
```

&nbsp;
&nbsp;

## Key OOP Concepts

### Abstraction

Abstraction is the idea of how we characterise classes in our program and the information we decide to include in our blueprint. For example our earlier examples using a Cat class included data members for name, colour, age and weight. This is an abstract idea of what we’ve decided a cat is for the purposes of our program.

If we were to create this program on a different day we might have different purposes and therefore our abstract idea of a cat might change. This time we might need to include breed alongside name, colour, age and weight.

With abstraction in mind rather than including every possible characteristic of an object, we instead only define what is relevant to the purposes of our program at that time.

&nbsp;
&nbsp;

### Encapsulation

Encapsulation refers to the visibility or accessibility of data in our programs. Earlier in this chapter we looked at access specifiers and discussed how class data is private by default. By including the public access specifier we make the data and methods of classes accessible across other parts of our program.

However, the reason data is private by default is because it is common practice and advisable to encapsulate as much class information as possible.. This makes your programs more secure as data can’t easily be modified by other parts of the program. Thus, you should only make public what really needs to be accessed by other parts of the program.

Take banking software as an example, you wouldn’t want to make the ```accountBalance``` data member public as this offers the potential for other parts of the program to directly access and modify this value. This might then result in an account losing all its money. Instead you would want to make ```accountBalance``` private and provide methods that allow the data to be read, but not necessarily written to.

If the rest of the program doesn’t need to utilise a variable in your class, but that variable is essential for other aspects of the class to function it should be private. This will also make it easier to alter your program, especially if other people are utilising your code (e.g if it’s distributed as a library), as you’ll be able to make modifications to private functions and variables without harming how other people may have implemented what is public. This is about interface (what others see) vs implementation (how actions are performed behind the scenes). If you make implementation alterations these should leave the interface intact.

&nbsp;
&nbsp;

#### An Example - Cars

```C++
class Car
{
  private:
    int vel;
    int travelTime;
    int mass;

  public:
    int getDistance()  {
       return (vel*travelTime);
    }
    int getMomentum()  {
        return (mass*vel);
    }
};
```

Take the above class as an example. This class has three data members which are declared as private. These data members are important to the functionality of a car but knowledge of them is not necessary in order to utilise the public methods ```getDistance();``` or ```getMomentum();``` or understand what they are going to do.

If we were creating objects of this car class in our program we do so knowing we can get information about the car’s distance and momentum, but without needing to what’s being used to make those calculations. It also means if this class was part of a third-party library that various people might be using, the developer of this class we could make alterations to these calculations (e.g. to improve them by adding other variables (the implementation)), without altering how they are used (e.g. calling the function remains the same even if the calculation is returned by different variables (the interface)).

You will have seen this in action already throughout CodeLab. For example when using the algorithm or string class you will have used methods such as ```.find()```, ```.compare()```, or ```.sort()```. When using these methods you know what parameters these take and how to use them (the interface), but you most likely have no idea how the result is actually being calculated behind the scenes (the implementation). The likelihood is there may be private data members at work that you don’t know exist, or really need to know exist.

&nbsp;
&nbsp;

#### Accessing Private Data

With the above in mind it is good practice to keep your data members private when working with classes. However there will be times where you want to access and modify these values. Methods created for this purpose are known as getter (retrieve data) and setter (modify / assign data) methods.

Lets modify out earlier cat example so it now uses private data members and getter and setter methods to access the private data

```C++
#include <iostream>
using namespace std;

class Cat{
    //no access specifier so data will be private
    string name;
    string colour;
    int age;
    double weight;

public://make methods public
    //SETTERS - assign passed in value to data member
    // need this pointer as method parameter is the same name
    void setName(string name) { this->name = name; }
    // need this pointer as method parameter is the same name
    void setColour(string colour){ this->colour = colour; }
    //don't need this pointer as method parameter name differs
    void setAge(int yrs){ age = yrs;}
    //don't need this pointer as method parameter name differs
    void setWeight(double kg){ weight = kg;}

    //GETTERS - simply return data member back to program
    string getName(){ return name; }
    string getColour(){ return colour; }
    int getAge(){return age; };
    double getWeight(){ return weight; }

    //constructor
    Cat(string name, string colour, int age, double width);
    //destructor
    ~Cat();
    //say hello function declaration
    void sayHello();
};

void Cat::sayHello(){
    cout << "Hello my name is " << name << endl;
}

Cat::Cat(string name, string colour, int age, double width){
    // need this pointer as constructor parameters use same name
    this->name = name;
    this->colour = colour;
    this->age = age;
    this->weight = width;
}
Cat::~Cat(){
    cout << name << " has been destroyed" << endl;
}
int main() {
    //create cat object and use constructor initialisation
    Cat felix("Felix", "Brown", 14, 8.5);

    //use setter methods to reassign values
    felix.setAge(15);
    felix.setColour("Grey");

    //use getter methods to retrieve and output data
    cout << "Cat is called " << felix.getName() << endl;
    cout << felix.getName() << " is " << felix.getAge() << " years old" << endl;
    cout << felix.getName() << " is " << felix.getColour() << " and weighs " << felix.getWeight() << endl;

    return 0;
}
```

&nbsp;
&nbsp;

### Inheritance

One of the benefits of OOP is code reuse, which as mentioned previously in this workbook should be a general goal of programming; to make your code as efficient as possible and avoid writing the same thing twice where possible.

We can enhance reuse with classes through inheritance. With inheritance we can create a base class for an object that defines the key overarching characteristics every object should have. Then in addition to this we create subclasses that inherit the data and methods of the base class, but can also add their own to create more unique objects.

This is visualised below where we have an Animal class as the base that contains key characteristics that every animal might have. From this we have two subclasses (dog and cat), that inherit these characteristics, but also add their own which are unique to that species. For example cats and dogs make different noises when they ‘speak’.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/inheritance.png">
</p>

We could expand this example further and have subclasses of our Dog / Cat that contain specific attributes of different breeds. We can also easily add more animals (e.g human / bird etc), without having to rewrite all of the core data and methods that define the base Animal class.

In C++ you can have multiple layers of inheritance, where a subclass can inherit from multiple base classes. But this can quickly get confusing and it’s therefore common just to inherit from one base class. Languages like Java prevent multiple inheritance

&nbsp;
&nbsp;

#### Creating Subclasses

To create a subclass and inherit from another, we create our class as usual, but after the class name we append a semicolon, followed by the keyword public and then the class we wish to inherit from.This means we make the information from the parent class public (accessible) to the subclass. If we want to make data members available to subclasses they must either be made public, or protected. Public will make them available to the entire program, whilst protected will only make them available to the subclasses.

```C++
//PARENT BASE CLASS
class Animal{
    //protected data accessible to subclasses
protected:
    string name;
    int age;
    double weight;
public:
    // public methods
    void eat(){
        cout << "Nom Nom Nom!" << endl;
    }
    void die(){
        cout << "Oh no " << name << " died!" << endl;
    }
    void move(){
        cout << name << " is walking" << endl;
    }
};
//CHILD SUBCLASS
class Cat: public Animal{
    //private data
    string breed;
public:
    //public methods
    void meow(){
        cout << "Meow, my name is: " << name << endl;
    }
};
//CHILD SUBCLASS
class Dog: public Animal{
    //private data
    string breed;
    string skills[3];
public:
    //public methods
    void woof(){
        cout << "Woof Woof, my name is: " << name << endl;
    }
};
```

&nbsp;
&nbsp;

### Polymorphism

Polymorphism means many forms. In programming this means our program will automatically perform the correct behaviour when multiple options are available. We’ve already encountered this. Take the + sign. When working with integers the plus sign will add them together. Yet, when working with strings it will concatenate them (link them together). We don’t need to instruct our program to do that, it performs the correct behaviour automatically depending on the data type it's working with. We’ve also seen polymorphism when overloading function. In this case we can have multiple functions of the same name and the compiler will determine which one to use based on the parameters passed to the function.

In OOP with classes, polymorphism means we can override core behaviour inherited from another class. If we expand our previous animal example and add a bird subclass. Let’s say the move function in our animal class accounts for animals that walk on the ground with 2 / 4 feet. Our bird subclass might therefore wish to override this move function to take into account that birds fly when they move. Similarly a fish subclass might override the move function to enable swimming.The appropriate move functionality will automatically be used dependant on what type of object is being used.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/polymorphism.png">
</p>

The above diagram is translated into the following code, to create the classes. If we were to then create some objects from these classes (e.g. A dog called Fido, a cat called Felix and a bird called Percy) and call the move method on each one our output would be as follows:

```
Fido is walking
Felix is walking
Percy is flying
```

This is because the dog and cat objects (Fido and Felix) inherit the move functionality from the Animal class, whilst the bird class overrides this behaviour with its own move function.

```C++
//PARENT BASE CLASS
class Animal{
    //protected data accessible to subclasses
protected:
    string name;
    int age;
    double weight;
public:
    // public methods
    void eat(){
        cout << "Nom Nom Nom!" << endl;
    }
    void die(){
        cout << "Oh no " << name << " died!" << endl;
    }
    virtual void move(){
        cout << name << " is walking" << endl;
    }
};

//CHILD SUBCLASS
class Cat: public Animal{
    //private data
    string breed;
public:
    //public methods
    void woof(){
        cout << "Meow, my name is: " << name << endl;
    }
};

//CHILD SUBCLASS
class Dog: public Animal{
    //private data
    string breed;
    string skills[3];
public:
    //public methods
    void woof(){
        cout << "Woof Woof, my name is: " << name << endl;
    }
};

//CHILD SUBCLASS
class Bird: public Animal{
    //private data
    string breed;
public:
    //public methods
    void squawk(){
        cout << "Squak, my name is: " << name << endl;
    }
    void move(){
        cout << name << " is flying" << endl;
    }
};
```

You might notice in the code above that the move method in the parent animal class is specified as being virtual (```virtual void move()```). This ensures the correct function is called if the child class is referred to via a pointer or reference of the parent class. For example, bird could be passed to a function parameter that has the type Animal) and if the move function was not virtual the compiler would shortcut to the Animal move function rather than the bird override. Virtual ensures this shortcut does not take place.

&nbsp;
&nbsp;

### Further Reading

[Chapter 1 of Programming Foundations: Object-Oriented Design on LinkedIn Learning](https://www.linkedin.com/learning/programming-foundations-object-oriented-design-3/object-oriented-thinking?)

&nbsp;
&nbsp;

## When Will I Use all of This?

Through this workbook we have introduced many concepts and there is much more to learn as you delve deeper in C++. On the face of it some of these concepts may seem fairly abstract (and potentially overwhelming). However, as you develop larger programs the usefulness of these techniques will become more and more apparent. OOP and many of the other techniques introduced are about making code reusable, flexible and efficient.

You should use them as and when you feel they are appropriate for the purposes of your program, but don’t force them in for the sake of it. Always strive for efficiency in your code.

Getting into the habit of creating classes where appropriate means you will open yourself up to create extensible code that you can reuse in other projects. For example, if you’re creating a game implement a Character class for your main player, you will likely find you can then reutilise this code in future projects.

In some instances you might never find a need to encapsulate your data (e.g. if your the only one who will ever use the code), but knowing the principle and getting into the habit of encapsulating data when appropriate will make you a better programmer going forward. Similarly, you might not often find the need to utilise polymorphism, but an understanding of the technique means you can utilise it in your code when you encounter a situation where its use is appropriate.

