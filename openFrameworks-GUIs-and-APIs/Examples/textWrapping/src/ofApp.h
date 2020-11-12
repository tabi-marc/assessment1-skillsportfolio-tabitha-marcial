#pragma once

#include "ofMain.h"
#include <string>//include string header
#include <vector>//include vector header

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        string wrapString(string text, int width); //string wrapping function
        ofTrueTypeFont myFont; //font object
        string text; //string to hold text once wrapped
};
