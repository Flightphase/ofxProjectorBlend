#ifndef _TEST_APP
#define _TEST_APP

/**
 *
 *	testApp.h
 *
 *  ofxProjectorBlend sample project
 *  
 *  Created by James George ( http://www.jamesgeorge.org ) Sep. 20 2010
 *  In collaboration with FlightPhase ( http://www.flightphase.com )
 *
 *  Copyright (c) 2010 
 *
 */

#include "ofMain.h"
#include "ofxProjectorBlend.h"

//let's pretend we are blending 2 projectors 
//side by side, set at a display resolution of 640x480
//with a 40 pixel overlap
#define PIXEL_OVERLAP 40
#define PROJECTOR_COUNT 2
#define PROJECTOR_WIDTH 640
#define PROJECTOR_HEIGHT 480

class testApp : public ofBaseApp{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	ofxProjectorBlend blender;
	
};

#endif
