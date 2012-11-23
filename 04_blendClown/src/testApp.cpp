#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    blender.setup(PROJECTOR_WIDTH, PROJECTOR_HEIGHT, PROJECTOR_COUNT, PIXEL_OVERLAP);
    blender.setWindowToDisplaySize();
    
    cout << "canvas size: " << blender.getCanvasWidth() << " x " << blender.getCanvasHeight() << endl;
    cout << "display size: " << blender.getDisplayWidth() << " x " << blender.getDisplayHeight() << endl;
    
    blendClown.loadImage("blendClown.png");
    bDrawClown = false;
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
        
        if(bDrawClown) {
            blendClown.draw(0, 0);
        }
        
        //instructions
        ofSetColor(255, 255, 255);
        ofRect(10, 10, 300, 100);
        ofSetColor(0, 0, 0);
        stringstream instructions;
        instructions << "SPACE - toggle show blend" << endl;
        instructions << "[g/G] - adjust gamma" << endl;
        instructions << "[p/P] - adjust blend power" << endl;
        instructions << "[l/L] - adjust luminance" << endl;
        instructions << "[c] - show/hide blend clown" << endl;
        ofDrawBitmapString(instructions.str(), 15, 35);
        
	}
	blender.end(); //call when you are finished drawing
	
    
	//this draws to the main window
	blender.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	//hit spacebar to toggle the blending strip
	if(key == ' '){
		//toggling this variable effects whether the blend strip is shown
		blender.showBlend = !blender.showBlend;
	}
	
	// more info here on what these variables do
	// http://local.wasp.uwa.edu.au/~pbourke/texture_colour/edgeblend/
	
	else if(key == 'g'){
		blender.gamma[0]  -= .05;
		blender.gamma[1] -= .05;
	}
	else if(key == 'G'){
		blender.gamma[0]  += .05;
		blender.gamma[1] += .05;
	}
	else if(key == 'l'){
		blender.luminance[0]  -= .05;
		blender.luminance[1] -= .05;
	}
	else if(key == 'L'){
		blender.luminance[0]  += .05;
		blender.luminance[1] += .05;
	}
	else if(key == 'p'){
		blender.blendPower[0]  -= .05;
		blender.blendPower[1] -= .05;
	}
	else if(key == 'P'){
		blender.blendPower[0]  += .05;
		blender.blendPower[1] += .05;
	}else if (key=='c') {
        bDrawClown = !bDrawClown;
    }
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