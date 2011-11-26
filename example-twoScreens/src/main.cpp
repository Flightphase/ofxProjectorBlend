/**
 *
 *	main.cpp
 *
 *  ofxProjectorBlend sample project
 *  
 *  Created by James George ( http://www.jamesgeorge.org ) Sep. 20 2010
 *  In collaboration with FlightPhase ( http://www.flightphase.com )
 *
 *  Copyright (c) 2010 
 */

#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	//these variablsa re defined in testApp.h and are used to set
	//the size of the canvas will be the resolution of two projectors side by side minus the overlap between them
	ofSetupOpenGL(&window, PROJECTOR_WIDTH*2-PIXEL_OVERLAP, PROJECTOR_HEIGHT, OF_WINDOW);
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
