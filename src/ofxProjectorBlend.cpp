#include "ofxProjectorBlend.h"
#include "ofxProjectorBlendShader.h"


// --------------------------------------------------
ofxProjectorBlend::ofxProjectorBlend()
{
	showBlend = true;
	gamma = gamma2 = 0.5;
	blendPower = blendPower2 = 1;
	luminance = luminance2 = 0;
	numProjectors = 0;
	threshold = 0;
}


// --------------------------------------------------
void ofxProjectorBlend::setup(int resolutionWidth, 
							  int resolutionHeight, 
							  int _numProjectors, 
							  int _pixelOverlap, 
							  ofxProjectorBlendLayout _layout, 
							  ofxProjectorBlendRotation _rotation)
{
	string l = "horizontal";
	if(layout==ofxProjectorBlend_Vertical) l = "vertical";
	
	string r = "normal";
	if(rotation==ofxProjectorBlend_RotatedLeft) r = "rotated left";
	else if(rotation==ofxProjectorBlend_RotatedRight) r = "rotated right";
	
	ofLog(OF_LOG_NOTICE, "ofxProjectorBlend: res: %d x %d * %d, overlap: %d pixels, layout: %s, rotation: %s\n", resolutionWidth, resolutionHeight, _numProjectors, _pixelOverlap, l.c_str(), r.c_str());
	numProjectors = _numProjectors;
	layout = _layout;
	rotation = _rotation;
	
	if(numProjectors <= 0){
		ofLog(OF_LOG_ERROR, "Cannot initialize with " + ofToString(this->numProjectors) + " projectors.");
		return;
	}
	
	//allow editing projector heights
	for(int i = 0; i < numProjectors; i++){
		projectorHeightOffset.push_back( 0 );
	}
	
	pixelOverlap = _pixelOverlap;
	
	if(rotation == ofxProjectorBlend_NoRotation) {
		singleChannelWidth = resolutionWidth;
		singleChannelHeight = resolutionHeight;
	}
	else {
		singleChannelWidth = resolutionHeight;
		singleChannelHeight = resolutionWidth;
	}
	
	if(layout == ofxProjectorBlend_Vertical) {
		fullTextureWidth = singleChannelWidth;
		fullTextureHeight = singleChannelHeight*numProjectors - pixelOverlap*(numProjectors-1);
	}
	else if(layout == ofxProjectorBlend_Horizontal) {
		fullTextureWidth = singleChannelWidth*numProjectors - pixelOverlap*(numProjectors-1);
		fullTextureHeight = singleChannelHeight;
	} else {
		ofLog(OF_LOG_ERROR, "ofxProjectorBlend: You have used an invalid ofxProjectorBlendLayout in ofxProjectorBlend::setup()");
		return;
	}
	
	
	displayWidth = resolutionWidth*numProjectors;
	displayHeight = resolutionHeight;
	
	fullTexture.allocate(fullTextureWidth, fullTextureHeight, GL_RGB, 4);
    
    
    blendShader.unload();
    blendShader.setupShaderFromSource(GL_FRAGMENT_SHADER, ofxProjectorBlendFragShader);
    blendShader.setupShaderFromSource(GL_VERTEX_SHADER, ofxProjectorBlendVertShader);
    blendShader.linkProgram();
}


// --------------------------------------------------
void ofxProjectorBlend::begin() {
	
	fullTexture.begin();
	
	ofPushStyle();
	ofClear(0,0,0,0);
}


// --------------------------------------------------
float ofxProjectorBlend::getDisplayWidth() {
	return displayWidth;
}


// --------------------------------------------------
float ofxProjectorBlend::getDisplayHeight() {
	return displayHeight;
}


// --------------------------------------------------
void ofxProjectorBlend::moveDisplayVertical(unsigned int targetDisplay, int yOffset)
{
	if(targetDisplay >= numProjectors){
		ofLog(OF_LOG_ERROR, "targetDisplay (" + ofToString(targetDisplay) + ") is invalid.");
		return;
	}
	
	projectorHeightOffset[targetDisplay] += yOffset;
}


// --------------------------------------------------
// This changes your app's window size to the correct output size
void ofxProjectorBlend::setWindowToDisplaySize()
{
	ofSetWindowShape(getDisplayWidth(), getDisplayHeight());
}


// --------------------------------------------------
float ofxProjectorBlend::getCanvasWidth()
{
	return fullTextureWidth;
}


// --------------------------------------------------
float ofxProjectorBlend::getCanvasHeight()
{
	return fullTextureHeight;
}



