#include "testApp.h"

/**
 *
 *	testApp.cpp
 * 
 *  ofxProjectorBlend sample project
 *  
 *  Created by James George ( http://www.jamesgeorge.org ) Sep. 20 2010
 *  In collaboration with FlightPhase ( http://www.flightphase.com )
 *
 *  Copyright (c) 2010 
 */

//--------------------------------------------------------------
void testApp::setup(){
	blender.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
	blender.gamma = .5;
	blender.blendPower = 1;
	blender.luminance = 0;
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	

	//call blender.begin() to draw onto the blendable canvas
	blender.begin();
	
	//light gray backaground
	ofSetColor(100, 100, 100);
	ofRect(0, 0, blender.getCanvasWidth(), blender.getCanvasHeight());
	
	//thick grid lines for blending
	ofSetColor(255, 255, 255);
	ofSetLineWidth(3);
	
	//vertical line
	for(int i = 0; i <= blender.getCanvasWidth(); i+=40){
		ofLine(i, 0, i, blender.getCanvasHeight());
	}
	
	//horizontal lines
	for(int j = 0; j <= blender.getCanvasHeight(); j+=40){
		ofLine(0, j, blender.getCanvasWidth(), j);		
	}
	
	//instructions
	ofSetColor(255, 255, 255);
	ofRect(10, 10, 300, 100);
	ofSetColor(0, 0, 0);
	ofDrawBitmapString("SPACE - toggle show blend\n[g/G] - adjust gamma\n[p/P] - adjust blend power\n[l/L] adjust luminance", 15, 35);
	
	//call when you are finished drawing
	blender.end();
	
	//this draws to the main window
	blender.draw();
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	//hit spacebar to toggle the blending strip
	if(key == ' '){
		//toggling this variable effects whether the blend strip is shown
		blender.showBlend = !blender.showBlend;
	}
	
	// more info here on what these variables do
	// http://local.wasp.uwa.edu.au/~pbourke/texture_colour/edgeblend/
	
	else if(key == 'g'){
		blender.gamma  -= .05;
		blender.gamma2 -= .05;
	}
	else if(key == 'G'){
		blender.gamma  += .05;
		blender.gamma2 += .05;
	}
	else if(key == 'l'){
		blender.luminance  -= .05;
		blender.luminance2 -= .05;
	}
	else if(key == 'L'){
		blender.luminance  += .05;
		blender.luminance2 += .05;
	}
	else if(key == 'p'){
		blender.blendPower  -= .05;
		blender.blendPower2 -= .05;
	}
	else if(key == 'P'){
		blender.blendPower  += .05;
		blender.blendPower2 += .05;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

