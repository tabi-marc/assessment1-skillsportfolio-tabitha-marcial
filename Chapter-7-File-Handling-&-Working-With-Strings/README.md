# Chapter 7 - File Handling & Working with Strings

* [File Handling](#file-handling)
  * [Declaring a File Stream Object](#declaring-a-file-stream-object)
  * [Writing Data to Files](#writing-data-to-files)
  * [Altering Default Writing Behaviour](#altering-default-writing-behaviour)
  * [Reading from Files](#reading-from-files)
  * [Formatting with getline](#formatting-with-getline)
  * [Moving Around a File](#moving-around-a-file)
  * [Getting the Current Position](#getting-the-current-position)
* [String Streams](#string-streams)
* [Working with Strings](#working-with-strings)
  * [Append](#append)
  * [Find](#find)
  * [Replace](#replace)
  * [Insert](#insert)
  * [Erase](#erase)
  * [Substring](#substring)
  * [toupper and tolower](#toupper-and-tolower)

&nbsp;
&nbsp;

## File Handling

The ability to read and write data from files through file handling is useful to be able to load or save information to and from our programs. The use of file handling can make your programs much more dynamic as you have much more to work with than just the data that is *‘hard coded’* into your program.

To access the functionality we need for working with files we can use the C++ ```fstream``` library. This can be accessed by adding the following include to the top of the program:

```C++
#include <fstream>
```

To work with files we need to create a file stream object in our program. There are two file stream objects included in the ```fstream``` library. The first is ```ofstream``` (output file stream), which is used for outputting (writing data to files). The second if ```ifstream``` (input file stream), which is used for inputting (reading data from files) data from files into our program. ```ofstream``` works similar to ```cout``` and data can be output to the file using the same ```<<``` insertion operators. ```ifstream```, thus works similar to ```cin``` and data can be extracted from the file stream in the same way using the extraction operators ```>>```.

&nbsp;
&nbsp;

### Declaring a File Stream Object

Declaring a file stream object is similar to how we declare other variables in C++. First we specify the data type of the object (e.g. ofstream or ifstream), next we give this object a variable name and immediately follow this with the file name we want to access in parentheses. The syntax looks like this:

```C++
ofstream myOutputFile("program-data.txt"); //output file stream
ifstream myInputFile("program-data.txt"); //input file stream
```

&nbsp;
&nbsp;

### Writing Data to Files

As noted above we use the output file stream to write data to files. When you declare an output file stream object and name the file you want to access in parentheses, the default behaviour is to overwrite this file if it already exists. If it doesn’t exist a new one will be created. Once the ```ofstream``` object has been declared it is good practice to check it has actually been created and can be accessed. We can do this by using the ```.is_open()``` method:

```C++
if(myOutputFile.is_open()){
   //do file handling stuff
}
```

After we have finished writing data to the file it is also good practice to ensure we always close the file. This can be done using the .close() method.

```C++
myOutputFile.close();
```

To actually write some data to the file we can use the insertion operators on the output file stream object, just like we would to output information to the console with cout. For example, if we wanted to write “Hello World” to a file the syntax would be

```C++
myOutputFile << "Hello World" << endl;
```

Let’s see an example of a full program piecing together everything described above. In this program we include the fstream library at the top. In the main program we then declare an output file stream object and check its ready to be written to using .good(). Once we know the file is ready to go we ask the user for their name and age (temporarily storing input into a string variable), and write this data to the file using the << extraction operators. When we are finished writing the data we close the file stream object.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){
    ofstream outputFile("program-data.txt"); //declare output file
    if(outputFile.is_open()){ //check file is good
        string userInput; //string variable to temp store user input
        cout << "What's your name?" << endl; //ask for user input
        getline(cin, userInput); //get user input
        outputFile << userInput << endl; //write name to file

        cout << "How old are you?" << endl;//ask for user input
        cin >> userInput;//get user input
        outputFile << userInput; //write age to file.

        outputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }
    return 0;
}
```

&nbsp;
&nbsp;
> **Advanced Note** - XCode Note
>On XCode you need to get permission to read and write to the file in your project. To do this go to:
> ```Product →  Scheme →  Edit scheme```
> Make sure the Options tab is selected on the window that appear then locate the Working Directory option. Check this box and set the directory file path to the same folder as your main.cpp file is located.

<p align="center">
  <img src="https://jakehobbs.co.uk/markdown_images/xcode-file.png">
</p>

&nbsp;
&nbsp;

### Altering Default Writing Behaviour

By default when writing to files it will be opened in truncate mode. This means all the contents in the existing file will be removed and replaced with the new data being written. We can change this behaviour by including an optional parameter after after the filename specified when declaring the file stream object. Multiple modes can be selected by including a | between each one. The available modes for filestream objects are listed in the table below.

| Mode       | Behaviour                    |
|------------|------------------------------|
| ios::out   | Open file to write output    |
| ios::in  | Open file to read input    |
| ios::app   | Open a file and append output at the end of existing content. Data will always be appended to the end, even if seeking to different position   |
| ios::trunc  | Replace existing content when writing (default behaviour)    |
| ios::ate  | Open file and seek to end for writing new data. However in comparison to ios::app can seek anywhere in file to begin writing new content. To avoid truncating the file using in combination with ios::in.    |
| ios::binary | Treat the file as binary format rather than text so the data may be stored in non text format.   |

The most commonly specified mode is ios::app which ensures content is appended to the end rather than overwriting existing data. The syntax for opening a file in append mode would look like this:

```C++
ofstream myOutputFile("program-data.txt", ios::app);
```

If we were to alter our previous example and specify the file be opened in append mode as above, each time the program runs the new content will be added to the end of the file.

&nbsp;
&nbsp;

### Reading From Files

The basic process for reading from files is not too dissimilar to writing. The main difference is that we need to use the input file stream (ifstream) and utilise extraction operators ( >> ) to get the data from the file into our programs.

Let's imagine we have the following data in a text file called customers.txt (included in repository):

```
Joe Bloggs	43	BS2 4CV
Karen Smith	23	EM1 5XY
Garry Jones	18	FG4 8NP
Phil Legg	54	BS1 5NE
```

To read it in we create an ```ifstream``` object, then check the file exists using the ```is_open()``` method.  Once we know the file is open we can then extract the data from the file. We can do this using ```getline()```, like we’ve done before when getting user input from the console. However, instead of specifying ```cin``` as the first parameter of the ```getline()``` call we specify we want to get the line from our input file stream and store this into a string variable. We can then output the string variable to the console.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){

    ifstream inputFile("customers.txt"); //declare output file stream

    if(inputFile.is_open()){ //check file is open
        string data; //string variable to temp store data
        getline(inputFile, data);//get data from file into variable
        cout << data << endl; //output data to console
        inputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }

    return 0;
}
```

If you run the above code with the data in the text file you will notice it only outputs the first line:

```
Joe Bloggs	43	BS2 4CV
```

This is because the code to read in the data is only run once. By now we know that when we want to repeat code we should make use of loops. In this case a while loop is most appropriate as we don’t know how long the file might be. Therefore, to ensure we read the whole file we can use a while loop with the condition ```! inputFile.eof()```.

This condition says while we are NOT at the end of file (notice the use of the not operator ! ). Thus, we wrap the code which is reading the data line by line (first three lines inside the IF block) inside a while loop to keep reading WHILE we are NOT at the end of the file. The ```inputFile.close();``` should be included after the while loop as we do not want to close the file until we have finished reading all the data.

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){
    ifstream inputFile("cusstomers.txt"); //declare output file stream

    if(inputFile.is_open()){ //check file is open
        while(!inputFile.eof()){//while not at end of file
            string data; //string variable to temp store data
            getline(inputFile, data);//get data from file into variable
            cout << data << endl; //output data to console
        }
        inputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }

    return 0;
}
```

&nbsp;
&nbsp;

### Formatting with getline

Our code above reads in each line and moves onto the next through the use of ```getline()```. However, we can add a third parameter to the ```getline()``` call to allow us to specify a point where ```getline``` should stop reading a line. This can be useful to separate the text as its read in for storage or formatted output purposes.

The third parameter should be a character where you want ```getline``` to stop reading. Subsequent calls to ```getline``` will continue reading from after the character specified in the previous call. For example consider the code below:

```C++
cout << "Enter a sentence: " << endl;
string sentence;
getline(cin,sentence, ' ');
cout << sentence << endl;
```

If we run the above code and entered *“Hello Codelab”* as the sentence, the subsequent ```cout``` would only output *“Hello”* as ```getline``` has been instructed to read up to the white space character.

Here’s another example. Imagine we have the following sentence in a file:

*I want to separate this line of text into two,everything after that comma should be on a new line*

As instructed by the sentence we want to split it at the comma character. To do so our code would look like this:

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){

    ifstream inputFile("program-data.txt"); //declare output file stream

    if(inputFile.is_open()){ //check file is open
        string data; //string variable to temp store data

        getline(inputFile, data, ',');//get data up to comma
        cout << data << endl; //output to console

        getline(inputFile, data); //get rest of sentence
        cout << data << endl; //output to console

        inputFile.close();//close the file
    }else{
        cout << "File cannot be accessed. Terminating program" << endl;
        return -1; //exit program
    }

    return 0;
}
```

The first ```getline``` in this code would read the line up to the comma character, with the ```cout``` statement outputting that half of the sentence. The subsequent ```getline``` call will pick up from after the comma and get the rest of the line. Therefore our output would look like this:

```
I want to separate this line of text into two
everything after that comma should be on a new line
```

We can use this logic to nicely read in and format the customers.txt data from the previous example of reading in a whole file. The data in this file is separated by a tabbed space, which can be represented as a character using ‘\t’. There are a few additional things going on in our modified program below including:

* Adding an array to store each piece of data
* The use of a third parameter in getline to separate the data as its read in
* Non typical increments in the for loop to correctly output the data.

Read the comments to see what is happening….

```C++
#include <iostream>
#include <fstream> //include the file stream library
#include <string>
using namespace std;

int main(){
    /* string array to store data from file
     there are 12 pieces of data in total */
    string data[12];

    //declare output file stream
    ifstream inputFile("customers.txt");

    int pos = 0; //variable to move through array indexes

    //check file is open
    if(inputFile.is_open()){
        //while not at end of file keep reading
        while(!inputFile.eof()){
            /* - if statement to check which piece of data is being read
               - if it's the third piece it is at the end of the line so   
                 ignore newline character
               - if its the the first two ignore we want to ignore the
                 tab character */
            if((pos+1) % 3 == 0){
                //get data up to new line character
                getline(inputFile, data[pos], '\n');
            }else{
                //get data upto tab character
                getline(inputFile, data[pos], '\t');
            }
            //increment pos so data gets input to next array position
            pos++;
        }
        inputFile.close();//close the file
        pos = 0;//reset position
    }else{
        //output message if file not read
        cout << "File cannot be accessed. Terminating program" << endl;
        //exit program
        return -1;
    }
    //OUTPUT DATA FROM ARRAY
    cout << "Customers" << endl;
    cout << "=========\n" << endl;
   /* for loop to run through array note it gets incremented by three each
      Time this is because there are three pieces of data on each line
      We want to output all three on each iteration then skip to the next line*/
    for(int i = 0; i < 12; i+=3){
        cout << "Name: " << data[i] << endl;//output name
        //output age - note 1 is added to i to move array index along          
        cout << "Age: " << data[i+1] << endl;
        //output postcode - note 2 is added move array index along again
        cout << "Postcode: " << data[i+2] << endl;
        cout << endl;//output blank line
        /* first time loop runs we output data at array indexes 0, 1, 2
         on the second iteration we output indexes 3, 4, 5
         on the third iteration we output indexes 6, 7, 8
         on the fourth iteration we output indexes 9, 10, 11
         now we've reached the end of the array so loop terminates */   
    }
    return 0;
}
```

The output from this program once the data is read in will look as follows

```
Customers
=========

Name: Joe Bloggs
Age: 43
Postcode: BS2 4CV

Name: Karen Smith
Age: 23
Postcode: EM1 5XY

Name: Garry Jones
Age: 18
Postcode: FG4 8NP

Name: Phil Legg
Age: 54
Postcode: BS1 5NE
```

&nbsp;
&nbsp;

### Moving Around a File

There may be occasions where you want to move around a file in order to read or write data at a specific point, or to jump to the beginning or end of the file. There are two different method calls we can use dependent on whether we are reading or writing to the file.

```C++
seekp(pos); //used on ofstream objects
seekg(pos); //used on ifstream objects
```

In both cases ```pos``` relates to the number of characters from the beginning of the file you wish to seek. For example the following would move five characters from the beginning of an output filestream

```C++
seekp(5); //seek 5 characters from the beginning
```

By default seek will start from the beginning of the file. However, we can add further parameters to the ```seekp()``` or ```seekg()``` calls to explicitly specify whether we want the seek to start from the beginning, end or current position in file.

```C++
seekp(5, ios::beg); //seek 5 characters from the beginning
seekp(-10, ios::end); //seek 10 characters back from the end
seekp(8, ios::cur); //seek 8 characters from the current position
```

The above work for both ```seekp``` (ofstream objects) and ```seekg``` (ifstream objects).

Note If seeking a position in an output file and then writing new data, the new data will overwrite any existing content from that position. It will not insert the data into the middle of the file from that point. If you want to insert into the middle you should copy the contents of the file, insert the new data and rewrite back to the file.

&nbsp;
&nbsp;

### Getting the Current Position

Whilst ```seekp() / ```seekg()``` will move you to a particular position in a file ```tellp()``` / ```tellg()``` will let you know what position you are at.

```C++
int pos = oFile.tellp(); //get position in ofstream
cout << pos << endl; //output position
```

We can use a combination of seek and tell to determine if a file is empty, as if we seek to the end of the file and the current position is 0 then there cannot be any content in the file. See the example below which could be used to check if a file is empty before attempting to read from it.

```C++
ifstream iFile("myfile.txt" ); //declare input file stream
iFile.seekg(0, ios::end); //seek to end of file
int pos = iFile.tellg(); //get position
if(pos == 0){ //if position is 0 file must be empty
    cout << "File is Empty" << endl;
    iFile.close();
}else{
    cout << "File not empty" << endl;
}
```

Take a look at the C++ documentation for a full list of the methods that can be used on input and output file streams.

https://en.cppreference.com/w/cpp/io/basic_ofstream
https://en.cppreference.com/w/cpp/io/basic_ifstream

&nbsp;
&nbsp;

## String Streams

As we are on the subject of streams from the previous chapter it seems like a good time to introduce the string stream object.

One issue with a standard string variable is that they cannot easily be converted other native data types such as ints through casting. Therefore imagine you had someone's age as a string value you could not cast this to an int to perform arithmetic operations such as incrementing the value.

The solution to this is the stringstream object, which can be used to convert string values to numeric values and visa versa. To access the string stream object we need to include the sstream library at the top of our program:

```C++
#include <sstream>
```

We declare a stringstream object in our program by specifying its type and then giving it a variable name

```C++
stringstream mystream;
```

Adding and extracting the data to the stringstream is done through the familiar insertion (```<<```) and extraction (```>>```) operators.

To reset the string stream to be used again it should be reset to its original state. This requires its contents to be set to empty and flags to be cleared

```C++
mystream.str(""); //set contents to empty
mystream.clear(); //clear flags
```

&nbsp;
&nbsp;

#### Example - int to string

The following shows the stringstream in action. At the beginning of the program we create a string and an int variable to store some biographical data we then want to output as a string. However, we cannot simply concatenate the string and int together and assign this to ```bioInfo```.

Instead we make use of a stringstream object and insert the desired data into the this object (```mystream```) using the insertion operators. We can then access the contents of the stringstream using the ```.str()``` call (this returns the contents of the stringstream as a string) and assign this to ```bioInfo```, which is then output to the console.

```C++
#include <iostream>
#include <sstream> //include the string stream library
#include <string>
using namespace std;

int main(){
    string name = "Jake Hobbs";
    int age = 34;
    string bioInfo;
    //bioInfo = name+age; <-- this won't work

    stringstream mystream;
    mystream << "Name is: " << name << endl;//insert string into stream;
    myStream << "Age is: " << age;//insert numeric data into stream;
    bioInfo = myStream.str();//make bioInfo equal to the contents of stream;

    cout << bioInfo << endl;

    mystream.str(""); //set contents to empty
    mystream.clear(); //clear flags

    return 0;
}
```

&nbsp;
&nbsp;

#### Example - string to int

The above example loads numeric data into the stringstream so it can be converted to a string. The next example does the opposite and takes numeric information from a string and assigns it to an int.

The code starts with a string that contains a series of numerical values. What we want to do is to convert these into ints and store them in an array. We do this by inserting the string into the stringstream object. Next we have a for loop to extract each number into the array indexes. This works as the extraction operator knows what data it is expecting and reads until it encounters invalid data (just like on ```cin```). As it is expecting int values to place into the integer array, it accepts the numeric values but stops as soon as it reaches the space character. Therefore, on the next loop iteration it picks up where it left off and gets the next numeric value.

Finally we use a range based for loop to output the newly inserted numeric values stored in the array.

```C++
#include <iostream>
#include <sstream> //include the string stream library
#include <string>
using namespace std;

int main(){
    string numberString = "1 23 4 567 778";//string with numeric info
    stringstream ss; //stringstream object
    int myArray[5]; //array to store numeric values
    ss << numberString; //insert number string into stream

    //for loop to get numbers into array
    for(int i = 0; i<5; i++){ //for loop to run through array
        ss >> myArray[i]; //extracts numeric value up to white space
    }

    //for loop runs through and outputs each array value
    for(int num : myArray){
        cout << num << " ";
    }

    mystream.str(""); //set contents to empty
    mystream.clear(); //clear flags
    return 0;
}
```

As a stringstream is a stream it has all the same functionality as other streams in the C++ library such as file streams. Therefore, you can access similar methods such as ```seekg()``` and ```tellg()```

For full list of available methods see: https://en.cppreference.com/w/cpp/io/basic_stringstream

&nbsp;
&nbsp;

## Working with Strings

The string class has many methods that allow you to get information about, or modify string values. We’ve seen some of these already, including .length() to work out how many characters are in a string and .compare(), which can be used to check if two strings are equal. Further examples of some of the main string methods are included below

You can see the full list of available methods with examples here: https://en.cppreference.com/w/cpp/string/basic_string

&nbsp;
&nbsp;

### Append

The ```append()``` method will add additional characters to a string. In its simplest form the method takes a single string argument and will add these characters to a string. However, by including different sets of parameters to the method call alters the exact nature of the ```append()``` method. See the examples below:

```C++
string str1 = "Hello";

str1.append(" World"); //appends entire string to end
cout << str1 << endl; //outputs Hello World

str1.append(3, '!'); //appends specified character three times
cout << str1 << endl; //outputs Hello World!!!

str1.append("CodeLab", 0, 4); /* appends part of specified string
                     starting a position 0 for 4 characters e.g. Code */
cout << str1 << endl; //outputs Hello World!!!Code

str1.append("CodeLab", 4, 3); /* appends part of specified string
                    starting a position 4 for 3 characters e.g. Lab */
cout << str1 << endl; //outputs Hello World!!!CodeLab
```

More details: https://en.cppreference.com/w/cpp/string/basic_string/append

&nbsp;
&nbsp;

### Find

The ```find()``` method finds the first occurence of the specified characters in a string. The method returns a ```size_t``` value, which is used to represent the size of an object. Therefore, when used with ```.find()``` it represents the size or length of the string at the point which the specified word is found.

We can compare the returned value against ```string::npos```, which represents the highest possible value for a ```size_t``` object. We can view ```npos``` as meaning no position or not found as to be equal we have reached the end of the string. Thus, when comparing the ```size_t``` value returned from ```.find()``` against ```string::npos``` we want to ensure it is *NOT EQUAL* as the position we get should be before the end if it is found.

```C++
string str1 = "Hello World, Welcome to CodeLab";

size_t pos = str1.find("World");
if(pos != string::npos){
    cout << "Found 'World' at position " << pos << " in string" << endl;
}else{
    cout << "Could not find 'World'" << endl;
}
```

This first example demonstrates the use of find to search for the word *“World”* in the string *“Hello World, Welcome to Codelab”*. Note here that the value returned from the ```.find()``` call is assigned to a ```size_t``` variable called ```pos```. We then compare pos against ```string::npos``` to determine if the string is found. If it is we output a message that includes the position ‘World’ was found. This will output:

```
Found 'World' at position 6 in string
```

The above can be streamlined slightly by directly comparing the ```.find()``` call against ```string::npos``` in the IF statement and omitting the ```size_t``` variable assignment. This can be done if you do not need to know the position where the string is found

```C++
string str1 = "Hello World, Welcome to CodeLab";

if(str1.find("World") != string::npos){
    cout << "Found 'World' in string" << endl;
}
```

Just like ```.append()``` including different sets of parameters in the ```.find()``` method call can alter its behaviour. For example we can specify where we want the search to start by providing a number after the word to be searched.

```C++
string str1 = "Hello World, Welcome to CodeLab";

if(str1.find("World", 10) != string::npos){
    cout << "Found 'World' in string" << endl;
}else{
    cout << "Can't find 'World'" << endl;
}
```

This example will output “Can’t find ‘World’” as the find has been started at character position 10 in the string, which is after the occurence of World.

We can also specify that we only want to search for part of a string by providing two values after the string parameter. These two values represent the starting position and the number of characters of the string specified. Therefore in the below example, whilst *“Hello Universe”* has been specified in the ```.find()``` call, this has been limited to 5 characters starting from position 0 (e.g. *“Hello”*). Therefore ```“Found ‘Hello’ in string”``` will be output.

```C++
string str1 = "Hello World, Welcome to CodeLab";
//just search for 5 characters in "Hello Universe" staring a position 0
if(str1.find("Hello Universe", 0, 5) != string::npos){
     cout << "Found 'Hello' in string" << endl;
}else{
    cout << "Can't find 'Hello'" << endl;
}
```

More Details: https://en.cppreference.com/w/cpp/string/basic_string/find

&nbsp;
&nbsp;

### Replace

Replace can be used to replace the contents of a string with another string value. The main parameters are the position to start the replacement, the number of characters to be replaced and the string to replace these characters with. For example the below code replaces *"World"* with *"Universe"* as World starts at position 6 in the original string and is 5 characters long.

```C++
string str1 = "Hello World, Welcome to CodeLab";
str1.replace(6, 5, "Universe");
cout << str1 << endl; //will output Hello Universe, Welcome to CodeLab
```

https://en.cppreference.com/w/cpp/string/basic_string/replace

&nbsp;
&nbsp;

### Insert

The insert method is used to insert a string at the position specified, with this position being the first parameter and the string the second parameter.

```C++
string str1 = "Bath University";
str1.insert(4, " Spa");
cout << str1 << endl; //will output Bath Spa University
```

Similar to ```.find()``` you can also specify partial strings to be inserted. See here for more details: https://en.cppreference.com/w/cpp/string/basic_string/insert

&nbsp;
&nbsp;

### Erase

Erase is used to remove parts of a string. The main parameters are the position to start erasing, followed by the number of characters to erase. For example the below code removes the word *“Hate”* which starts at position 14, and also erases the the white space after the word hence 5 being specified as the length.

```C++
string str1 = "I have a love hate relationship with programming";
str1.erase(14, 5);
cout << str1 << endl; //I have a love relationship with programming
```

More Details: https://en.cppreference.com/w/cpp/string/basic_string/erase

&nbsp;
&nbsp;

### Substring

The ```.substr()``` method returns a new string from a portion of the string the method is used on. Two parameters can be provided to the ```.substr()``` method, the first is the position to begin taking the substring, the second is the number of characters to take. If only the position is specified the remainder of the string after the position will be returned.

For example in the following code, ```.substr()``` starts at character 13 and takes the remainder of str1 to assign *“Welcome to CodeLab”* to the ```str2``` variable.

```C++
string str1 = "Hello World, Welcome to CodeLab";
string str2 = str1.substr(13);
cout << str2 << endl; //Outputs Welcome to CodeLab
```

Whilst this next example just assigns “Welcome” to str2 as the number of characters to take is also specified.

```C++
string str1 = "Hello World, Welcome to CodeLab";
string str2 = str1.substr(13, 7);
cout << str2 << endl; //Outputs Welcome
```

More details: https://en.cppreference.com/w/cpp/string/basic_string/substr

&nbsp;
&nbsp;

### toupper and tolower

Whilst not part of the string class itself, ```toupper``` and ```tolower``` are useful methods to use if you need to convert a string to upper or lower case. There are two core methods to do this. The first is to use a for loop to run through the string and individually convert each letter. The second is to use the ```.transform()``` method from the algorithm library and include ```toupper``` or ```tolower``` as one of the parameters. Examples for each are included below

```C++
string str1 = "Hello World";

//for loop method
for(int i = 0; i < str1.length(); i++){
    str1[i] = toupper(str1[i]);
}
cout << str1 << endl; //outputs HELLO WORLD

//transform method
transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
cout << str1 << endl; //outputs hello world
```

As noted previously there are many more string methods than shown here. Explore the documentation to learn about more:

https://en.cppreference.com/w/cpp/string/basic_string

