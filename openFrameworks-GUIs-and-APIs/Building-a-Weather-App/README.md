# Building a Weather App with openFrameworks

* [Getting Started](#getting-started)
* [Accessing the openWeatherMap API](#accessing-the-openweathermap-api)
* [Setting up the Project](#setting-up-the-project)
* [Using this Section](#using-this-section)
* [App Aims](#app-aims)
* [main.cpp](#maincpp)
* [ofApp.h](#ofApph)
  * [Includes](#includes)
  * [openFrameworks Functions](#openframeworks-functions)
  * [Custom Functions](#custom-functions)
  * [Standard Variables](#standard-variables)
  * [openFrameworks Variables](#openframeworks-variables)
* [ofApp.cpp](#ofappcpp)
  * [setup()](#setup)
  * [getWeatherData()](#getweatherdata)
  * [getDate()](#getdate)
  * [getBackground()](#getbackground)
  * [keyPressed()](#keypressed)
  * [draw()](#draw)

&nbsp;
&nbsp;

## Getting Started

This section provides a step by step guide on how to build a simple weather app using openFrameworks. The material covered here will complement a class lecture demonstrating how to build the app.

The app makes use of the openWeatherMap API to retrieve data and uses the openFrameworks addon  ```ofxJSON``` to read in the data. This addon can be downloaded from here:
https://github.com/jeffcrouse/ofxJSON (the G.32 PC’s should already have this addon included in the openFrameworks folder).

This addon should be unzipped then placed in the addons folder of your openFrameworks installation.

We will be using the current weather API from openWeatherMap. Documentation on this API can be viewed here:
https://openweathermap.org/current

&nbsp;
&nbsp;

## Accessing the openWeatherMap API

To access the openWeatherMap API you will need to sign up for an account. This is free and can be done at the following link:
https://home.openweathermap.org/users/sign_up

Once you have signed up can access your API key, this will allow you to retrieve the weather data.

To do so go to the following link:
https://home.openweathermap.org/api_keys

&nbsp;
&nbsp;

## Setting up the Project

* Open the project generator and give the project a name (e.g. WeatherApp).
* Include the ```ofxJson``` addon in the addons box.
* Click ```Generate```
* Click ```open in IDE``` and run the project (if you get a grey window the project has successfully generated
* Locate the fonts folder provide in this section of the GitHub repository, this contains the fonts used in the project (you may use different fonts if you wish). Copy the font files in this folder to the ```bin → data``` folder of your openFrameworks project.
* Clean up the functions in the ```ofApp.h``` and ```ofApp.cpp``` so you just have the following functions left
  * setup();
  * update();
  * draw();
  * keyPressed();

&nbsp;
&nbsp;

## Using this section

This section should be used in conjunction with the class materials provided when a live demo for this app is delivered. The code for this project will be written across three files (```main.cpp```, ```ofApp.h```, ```ofApp.cpp```). These should get automatically generated when you setup the project as per the instructions above. When working through this section the code for each file is presented in full, before being broken down to provide further information about what is happening at each step.

Don’t just jump in and copy the code without taking time to read the comments and additional instructions. As you are working through ensure you understand what is happening on each line of code, if you are unsure just ask. Also if you feel confident, feel free to experiment and modify some of the code to make the weather app your own.

&nbsp;
&nbsp;

## App Aims

The aims for this app are to build a simple weather app with the following features:

* Read in data for weather
* Output data to graphics window
* Load in images relating to current conditions
* Modify background based on temperature
* Use key presses to interact

Along the way we will make use of our own functions to improve the efficiency of the program.

<p align="center">
  <img width="20%" src="https://jakehobbs.co.uk/markdown_images/weather-app-wireframe.png">
</p>

&nbsp;
&nbsp;

## main.cpp

The ```main.cpp``` file in an openFrameworks project sets up the app by initialising the graphics window and launching a new instance of the ```ofApp``` class that will contain the code to run our program.

We will make one small modification here to alter the size of the graphics window to 320x480 (*yes this is rather small, there is a reason for this*).

```C++
#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofSetupOpenGL(320,480,OF_WINDOW); // <-------- setup the GL context
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
}
```

&nbsp;
&nbsp;

## ofApp.h

In C++ we make use of header files to declare the data members (variables) and methods (functions) that characterise our classes. In this program we will just be using one class (the default ```ofApp```) that will hold all the variables and functions to run our program.

In ```ofApp.h``` we want to declare all the variables, objects and functions we will use in our program, we then fully define the implementation of these in the ```.cpp```

```C++
#pragma once

#include "ofMain.h" //access to main openframeworks functionality
#include "ofxJson.h" //access to ofxJson addon
#include <string> //access to string functionality
#include <sstream> //access to stringstream functionality
#include <time.h> //access to time functions
using namespace std;

class ofApp : public ofBaseApp{

public:
    //key Openframeworks functions
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    //Custom functions
    void getWeatherData(); //retrieve JSON data
    string getDate(time_t dateID, int s); //converts numeric timestamp to string
    void getBackground(int temp); //sets background gradient based on temperature value
    //Standard Variables
    bool parseSuccess; //boolean used to check if JSON data is received successfully
    stringstream weatherInfo; //string stream used to insert weather information
    string APIKey, APICall, errorMsg, date, dateText, city, menu; //string variable used in APP

    //openFrameworks objects
    ofxJSONElement json;//JSON data object - stores JSON data from API Call
    ofTrueTypeFont headTXT, subHeadTXT, mainTXT, menuTXT;//Font objects
    ofColor c1, c2;//Colour objects, used to set gradient
    ofHttpResponse imgURL; //Http response object to retrieve image icons
    ofImage weatherIcon; //Image object to display weather icon
};
```

Let's break down the elements of this header file one by one...

&nbsp;
&nbsp;

### Includes

```C++
#include "ofMain.h" //access to main openframeworks functionality
#include "ofxJson.h" //access to ofxJson addon
#include <string> //access to string functionality
#include <sstream> //access to stringstream functionality
#include <time.h> //access to time functions
```

Our includes give us access to different parts of the C++ standard library, the openFrameworks toolkit and addons we wish to use (e.g. ```ofxJson```). We will be using a ```stringstream``` to easily convert data of different types to strings, and accessing the time header to do some timestamp conversion.

&nbsp;
&nbsp;

### OpenFrameworks Functions

```C++
//key Openframeworks functions
void setup(); //runs once when app launches - good place to initialise variables and load in assets
void update(); //runs every frame (e.g. 60 times a second) - good place to update variables
void draw(); //runs immediately after update, anything we want to draw to the screen must be done here
void keyPressed(int key); //used to determine which key has been pressed by the user.
```

When you generate an openFrameworks project the default ```ofApp``` class comes with some in built functions that handle the main running of the program and enable user interaction. We will be making use of 4 of these as (the others that may be present when generating the project can be removed).


&nbsp;
&nbsp;

### Custom Functions

```C++
//Custom functions
void getWeatherData(); //retrieve JSON data
string getDate(time_t dateID, int s); //converts numeric timestamp to string
void getBackground(int temp); //sets background gradient based on temperature value
```

These user defined functions will be used to handle operations that occur multiple times in our App. More detailed information on each is included below...

* ```getWeatherData()``` - This function will be used to read in the weather data from the openWeatherMap api and store the information into our programs variables (listed below). This function gets called each time a user presses a key listed on the menu to view a different city. Therefore each time the key is pressed new data gets read in and overwrites the previously stored data.
* ```getDate(time_t dateID, int s)``` - This function will be used to convert a timestamp value that is read in from the openWeatherMap API into a readable string format. This function takes two parameters a ```time_t``` value (```dateID```), which is the timestamp value we can read from the API. An ```int``` value (```s```) is also passed in to determine how to split the string that gets returned as we want separate parts of the converted string in different areas of our app.
* ```getBackground(int temp)``` - This function will be used to determine the background colour of the app. When calling the function we will pass in a temperature value returned by the weather API to the function (```int temp```). Dependant on the temperature returned we will then update the background colour values accordingly.


&nbsp;
&nbsp;

### Standard Variables

```C++
//Standard Variables
bool parseSuccess; //boolean used to check if JSON data is received successfully
stringstream weatherInfo; //stringstream used to insert weather information
string APIKey, APICall, errorMsg, date, dateText, city, menu; //string variables used
```

We will be making use of a number of ```int```, ```string``` and other data type variables in our program to store and manipulate the information retrieved from the weather API. A breakdown of these is included below

* ```parseSuccess``` - ```bool``` value used to determine if the data has been successfully read in from the API. If this ```bool``` is true we can run our app, else we will present an error message to the user.
* ```weatherInfo``` - This ```stringstream``` object will be used to insert data of different types (```int```, ```string```, etc) that we retrieve from the API. We can then easily obtain the info in the ```stringstream``` and draw this on the screen.
* ```APIKey``` - will store the API Key value you obtained from the openWeatherMap site
* ```APICall``` - will store the URL that will be used to retrieve weather data, this will be updated dependant on the city the user wishes to view
* ```date``` - will store the current date after it’s been converted from a timestamp by the ```getDate``` function
* ```dateText``` - ```string``` value returned by the ```getDate``` function. This value then gets stored in the ```date``` variable.
* ```city``` - stores the name of the city currently being viewed by the user
* ```menu``` - stores the string that will be used to display the menu

&nbsp;
&nbsp;

### openFrameworks Variables

```C++
//openFrameworks objects
ofxJSONElement json;//JSON data object - stores JSON data from API Call
ofTrueTypeFont headTXT, subHeadTXT, mainTXT, menuTXT;//Font objects
ofColor c1, c2;//Colour objects, used to set gradient
ofHttpResponse imgURL; //Http response object to retrieve image icons
ofImage weatherIcon; //Image object to display weather icon
```

Alongside the data types and objects declared above that all come from the standard C++ library we will be making use of objects (instances of classes) accessed from openFrameworks.


* ```ofxJSONElement``` - accessed from the ```ofxJSON``` addon, this object will store the data read in from the API.
* ```ofTrueTypeFont``` - these font objects will be used to load in custom fonts. We want fonts of different styles and sizes hence the use of four different object variables
* ```ofColor``` - these colour objects can be used to store ```rgb``` colour values. These will be used to set the background gradient in our app. ```c1``` will be updated by the ```getBackground``` function, whilst ```c2``` will always remain a white that ```c1``` will fade into for a gradient effect.
* ```ofHttpResponse``` - accessed from the ```ofxJSON``` addon, this is used to retrieve images from a url received from the API
* ```ofImage``` - image object that will load in the image returned by the ```ofHttpResponse``` so we can display weather icons in the app

&nbsp;
&nbsp;

## ofApp.cpp

Now we have declared all of the data members (variables & objects) and methods (functions) that our program will use we need to define them. We do this in the class ```.cpp``` file. This file should already have the skeleton definitions for the openFrameworks functions (```setup```, ```update```, ```draw```, ```keyPressed```), but we will need to add code to these as well as adding the definitions for our custom functions. The code required for the ```ofApp``` file is presented per method. Attempting to run the program before all methods have been implemented fully is likely to run into errors. Code for each method is first presented in full, before then being broken down into its component parts to provide additional detail about what is happening. Let's start with the setup function.

&nbsp;
&nbsp;

### setup()

```C++
void ofApp::setup(){
    //load in fonts - ensure the files are in the bin > data folder
    headTXT.load("header.ttf", 30); //main header font
    subHeadTXT.load("header.ttf", 16); //sub header font
    mainTXT.load("font.ttf", 11); //font used for the main text
    menuTXT.load("font.ttf", 8); //font used for the menu text
    //set second gradient color to white
    c2.set(255, 255, 255);
    //menu string
    menu = "1 - Bath  |  2 - Timbuktu  |  3 - Rio De Janiero\n4 - Prudhoe Bay  |  5 - Madrid";
    //Set API Key from OpenWeatherMap
    APIKey = "&APPID=a28ea31b42a0785dc4587fa3d5b1b85a";
    //Set initial weather call to Bath
    APICall = "weather?id=2656173&units=metric"+APIKey;
    //Call weather function to retrieve data
    getWeatherData();
}
```

The setup function runs once, as soon as the app is launched. The setup function should be used to load in assets (e.g fonts) used in the program as well as initialising variables. Let's break down what is happening in our setup function step by step.

&nbsp;
&nbsp;

#### Load in Fonts

```C++
//load in fonts - ensure the files are in the bin > data folder
headTXT.load("header.ttf", 30); //main header font
subHeadTXT.load("header.ttf", 16); //sub header font
mainTXT.load("font.ttf", 11); //font used for the main text
menuTXT.load("font.ttf", 8); //font used for the menu text
```

The first lines of code load in the fonts we want to use in the program and set their size. You will notice I use the two font files twice, but set different sizes on them. This is because we want to have different sized text in different places on the screen.

&nbsp;
&nbsp;

#### Set Second Colour Object Value

```C++
//set second gradient color to white
c2.set(255, 255, 255);
```

This code sets our second colour object (```c2```) to white, this value will be used when we set a background gradient in the draw function. The first colour object (```c1```) will change based on the temperature read in by the weather API, but each colour will always fade into this white colour.

&nbsp;
&nbsp;

#### Set menu Text

```C++
//menu string
menu = "1 - Bath  |  2 - Timbuktu  |  3 - Rio De Janeiro\n4 - Prudhoe Bay  |  5 - Madrid";
```

Here we set our ```menu``` ```string```. This will display the key press options to the user and will be drawn to the bottom of the app screen

&nbsp;
&nbsp;

#### Set API Strings

```C++
//Set API Key from OpenWeatherMap
APIKey = "&APPID=YOURAPIKEY";
//Set initial weather call to Bath
APICall = "weather?id=2656173&units=metric"+APIKey;
```

To access data from the openWeatherMap API we call url addresses which then return json data. These URL always begin with:
http://api.openweathermap.org/data/2.5/

Appended to this is a series of values that specify what information we want back as well as the API Key you generated on openWeatherMap to give you access to the data.

The ```APIKey``` ```string``` variable will hold your API key so we can easily append this to the end of full URL each time we want to access the API. Make sure you replace ```YOURAPIKEY``` with the value obtained from the openWeatherMap website.

The ```APICall``` ```string``` specifies the data we want to get back. The weather part states we want to access the basic weather API, the ```id=2656173``` sets the location to Bath (openWeatherMap has thousands of city codes for locations worldwide) and ```units=metric``` specifies the data format. The ```APIKey``` value set in the line previous is then appended to the end.

The full url call will look something like this:
http://api.openweathermap.org/data/2.5/weather?id=2656173&units=metric&APPID=YOURAPIKEY

If you go to this URL in your browser you will see the JSON data displayed in its raw form (obviously replace ```YOURAPIKEY``` first).

&nbsp;
&nbsp;

#### Get The Weather Data

```C++
//Call weather function to retrieve data
getWeatherData();
```

The last step in the setup is to call the ```getWeatherData()``` function. This will then retrieve the initial data back from the API based on the values given to the ``APICall`` ```string``` in the line previously (e.g. should retrieve data from Bath initially).

We will define this ```getWeatherData``` function and our other custom functions next before returning to the openFrameworks functions (```update```, ```draw```, ```keyPressed```).

&nbsp;
&nbsp;

### getWeatherData()

```C++
void ofApp::getWeatherData(){
    parseSuccess = json.open("http://api.openweathermap.org/data/2.5/"+APICall); //get the json data and check if successful
    if(parseSuccess){ //if parseSuccess is true read in data
        cout << json.getRawString(true); //Output json data to console for reference, remove in final version

        date = getDate(json["dt"].asInt(), 1); //make date string equal to value returned by getDate function
        city = json["name"].asString(); //set city string to city name

        //GET WEATHER INFO
        weatherInfo.str(""); //clear string stream
        weatherInfo << "Temperature: " << json["main"]["temp"].asString() + "c" << endl; //insert temperature
        weatherInfo << "Conditions: " << json["weather"][0]["main"].asString() << endl; //insert conditions
        weatherInfo << "Sunrise: " << getDate(json["sys"]["sunrise"].asInt(), 2) << endl; //get sunrise time via getDate
        weatherInfo << "Sunset: " << getDate(json["sys"]["sunset"].asInt(), 2) << endl; //get sunset time via getDate

        //GET TEMPERATURE
        getBackground(json["main"]["temp"].asInt()); //call getbackground - pass in temperature as parameter

              //GET IMAGE ICON
        imgURL = ofLoadURL("http://openweathermap.org/img/w/"+json["weather"][0]["icon"].asString()+".png");
             // set image url to weather icon returned in json data
        weatherIcon.load(imgURL); //load the image
    }else{
        errorMsg = "Error loading\nWeather Data"; //set error message if data not retrieved.
    }
}
```

The ```getWeatherData``` function opens the ```JSON``` file accessed via the API URL and if successful we can read in the data we want to display in our app. Let's take a look step by step...

&nbsp;
&nbsp;

#### Open the JSON File

```C++
parseSuccess = json.open("http://api.openweathermap.org/data/2.5/"+APICall);
```

Using the ```ofxJSONElement``` object we open the ```JSON``` file returned by the API URL which has the ```APICall``` ```string``` at the end so we can get data from different cities. This call will return either ```true``` or ```false``` dependant on whether the file can be read successfully. Therefore, we can assign this returned value to our ```parseSuccess``` ```bool``` to handle errors via an ```IF``` statement, e.g:

```
if(parseSuccess){
     //data has been received so read
else{
     //set error message
}
```

&nbsp;
&nbsp;

#### Output Data to the Console

```
if(parseSuccess){ //if parseSuccess is true read in data
    cout << json.getRawString(true); //Output json data to console for reference
```

Next we have the start of the ```IF``` statement checking if ```parseSuccess``` is true. The first line in this ```IF``` statement outputs the returned ```JSON``` data to the console. This is useful so we can see what data we can access while building the app.

&nbsp;
&nbsp;

#### Get the Current Date

In the app we want to display the current date to the screen as some text. We can do this by converting the timestamp value returned by the API into a readable string. This is done in our ```getDate()``` function (detailed below). This function takes two parameters the timestamp to convert, followed by an integer which should either be a 1 or 2.

* If 1 is specified the ```getDate()``` function will only return the first 10 characters of the converted timestamp.
* if 2 is specified the ```getDate()``` function will return 6 characters starting at position 10.

The reasons for this will be explained further in the ```getDate()``` function section.

At this point it is worth looking at how we read and access the data returned by the Weather API. Much of this is handled by the ```ofxJSON``` addon, which makes it easy to access and convert the values read in to different data types. But we need to at least understand how we access different parts of the ```JSON``` file.

In the below image we can see the json data that is returned to the console. The timestamp we want is stored in the ```dt``` object of the returned JSON data.

<p align="center">
  <img width="30%" src="https://jakehobbs.co.uk/markdown_images/dt-json.png">
</p>

To access this we use of our ```json``` object and specify the value we want to obtain in square brackets. This is followed by calling the method to specify which data type we want the value returned as (in this case an ```int```).

```C++
json["dt"].asInt()
```

This returns us the timestamp value stored at ```dt``` in the json file (e.g 1543926000)

In our program we want to make the ```date``` ```string``` variable equal to the value returned by the ```getDate``` function. So we call the function and pass in the appropriate parameters.

```C++
date = getDate(json["dt"].asInt(), 1);
```

&nbsp;
&nbsp;

#### Get City

```C++
city = json["name"].asString(); //set city string to city name
```

To get the city from the API we need to access the city name from the ```JSON``` data and store this into our ```city``` ```string``` variable. Notice this time ```.asString``` is called on the json object as this is the type of data we want the value stored as.

<p align="center">
  <img width="30%" src="https://jakehobbs.co.uk/markdown_images/city-json.png">
</p>

&nbsp;
&nbsp;

#### Get Weather Information

```C++
//GET WEATHER INFO
weatherInfo.str(""); //clear string stream
weatherInfo << "Temperature: " << json["main"]["temp"].asString() + "c" << endl; //insert temperature
weatherInfo << "Conditions: " << json["weather"][0]["main"].asString() << endl; //insert conditions
weatherInfo << "Sunrise: " << getDate(json["sys"]["sunrise"].asInt(), 2) << endl; //get sunrise time via getDate function
weatherInfo << "Sunset: " << getDate(json["sys"]["sunset"].asInt(), 2) << endl; //get sunset time via getDate function
```

Next we want to get information about the current weather conditions and insert these into our ```stringstream``` object. We use a ```stringstream``` here as it makes it easy to insert data of different types as well as quickly format the strings onto new lines. Let’s break this section down line by line.

```C++
weatherInfo.str(""); //clear string stream
```

First we clear the ```stringstream``` to remove any contents previously stored inside. This allows us to change the data displayed based on user inputs.

```C++
weatherInfo << "Temperature: " << json["main"]["temp"].asString() + "c" << endl; //insert temperature
```

Now we insert the first line of text into our ```stringstream``` which will be the temperature. We insert the string ```“Temperature: “``` first, then insert the temperature value returned by the ```JSON``` data. Note here we have a pair of square brackets to access the value. This is because the ```temp``` value, is nested alongside other values that also belong to the ```main``` object within the ```JSON``` data (e.g. like rows and columns in a multidimensional array - see image below). So  each piece of data  we add to the ```stringstream``` is  displayed on a new line we insert ```endl``` at the end.

<p align="center">
  <img width="30%" src="https://jakehobbs.co.uk/markdown_images/temp-json.png">
</p>

```C++
weatherInfo << "Conditions: " << json["weather"][0]["main"].asString() << endl; //insert conditions
```

We follow a similar process to get the weather conditions , which is accessed from the  ```weather``` object. Depending on the time of day API the ```weather``` object could return multiple elements (e.g. am & pm if access the city before afternoon) hence the ```[0]``` which states to get the ```main``` value from the first weather element (note the square brackets that wrap the list of weather objects below).

<p align="center">
  <img width="20%" src="https://jakehobbs.co.uk/markdown_images/conditions-json.png">
</p>

If multiple weather blocks were returned each would be wrapped in curly brackets within the square brackets (see the example below). If we wanted to access the PM description we would use:

```C++
json["weather"][1]["main"].asString()      
```

<p align="center">
  <img width="30%" src="https://jakehobbs.co.uk/markdown_images/am-json.png">
</p>

```C++
weatherInfo << "Sunrise: " << getDate(json["sys"]["sunrise"].asInt(), 2) << endl; //get sunrise time weatherInfo << "Sunset: " << getDate(json["sys"]["sunset"].asInt(), 2) << endl; //get sunset time
```

To get sunrise and sunset times we again make use of our ```getDate``` function similar to when we assigned the current date to our date string previously. The ```getDate``` function returns a ```string``` value so we can directly insert this into the ```stringstream```. Notice that when calling ```getDate``` this time we pass the value ```2``` as the second parameter. This is because we want to split the return string differently when getting the sunrise/sunset time versus when we got the current date. This parameter will help us do that.

<p align="center">
  <img width="30%" src="https://jakehobbs.co.uk/markdown_images/sunrise-json.png">
</p>

&nbsp;
&nbsp;

#### Get Background Colour

```C++
getBackground(json["main"]["temp"].asInt()); //call getbackground function to set background colour
```

Now we have all the information we want to display to the screen in our ```stringstream``` we want to call our custom getBackground function to determine what colour the background will be. This ```getBackground()``` function takes an ```int``` parameter which set to the temperature returned by the API (accessed the same as when we inserted the temperature into the ```stringstream``` earlier).

&nbsp;
&nbsp;

#### Load image icon

```C++
imgURL = ofLoadURL("http://openweathermap.org/img/w/"+json["weather"][0]["icon"].asString()+".png"); //set image url to weather icon returned in json data
weatherIcon.load(imgURL); //load the image
```

In our app we want to display an image of the current weather conditions. openWeatherMap provides a set of image icons the name of which is returned in the json data.

<p align="center">
  <img width="30%" src="https://jakehobbs.co.uk/markdown_images/icon-json.png">
</p>

To access this image we use the ```ofHttpResponse``` object to load in the URL of the image icon. We set this dynamically by concatenating the url string with the icon name obtained from the ```JSON``` data. Based on the icon value being returned in the example image above the URL above would become: http://openweathermap.org/img/w/03d.png

If you go to this link you will see this accesses a cloud icon image.

We can now pass this url into our weatherIcon ```ofImage``` object to load ready for drawing.

&nbsp;
&nbsp;

#### Setting Error Message

```C++
}else{
   errorMsg = "Error loading\nWeather Data"; //set error message if data not retrieved.
}
```

In the else part of the ```parseSuccess``` ```IF``` statement we set our ```errorMsg``` ```string``` so we can inform the user of an error on the app screen.

&nbsp;
&nbsp;

### getDate()

```C++
string ofApp::getDate(time_t dateID, int s){
    //Convert timestamp to readable format
    switch(s){
        case 1:
            dateText = ctime(&dateID); //use ctime function from time.h to convert date ID                        
            return dateText.substr(0,10); //return trimmed date
            break;
        case 2:
            dateText = ctime(&dateID); //use ctime function from time.h to convert date ID                       
            return dateText.substr(10,6); //return trimmed date
            break;
    }    
}
```

In the ```getWeatherData()``` function detailed above we are calling the ```getDate()``` function a number of times, but its not yet been defined so we will do that next.
Again we will break this down step by step...

```
string ofApp::getDate(time_t dateID, int s){
```

Our function header specifies the functions return type, it’s name and the parameters it takes. This should match the declaration that is included in the header file. Unlike some other functions in the program whose return type is void this function will return a ```string```, hence ```string``` being used here as the return type. When we call the function in the program we pass in two parameters. These parameters are specified in the parentheses of the function. The first is a timestamp value which gets passed to the ```time_t``` data type (accessed from the time.h header), the second is a number that gets passed to the ```int``` value. The values passed to these parameters are used in the body of the function.

```
switch(s){
    case 1:
```

In the function body we have a switch statement, which evaluates the ```int``` value passed to the ```s``` variable used as a function parameter. This variable allows us to trim the converted date string differently depending on the exact information we wish to display in the program. When we call this function in the ```getWeatherData``` function we pass in either ```1``` or ```2``` to the ```s``` parameter. If ```1``` is specified we return the first part of the converted date ```string```, if ```2``` is specified we return the second part of the converted date ```string```.

```C++
dateText = ctime(&dateID);
```

Inside each case the first line we want to execute converts the timestamp passed to the ```dateID``` parameter to a readable string via the ```ctime()``` function that is part of the time class in C++ (```time.h```). The value returned by ```ctime``` is assigned to ```dateText```.

When we call this function the first time we want to get the current date and the timestamp value we pass in  will look something like: ```1543926000```

The ```ctime``` conversion changes this into a readable format for example if today was 4th December 2020: ```Tue Dec  4 12:20:00 2020```

```C++
return dateText.substr(0,10); //return trimmed date
break;
```

When getting the current date we only want to return the first part of this converted string (up to the time part). So we call the ```substr()``` function on ```dateText``` to trim it. The first value passed to ```substr``` is the starting position, and the second value is how many characters we want (e.g. first 10 characters). Therefore the trimmed string will be: ```Tue Dec  4```. The break statement then ends our first case.

```C++
case 2:
   dateText = ctime(&dateID); //use ctime function from time.h to convert date ID                       
   return dateText.substr(10,6); //return trimmed date
   break;
```

Our second case is similar to the first. The only difference is we trim the ```dateText``` ```string``` differently. This is used when we call ```getDate()``` to get the sunrise and sunset times. In these instances we only want the time aspect of converted string, so we start the ```substr()``` call at position 10 and get the next 6 characters.

If we use the following string as our example (```Tue Dec  4 12:20:00 2018```) then the trimmed string would be: ```12:20```

&nbsp;
&nbsp;

### getBackground()

```C++
void ofApp::getBackground(int temp){
    //modify background gradient colours based on temperature
    if(temp < -5){ //if freezing
        c1.set(167,219,216); //set main colour to blue
    }else if((temp > -6)&&(temp<10)){ //if cold
        c1.set(224,228,204); //set main colour to brown
    }else if((temp > 9)&&(temp<20)){ //if mild
        c1.set(146,204,177); //set main colour to green
    }else if((temp > 19)&&(temp<30)){ //if warm
        c1.set(243,134,48); //set main colour to orange
    }else if(temp > 29){ //if hot
        c1.set(241,46,40); //set main colour to red
    }
}
```

When called this function expects an ```int``` value that gets passed to the ```temp``` parameter. This is used to determine what the background colour will be. This is done by using the ```temp``` value in an if statement that checks the ranges and determines if it is freezing, cold, mild, warm, or hot. The ```c1``` colour object is then set accordingly using ```rgb``` values

* Freezing = blue
* Cold =  brown
* Mild = green
* Warm = orange
* Hot = red

&nbsp;
&nbsp;

### keyPressed()

```C++
void ofApp::keyPressed(int key){
    switch(key){//modify APICall url based on key presses
        //Bath
        case '1':
                 APICall = "weather?id=2656173&units=metric"+APIKey; //set API to retrieve Bath
            getWeatherData(); //call get data function
            break;
        //Timbuktu
        case '2':
            APICall = "weather?id=2449067&units=metric"+APIKey; //set API to retrieve Timbuktu
            getWeatherData(); //call get data function
            break;
        //Rio
        case '3':
            APICall = "weather?id=3451190&units=metric"+APIKey; //set API to retrieve Rio
            getWeatherData(); //call get data function
            break;
        //Prudhoe Bay
        case '4':
            APICall = "weather?id=5872126&units=metric"+APIKey; //set API to retrieve Prudhoe Bay
            getWeatherData(); //call get data function
            break;
        //Madrid
        case '5':
            APICall = "weather?id=6359304&units=metric"+APIKey; //set API to retrieve Madrid
            getWeatherData(); //call get data function
            break;
        default:
            errorMsg = "Invalid Input"; //if incorrect key pressed set errorMsg string
            parseSuccess = false; //set parse boolean to false
    }
}
```

Currently our program just gets in the data for Bath as this is what we set the initial ```APICall``` ```string``` to in the ```setup``` function earlier. We want to allow the user to modify this and pick what city to view based on the menu they see. We will do this via the ```keyPressed``` function where we will evaluate the key that has been pressed in an if statement. If the key matches one of the cases we alter the ```APICall``` and call the ```getWeatherData``` function to get new information in.

Note the main change in each case is the numeric ```ID``` value specified in the ```APICall``` ```string```. This changes the city for the data we want to retrieve. The cities chosen below have been selected due to geographic and temperature spread but feel free to select different ones. A list of all city IDs is available [here](https://jakehobbs.co.uk/markdown_images/city.list.json.gz) (download and unzip the file to access the list). The default case in the switch statement handles incorrect inputs and sets the ```parseSuccess``` boolean to false and sets our ```errorMsg``` ```string``` to an appropriate message. This will allow us to draw the error message to screen on invalid input.

&nbsp;
&nbsp;

### draw()

```C++
//--------------------------------------------------------------
void ofApp::draw(){
    if(parseSuccess){ //check if data has been received

        ofBackgroundGradient(c1, c2, OF_GRADIENT_LINEAR); //draw linear background based on temp        
        //MAIN TEXT
        ofSetColor(50); //set colour to dark grey for the text
        subHeadTXT.drawString(date,(ofGetWidth()/2)-(subHeadTXT.stringWidth(date)/2), 30); //date
        headTXT.drawString(city,(ofGetWidth()/2)-(headTXT.stringWidth(city)/2), 70); //draw city name
        subHeadTXT.drawString("Weather Details", 20, 240); //draw subheading
        mainTXT.drawString(weatherInfo.str(), 20, 270); //output weather info
        menuTXT.drawString(menu, 10, ofGetHeight()-(menuTXT.stringHeight(menu))); //draw menu         
        //DRAWING ICON
        ofSetColor(255); //clear colour
        weatherIcon.draw((ofGetWidth()/2)-50,90, 100, 100); //draw weather icon in middle of screen

        //ADD SEPARATOR
        ofSetColor(50, 50, 50, 100); //set dark grey colour with opacity
        ofSetLineWidth(2.0f); //set line thickness
        ofDrawLine(10, 190, ofGetWidth()-10, 190); //drawline

    }else{ //If data not retrieved draw error screen
        c1.set(255,87,71); //set main color to red
        ofBackgroundGradient(c1, c2, OF_GRADIENT_LINEAR); //set background gradient
        headTXT.drawString(errorMsg,(ofGetWidth()/2)-(headTXT.stringWidth(errorMsg)/2),  (ofGetHeight()/2)-(headTXT.stringHeight(errorMsg)/2)); //draw error message text.
    }
}
```

Our program is almost complete. If you run it now it should successfully read in data and react to the key presses by getting new information in. However currently this will just display to the console as we have not drawn anything to the screen yet. Therefore our final step is to draw all the information we retrieved to the screen. Let’s break the above code down piece by piece...

&nbsp;
&nbsp;

#### Separating the draw function

```
if(parseSuccess){
     //data has been received so draw to screen
else{
     //draw error message
}
```

The first thing we want to do is separate our draw function using the ```parseSuccess``` ```bool```. This will allow us to draw the weather information if it has been correctly received, otherwise we will draw the error message.

&nbsp;
&nbsp;

#### Draw the background

```C++
ofBackgroundGradient(c1, c2, OF_GRADIENT_LINEAR); //draw linear background based on temp of city
```

The first line of code inside the if statement sets the background colour of our app. We do this by passing in the two colour objects (```c1```, ```c2```) that we set previously and then specify the type of gradient we want. This will blend our ```c1``` colour (that changes based on the temperature of the city) to the c2 colour (white) from the top of the screen down.

&nbsp;
&nbsp;

#### Drawing the text

```C++
//MAIN TEXT
ofSetColor(50); //set colour to dark grey for the text
```

Now we want to begin drawing our text to the screen so we can display the weather information. First we set the colour to a dark grey to specify our text colour.

```C++
subHeadTXT.drawString(date,(ofGetWidth()/2)-(subHeadTXT.stringWidth(date)/2), 30);
```

This line draws the value stored in our ```date``` ```string``` with the ```subHeadTXT``` font object. Remember to draw custom fonts we call ```drawString``` on the font object and specify the ```string``` and the ```x``` and ```y``` positions: ```drawString(stringToDraw, xValue, yValue)```

The code above to draw the date might initially look complex, but all it is doing is drawing the text to the centre of the screen by dynamically calculating the ```x``` value...

* The ```x``` value is calculated by dividing the screen width by 2 (```ofGetWidth()/2```), then subtracting half the width of the string we are placing in the centre: (```subHeadTXT.stringWidth(date)/2```)

```C++
headTXT.drawString(city,(ofGetWidth()/2)-(headTXT.stringWidth(city)/2), 70);
```

To draw the city name onto the screen we follow a similar approach to the date. But instead we use our ```headTXT``` font object and ensure we pass in the ```city``` ```string``` and set the ```y``` value to ```70``` so it appears below the date.

```C++
subHeadTXT.drawString("Weather Details", 20, 240);
```

Before we draw the weather information we want to add a subheading. We do this using our ```subHeadTXT``` object and directly specify the ```string``` value and ```x``` and ```y``` parameter values. This will draw the header slightly to the left and half way down our screen.

```C++
mainTXT.drawString(weatherInfo.str(), 20, 270);
```

Now we can draw the weather information. Remember this is stored inside a ```stringstream``` object. To get the value contained in a ```stringstream``` we call the ```.str()``` method. The ```x``` value is set the same as the previous header and then the ```y``` value set to ```270``` so it will appear below the header.

```C++
menuTXT.drawString(menu, 10, ofGetHeight()-(menuTXT.stringHeight(menu)));
```

We want to display our ```menu``` ```string``` at the bottom of the screen. This has been achieved here by getting the screen height: ```ofGetHeight()```, then subtracting the height of the ```menu``` ```string``` to set the ```y``` value in the ```drawString``` call. Note this time we are again using a different font object (```menuTXT```) so that we can display our text using different fonts and sizes. We could simply hard code the ```y``` value (e.g. 450), but setting it dynamically based on screen height means if we decide to change our screen size later and the menu will still be displayed at the bottom.

&nbsp;
&nbsp;

#### Drawing the Weather Icon

```C++
ofSetColor(255); //clear colour
weatherIcon.draw((ofGetWidth()/2)-50,90, 100, 100); //draw weather icon in middle of screen
```

To draw our weather icon to provide a visual of the current conditions we first clear the colour to white. This ensures no tint is applied to images. Then we call draw on our ```weatherIcon``` image object. For image objects the draw call takes the following parameters: ```draw(x, y, width, height)```

We want our image in the middle of the screen so we set the ```x``` value getting the middle point of the screen - (screen width divided by two: ```ofGetWidth() / 2```) then subtracting half the width of our image from this value (50). This ensures the centre point of our image is in the centre of the screen. This is the same principle we applied to our text above. *The reason we set the screen size to 320x480 earlier is due to these image icons which have a low resolution and don't look great much larger than the size used here. If you were to develop this app further you might create your own custom weather icons*

The ```y``` value (90) places the image underneath our date and city text and the width and height values specify we want the image 100x100 pixels.


#### Drawing a line separator

```C++
ofSetColor(50, 50, 50, 100); //set dark grey colour with opacity
ofSetLineWidth(2.0f); //set line thickness
ofDrawLine(10, 190, ofGetWidth()-10, 190); //drawline
```

Just for decoration we are going to add a line that will be drawn between our heading and weather information text. We do this by specifying the line colour, line width and drawing the line via the appropriate openFrameworks methods.

ofDrawLine values are as follows: ```ofDrawLine(startingX, startingY, endingX, endingY);```

&nbsp;
&nbsp;

#### Drawing the error message

```C++
}else{ //If data not retrieved draw error screen
    c1.set(255,87,71); //set main color to red
    ofBackgroundGradient(c1, c2, OF_GRADIENT_LINEAR); //set background gradient
    headTXT.drawString(errorMsg,(ofGetWidth()/2)-(headTXT.stringWidth(errorMsg)/2), (ofGetHeight()/2)-(headTXT.stringHeight(errorMsg)/2)); //draw error message text.
}
```

Our final step is to draw our error message in the ```else``` section of the ```IF``` statement we added to the ```draw``` function. Inside here we first set our ```c1``` colour object to red (red for warning!) and then apply the background on the next line. On the third line we draw our ```errorMsg``` ```string``` to the middle of the screen both horizontally and vertically. We’ve already seen how to do this horizontally on the x-axis previously, and that same principle is applied here. To centre vertically we use the screen and string heights in our calculation.

&nbsp;
&nbsp;

## Full Code

The full source code for this project can be found [here](./Source-Code)
