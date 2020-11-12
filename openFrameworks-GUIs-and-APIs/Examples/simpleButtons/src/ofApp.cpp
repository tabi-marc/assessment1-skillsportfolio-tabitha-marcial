#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	btnImg.load("button.png");//load in button image
    
	//set position and size for 2 button rectangles
	btn1.set(20, 100, 200, 100);
	btn2.set(250, 100, 200, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::draw(){
    //set color to white - ensures no tint placed on image
	ofSetColor(255);
	//draw img and pass in btn1 rectangle object to set positions
	btnImg.draw(btn1);
    
    //set color to green
	ofSetColor(0,255,0);
	//draw button using drawRectangle and pass in rectangle positions from btn2
	ofDrawRectangle(btn2);
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//check whether mouse press is inside buttons
	if(btn1.inside(x, y)){
		std::cout << "Clicked button 1" << endl;
	}
	if(btn2.inside(x, y)){
		std::cout << "Clicked button 2" << endl;
	}
}
