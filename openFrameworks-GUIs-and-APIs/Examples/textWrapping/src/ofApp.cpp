#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("font.ttf",10, true, true); //load font
    myFont.setLineHeight(20.0f); //set line height of font
    
    string sometext = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.";
    
    text = wrapString(sometext, 300); //get wrapped text from function
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
    myFont.drawString(text, 100, 210); //draw text to screen
}

string ofApp::wrapString(string text, int width) {
    string typeWrapped = "";
    string tempString = "";
    vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in
    
    for(int i=0; i<words.size(); i++) { //run through vector
        string wrd = words[i]; //get current word in vector
        
        // if we aren't on the first word, add a space
        if (i > 0) {
            tempString += " ";
        }
        tempString += wrd; //add current word to temp string
        
        int stringwidth = myFont.stringWidth(tempString); //set string width to length of line
        
        if(stringwidth >= width) {//check string with to add either space or new line before current word
            typeWrapped += "\n"; //if line is now longer than desired width add a new line
            tempString = wrd; // make sure we're including the extra word on the next line
        } else if (i > 0) {
            typeWrapped += " "; // if we aren't on the first word, add a space
        }
        typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
    }
    
    return typeWrapped;
    
}
