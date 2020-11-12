#pragma once
#include "ofMain.h"
class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	
	ofImage btnImg; //image object for button appearance
	ofRectangle btn1, btn2; //rectangle object to hold buttons
};
