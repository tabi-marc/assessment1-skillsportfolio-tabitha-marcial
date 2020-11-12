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
