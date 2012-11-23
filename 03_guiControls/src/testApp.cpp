#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    blender.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
	blender.setWindowToDisplaySize();
    blender.gamma = .5;
	blender.blendPower = 1;
	blender.luminance = 0;
    
	gui.addToggle("Show Blend", blender.showBlend);
	gui.addSlider("Blend Power", blender.blendPower, 0.0, 4.0);
	gui.addSlider("Gamma", blender.gamma, 0.1, 4.0);
	gui.addSlider("Luminance", blender.luminance, 0.0, 4.0);
	gui.addSlider("Blend Power 2", blender.blendPower2, 0.0, 4.0);
	gui.addSlider("Gamma 2", blender.gamma2, 0.1, 4.0);
	gui.addSlider("Luminance 2", blender.luminance2, 0.0, 4.0);
    
    gui.loadFromXML();
    gui.show();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	blender.begin(); //call blender.begin() to draw onto the blendable canvas
    {
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
	}
	blender.end(); //call when you are finished drawing
	
    
	//this draws to the main window
	blender.draw();
    
    
    // We might not want the GUI to be blended...
    gui.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key=='g' || key=='G')
        gui.toggleDraw();
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}