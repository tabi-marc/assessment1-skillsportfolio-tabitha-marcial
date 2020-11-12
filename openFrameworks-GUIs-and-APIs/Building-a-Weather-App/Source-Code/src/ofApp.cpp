#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //load in fonts
    headTXT.load("header.ttf", 30); //main header font
    subHeadTXT.load("header.ttf", 16); //sub header font
    mainTXT.load("font.ttf", 11); //font used for the main text
    menuTXT.load("font.ttf", 8); //font used for the menu text

    //set second gradient color to white
    c2.set(255, 255, 255);

    //menu string
    menu = "1 - Bath  |  2 - Timbuktu  |  3 - Rio De Janiero\n4 - Prudhoe Bay  |  5 - Madrid";

    //Set API Key from OpenWeatherMap
    APIKey = "&APPID=REPLACEWITHYOURKEY";
    //Set initial weather call to Bath
    APICall = "weather?id=2656173&units=metric"+APIKey;

    //Call weather function to retrieve data
    getWeatherData();
}

//--------------------------------------------------------------
void ofApp::update(){
    //Don't need to update anything on each frame so nothing happening here
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(parseSuccess){ //check if data has been received

        ofBackgroundGradient(c1, c2, OF_GRADIENT_LINEAR); //draw linear background based on temp of city

        //MAIN TEXT
        ofSetColor(50); //set colour to dark grey for the text
        subHeadTXT.drawString(date,(ofGetWidth()/2)-(subHeadTXT.stringWidth(date)/2), 30); //draw current date to screen, text should appear in middle by dividing screen width by 2 and subtracting width of text also divided by 2
        headTXT.drawString(city,(ofGetWidth()/2)-(headTXT.stringWidth(city)/2), 70); //draw city name to screen again should appear in the middle
        subHeadTXT.drawString("Weather Details", 20, 240); //draw subheading
        mainTXT.drawString(weatherInfo.str(), 20, 270); //output weather info stored in string stream
        menuTXT.drawString(menu, 10, 450); //draw menu at bottom of screen

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
        headTXT.drawString(errorMsg,(ofGetWidth()/2)-(headTXT.stringWidth(errorMsg)/2), (ofGetHeight()/2)-(headTXT.stringHeight(errorMsg)/2)); //draw error message text.
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //modify APICall url based on key presses
    switch(key){
            //Bath
        case '1':
            APICall = "weather?id=2656173&units=metric"+APIKey; //set API to retrieve Bath Data
            getWeatherData(); //call get data function
            break;
            //Timbuktu
        case '2':
            APICall = "weather?id=2449067&units=metric"+APIKey; //set API to retrieve Timbuktu Data
            getWeatherData(); //call get data function
            break;
            //Rio
        case '3':
            APICall = "weather?id=3451190&units=metric"+APIKey; //set API to retrieve Rio Data
            getWeatherData(); //call get data function
            break;
            //Prudhoe Bay
        case '4':
            APICall = "weather?id=5872126&units=metric"+APIKey; //set API to retrieve Prudhoe Bay Data
            getWeatherData(); //call get data function
            break;
            //Madrid
        case '5':
            APICall = "weather?id=6359304&units=metric"+APIKey; //set API to retrieve Madrid Data
            getWeatherData(); //call get data function
            break;
        default:
            errorMsg = "Invalid Input"; //if incorrect key pressed set errorMsg string
            parseSuccess = false; //set parse boolean to false
    }
}
//--------------------------------------------------------------
void ofApp::getWeatherData(){

    parseSuccess = json.open("http://api.openweathermap.org/data/2.5/"+APICall); //get the json data and check if successful

    if(parseSuccess){ //if parseSuccess is true read in data

        cout << json.getRawString(true); //Output json data to console for reference, remove in final version

        date = getDate(json["dt"].asInt(), 1); //make date string equal to value returned by getDate function
        city = json["name"].asString(); //set city string to city name
        //cout << json["dt"].asInt();
        // cout << date << endl;
        //GET WEATHER INFO
        weatherInfo.str(""); //clear string stream
        weatherInfo << "Temperature: " << json["main"]["temp"].asString() + "c" << endl; //insert temperature
        weatherInfo << "Conditions: " << json["weather"][0]["main"].asString() << endl; //insert conditions
        weatherInfo << "Sunrise: " << getDate(json["sys"]["sunrise"].asInt(), 2) << endl; //get sunrise time via getDate function
        weatherInfo << "Sunset: " << getDate(json["sys"]["sunset"].asInt(), 2) << endl; //get sunset time via getDate function

        //GET TEMPERATURE
        getBackground(json["main"]["temp"].asInt()); //call getbackground function to set background colour - pass in temperature as parameter

        //GET IMAGE ICON
        imgURL = ofLoadURL("http://openweathermap.org/img/w/"+json["weather"][0]["icon"].asString()+".png"); //set image url to weather icon returned in json data
        weatherIcon.load(imgURL); //load the image
    }else{
        errorMsg = "Error loading\nWeather Data"; //set error message if data not retrieved.
    }
}
//--------------------------------------------------------------
string ofApp::getDate(time_t dateID, int s){
    //Convert timestamp to readable format
    switch(s){
        case 1:
            dateText = ctime(&dateID); //use ctime function from time.h to convert date ID to readable format
            cout << dateText;
            return dateText.substr(0,10); //trim dateText to desired characters (first 10 characters)
            break;
        case 2:
            dateText = ctime(&dateID); //use ctime function from time.h to convert date ID to readable format
            return dateText.substr(10,6); //trim dateText to desired characters (6 characters starting at 10th character)
            break;
    }

}
//--------------------------------------------------------------
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
