#pragma once

#include "ofMain.h"
#include "ofxProjectorBlend.h"
#include "ofxSimpleGuiToo.h"

#define PROJECTOR_COUNT 3
#define PROJECTOR_WIDTH 640
#define PROJECTOR_HEIGHT 480
#define PIXEL_OVERLAP 40

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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxProjectorBlend blender;
};