// --------------------------------------------------
void ofxProjectorBlend::end()
{
	fullTexture.end();
	ofPopStyle();
}


// --------------------------------------------------
void ofxProjectorBlend::updateShaderUniforms()
{
	
	blendShader.setUniform1f("OverlapTop", 0.0f);
	blendShader.setUniform1f("OverlapLeft", 0.0f);
	blendShader.setUniform1f("OverlapBottom", 0.0f);
	blendShader.setUniform1f("OverlapRight", 0.0f);
	
	blendShader.setUniform1f("BlendPower", blendPower);
	blendShader.setUniform1f("SomeLuminanceControl", luminance);
	blendShader.setUniform3f("GammaCorrection", gamma, gamma, gamma);
	
	blendShader.setUniform1f("BlendPower2", blendPower2);
	blendShader.setUniform1f("SomeLuminanceControl2", luminance2);
	blendShader.setUniform3f("GammaCorrection2", gamma2, gamma2, gamma2);
	
	blendShader.setUniform1f("projectors", this->numProjectors);
	blendShader.setUniform1f("threshold", threshold);
}

void ofxProjectorBlend::draw(float x, float y) {
	ofSetHexColor(0xFFFFFF);
	glPushMatrix();
	glTranslatef(x, y, 0);
	if(showBlend) {
		blendShader.begin();
		blendShader.setUniform1f("width", singleChannelWidth);
		blendShader.setUniform1f("height", singleChannelHeight);
		
		updateShaderUniforms();
		
		if(layout == ofxProjectorBlend_Horizontal) {
			blendShader.setUniform1f("OverlapRight", pixelOverlap);	
		}
		else {
			blendShader.setUniform1f("OverlapTop", pixelOverlap);
		}
		
		blendShader.setUniformTexture("Tex0", fullTexture.getTextureReference(), 0);
		
		
		ofVec2f offset(0,0);
		glPushMatrix();
		
		// loop through each projector and glTranslatef() to its position and draw.
		for(int i = 0; i < numProjectors; i++) {
			blendShader.setUniform2f("texCoordOffset", offset.x, offset.y);
			
			if(i==1) {
				// set the first edge
				if(layout == ofxProjectorBlend_Horizontal) {
					blendShader.setUniform1f("OverlapLeft", pixelOverlap);	
				}
				else {
					blendShader.setUniform1f("OverlapBottom", pixelOverlap);
				}
				
			}
			// if we're at the end of the list of projectors, turn off the second edge's blend
			
			if(i+1 == numProjectors) {
				if(layout == ofxProjectorBlend_Horizontal) {
					blendShader.setUniform1f("OverlapRight", 0);	
				}
				else {
					blendShader.setUniform1f("OverlapTop", 0);
				}
			}
			
			glPushMatrix(); {
				if(rotation == ofxProjectorBlend_RotatedRight) {
					glRotatef(90, 0, 0, 1);
					glTranslatef(0, -singleChannelHeight, 0);
				}
				else if(rotation == ofxProjectorBlend_RotatedLeft) {
					glRotatef(-90, 0, 0, 1);
					glTranslatef(-singleChannelWidth, 0, 0);
				}
				
				glTranslatef(0, (float)projectorHeightOffset[i], 0);
				
				glBegin(GL_QUADS);
				
				glTexCoord2f(0, 0);
				glVertex2f(0, 0);
				
				glTexCoord2f(singleChannelWidth, 0);
				glVertex2f(singleChannelWidth, 0);
				
				glTexCoord2f(singleChannelWidth, singleChannelHeight);
				glVertex2f(singleChannelWidth, singleChannelHeight);
				
				glTexCoord2f(0, singleChannelHeight);
				glVertex2f(0, singleChannelHeight);
				
				glEnd();
			}
			glPopMatrix();
			
			// move the texture offset and where we're drawing to.
			if(layout == ofxProjectorBlend_Horizontal) {
				offset.x += singleChannelWidth - pixelOverlap;
			}
			else {
				offset.y += singleChannelHeight - pixelOverlap;
				
			}
			
			if(rotation == ofxProjectorBlend_RotatedLeft || rotation == ofxProjectorBlend_RotatedRight) {
				glTranslatef(singleChannelHeight, 0, 0);
			}
			else {
				glTranslatef(singleChannelWidth, 0, 0);
			}
			
		}
		glPopMatrix();
	
		blendShader.end();
	} else {
		fullTexture.draw(x, y);
	}
	glPopMatrix();
}


