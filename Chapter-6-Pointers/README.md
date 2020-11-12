# Chapter 6 - Pointers

* [What are Pointers?](#what-are-pointers)
  * [Pointers = The Basics](#pointers---the-basics)
  * [Declaring a Pointer](#declaring-a-pointer)
  * [Assigning Values to Pointers](#assigning-values-to-pointers)
  * [Dereferencing Pointers](#dereferencing-pointers)
  * [Pointer Arithmetic](#pointer-arithmetic)
* [Passing by Pointer](#passing-by-pointer)
  * [Pass by Reference or Pointer?](#pass-by-reference-or-pointer)
* [Handling Memory](#handling-memory)
  * [New and Delete](#new-and-delete)
  * [Array Allocation](#array-allocation)
  * [When Should You Allocate Memory](#when-should-you-allocate-memory)
* [Further Reading](#further-reading)

## What are Pointers?

Pointers are a key aspect of C++ and what differentiates it from other programming languages such as Java or Python. Pointers are one of the reasons why C++ can be highly efficient as they can allow you to manage memory in the programs you write, which other languages don’t.

The subject of pointers is large and not everything will be covered in this workbook, as with every concept introduced here you are encouraged to explore more to further your understanding and some useful resources are included at the end of this chapter. Whilst there is lots that could be covered regarding pointers, some of which gets complex, the basics covered here are relatively simple…

&nbsp;
&nbsp;

### Pointers - The Basics

To understand pointers we need to understand how memory is stored and allocated to the programs we write. At a basic level we can view memory as a long (very long) row of sequentially numbered slots.  Each slot can contain one byte of data. When variables are declared in a program the computer reserves the required number of slots to store the data for that variable.

When a program uses a variable it retrieves the value by using the address of the variables first reserved slot (the slot number). This can be seen as similar to a long row of terraced houses that accommodate families. To reference or gain access to a family we can refer to their address.

Pointers are themselves a type of variable, which stores a memory address (slot number). This then provides indirect access to the value stored at these addresses by dereferencing the pointer.

We have touched upon pointers already. Earlier in the chapter on functions we spoke about the address of operator (&) when discussing passing by value versus passing by reference. This operator provides allows us to access the address of variables, which are the values we can assign to pointers. We also looked at [iterators](https://github.com/CodeLab-II-20-21/CodeLab-II/tree/master/Chapter-5-Vectors-and-the-STL#iterators) in the last chapter, a form of pointer that points to the memory addresses of values in container objects (e.g. arrays and vectors). We can use iterators to move through containers and access the value the iterator points to by using the dereference operator (```*```). All of this (and more) can be done with standard (or raw) pointers in C++.

In summary, pointers are just variables that can store the memory address of another variable in your program.

&nbsp;
&nbsp;

### Declaring a Pointer

Pointer variables are declared in the same way as other variables are in a program. However, the data type is immediately followed by an asterix character to identify the variable as a pointer. When creating a pointer it must be given the same data type as the value whose memory address it will stores. For example to store the address of a string variable the pointer must have the type string, whilst to store the address of an int variable the pointer must have the type int.

```C++
int* myIntPtr; //declaration for an int pointer
string* myStringPtr; //declaration for a string pointer
```

&nbsp;
&nbsp;

### Assigning Values to Pointers

We know that pointers store the addresses of other variables, and as discussed when introducing pointers these addresses can be obtained by using the address of operator (&). For example, if we wanted to assign values to the two pointer variables we declared above our code might look as follows.

```C++
int* myIntPtr; //declaration for an int pointer
string* myStringPtr; //declaration for a string pointer

int myNum = 6; //basic int variable
string myWord = "Hello"; //basic string variable;

myIntPtr = &myNum; //assign the address of myNum to myIntPtr
myStringPtr = &myWord; //assign the address of myWord to myStringPtr
```

If you don’t have a value to immediately assign to the pointer you can set them to NULL in either of the following two ways.

```C++
int* myIntPtr = NULL; //declare then set pointer to null
string* myStringPtr = nullptr; //declare then set pointer to null
```

&nbsp;
&nbsp;

### Dereferencing Pointers

As noted when introducing pointers, the values stored at the address assigned to the pointer can be indirectly accessed via the pointer by dereferencing it. For this we need the dereference operator (```*```).

If we continue with the same example from before we can see how pointers can be dereferenced to obtain the value:

```C++
int* myIntPtr; //declaration for an int pointer
string* myStringPtr; //declaration for a string pointer

int myNum = 6; //basic int variable
string myWord = "Hello"; //basic string variable;

myIntPtr = &myNum; //assign the address of myNum to myIntPtr
myStringPtr = &myWord; //assign the address of myWord to myStringPtr

cout << myIntPtr << endl; //output the address stored in the pointer.
cout << *myIntPtr << endl; //output the value stored at address (6)

*myStringPtr = "Hello World"; //reassign value stored at address
cout << myWord << endl; //outputs Hello World
```

In the above code after declaring and assigning values to the int and string pointers, we output the address of the integer pointer, followed by outputting the value at the address by dereferencing the pointer. Next we indirectly access the value stored at the string pointer (again by dereferencing it) and reassign its value to “Hello World” thus the final output will reflect this change. The expected output will look something like this

```
0x22ff04
6
Hello World
```

Note the first value is a hexadecimal address, which is how memory address are represented. The actual value output to the console might differ from the above as memory is dynamically allocated at runtime.

&nbsp;
&nbsp;

### Pointer Arithmetic

As values are stored sequentially in memory we can use basic mathematical operators (e.g: +, -, ++, --) to alter the value a pointer points to. This is especially useful with arrays as array elements occupy consecutive memory addresses. Also arrays and pointers are closely linked as an array name on its own will return the memory address of the first element, thus negating the need to use the address of operator.

The following example demonstrates the use of arithmetic operations to move around a string array. See the comments to understand what is happening in the code.

```C++
//array of strings
string texts[6] = {"Jake", "Coral", "Sam", "Lee", "John", "Ron"};
//point to first element, don't need to use & ahead of array name
string* pTexts = texts;     

pTexts += 3; //moves pointer to fourth element in array
cout << *pTexts << endl;  //outputs Lee

pTexts -= 2; //moves pointer to second element in array
cout << *pTexts << endl; //outputs sam

string *pEnd = &texts[6]; //new pointer assigned address of end element

pTexts = texts; //original pointer reassigned to first element

while(pTexts != pEnd){ //while first pointer is not equal to end pointer
   cout << *pTexts << endl; //output dereference value of pointer
   pTexts ++; //increment pointer through the array
}
```

This same logic is applied when we want to move an iterator around a container. For example if we wanted to start an iterator at the fourth index you could add 4 to the .begin() method.

```C++
vector<string> staff = {"Jake", "Coral", "Sam", "Lee", "John", "Ron"};
staff.insert(staff.begin()+4, "Goni");
```

&nbsp;
&nbsp;

## Passing by Pointer

In the chapter on functions we discussed the differences between [passing by value and passing by reference](https://github.com/CodeLab-II-20-21/CodeLab-II/tree/master/Chapter-3-Furthering-Functions#passing-by-value-vs-passing-by-reference), and how values are copied if passing by value. If wanting to directly modify the value being passed in, or wanting to save the overhead of copying you can alternative pass by reference by including the address of operator (```&```) ahead of the parameter name.

You can also pass by pointer, by making the function parameter a pointer variable. Passing by pointer has the same effect as passing by reference and passes the actual variable to the function. This means any modifications which occur on the variable inside the function will persist outside of the function. The difference when passing by pointer over reference is when calling the function and specifying the parameter value you must pass an address (e.g. prepend the variable with the address of operator - ```&```). This means you also need to dereference the pointer to work with the value itself. This can make it more obvious that the value is not being passed by value than when passing by reference.

```C++
#include <iostream>
using namespace std;

// pass-by-value
void incrementByValue(int num) {
    num = num + 1;
    cout << "q in increment " << num << endl; // num is altered here
}

// pass-by-reference
void incrementByReference(int &num) { // note the & operator appended before the parameter variable
    num = num + 1;
    cout << "q in increment " << num << endl; // num is altered here
}

// pass-by-pointer
void incrementByPointer(int* num) { // note the * operator to signify pointer argument
    *num = *num + 1; //must dereference num to work on the value
    cout << "q in increment " << *num << endl; // num is altered here
}

int main() {
    int num = 3;
    incrementByValue(num);
    // num is not altered here
    cout << "num in main after passing by value" << num << endl;

    incrementByReference(num);
    // num is altered here too
    cout << "num in main after passing by reference" << num << endl;

    incrementByPointer(&num); //must pass address not variable
    // num is altered here too
    cout << "num in main after passing by pointer" << num << endl;
    return 0;
}
```

&nbsp;
&nbsp;

### Pass by Reference or Pointer?

As passing by reference and pointer enable the same behaviour and prevent the copying of the value being passed in you might be wondering which one to use. The general rule is that you should prioritise passing by reference if you do not want to copy the value unless ```NULL``` is an acceptable value as only pointers can have a ```NULL``` value. Cplusplus.com provides and excellent summary here (see bottom of article) including when the parameter should be const: http://www.cplusplus.com/articles/z6vU7k9E/

&nbsp;
&nbsp;

## Handling Memory

One of the major benefits of pointers is the fact they enable us to handle our own memory in C++ programs (something that cannot be done in other languages). This means you have the potential to create highly memory efficient programs.

The way we are able to allocate memory is due to how that memory is allocated. There are two ways memory is allocated in a C++ program; either on the stack or on the heap.

* *Stack* - Fixed storage area where local variables and objects get allocated
* *Heap* - Flexible storage area of unused memory available for allocation

All of the programs we’ve been creating so far will have been making use of our programs “stack”. This is where all local variables and objects we declare inside our program get allocated while they are in scope. As soon as they go out of scope this memory is freed again. This is all done without you as the programmer needing to worry about anything.

In some cases we may wish to have more control over this memory allocation to make our programs more efficient. For instance, the stack only has a fixed storage area (1mb - 8mb), so if we have large objects in our programs that require more space these must be allocated to the heap. We might also have instances where the amount of memory we require is not known until the program is in use. In C++ we therefore have access to the heap where we can dynamically allocate memory as and when we need it.

&nbsp;
&nbsp;

### New and Delete

To dynamically allocate memory in C++ we can use the new and delete keywords.

* *New* - used to allocate memory.
* *Delete* - used to deallocate memory when it’s no longer needed.

When allocating memory we have to use pointers, as when memory is allocated the address is returned and pointers are variables that can store memory addresses. We can then assign data to that address by dereferencing the pointer.

One word of caution is that whenever you use ```new``` you must remember to call ```delete``` when the object or variable allocated to this memory is no longer needed. Otherwise memory leaks can occur in the program as the data remains in memory until delete is called.

```C++
//create memory for an int with the value 8 using the new keyword.
//Assign this memory to pointer
int* point = = new int(8);
cout << point << endl; //output the memory address assigned to the pointer
cout << *point << endl; //output the value being pointed to (8)

*point = 22; //assign the value from 8 to 22
cout << *point << endl; //output the value being pointed to (22)
delete point; //delete the memory
```

The above code demonstrates a simple example of dynamic memory allocation. This code does the following:

1. Allocates memory for an int with the value 8 using the new keyword. The value returned from this memory allocation will be the address of the newly allocated memory that can be assigned to the int pointer
2. Output the address of the allocated memory
3. Deference the pointer to output the value stored at this address
4. Re-assign the value from 8 to 22 via the pointer
5. Output this new value
6. Delete the memory from the heap now we’ve finished using it.

&nbsp;
&nbsp;

### Array Allocation

If wanting to dynamically allocate memory for arrays the synatx is very similar to a standard variable, but note the use of array notation when calling delete. Also you will notice you do not need to explicitly dereference the pointer using ```*``` to access the array values. This is because the subscript operators ```[ ]``` dereference the pointer to the index indicated.

```C++
int *iPointer = new int[3];
iPointer[0] = 3;
iPointer[1] = 4;
iPointer[2] = 8;


for(int i = 0; i < 3; i++){
    cout << iPointer[i] << " ";
}

delete[] iPointer;
```

However, rather than dynamically allocating a basic array it is preferable to instead use a vector which dynamically allocates the values it stores to the heap without the need for you as the programmer to call new and delete. As discussed in the previous chapter you then also have the benefits of being able to resize the storage container and make use of the vector class methods.

&nbsp;
&nbsp;

### When Should You Allocate Memory?

The simple answer is when you need to and in most instances you probably won’t need to. For handling primitive data types such as ints, chars etc stack storage is perfectly sufficient and quicker in terms of allocation and access. Therefore always prioritise the stack unless the object/data you are working with is particularly large, or you need the memory to persist after the scope of its creation.

Another reason for prioritising stack storage is because handling memory can be error prone and lead to memory leaks (e.g. forgetting to call delete). However C++ has made this somewhat easier with the use of smart pointers that automatically handle the calling of new and delete for you. For example a unique_ptr will automatically call delete when the pointer goes out of scope:

```C++
int main() {

  {
     unique_ptr<int> ptr = make_unique<int>(8) //allocate memory for int
     cout << *ptr << endl; //output value at pointer
  }//pointer goes out of scope - delete automatically called

    return 0;
}
```

To learn more about pointers and smart pointers take a look at the further reading resources below. Also take a look at the examples of using pointers with class objects here.

Note you may need the memory header to access smart pointers:

```C++
#include <memory>
```

&nbsp;
&nbsp;

## Further Reading

* [Learning C++ Pointers - LinkedIn Learning](https://www.linkedin.com/learning/learning-c-plus-plus-pointers/)
* [C++: Smart Pointers - LinkedIn Learning](https://www.linkedin.com/learning/c-plus-plus-smart-pointers/)
* [Smart Pointers (Modern C++) - Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019)

