#include "ofApp.h"
#include "ofxGui.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
    
	// If you want to set any non-default parameters like size, format7, blocking
	// capture, etc., you can do it here before setup. They'll be applied to the
	// camera during setup().
	
	// setup() will pick the first camera. Or if there are multiple cameras you
	// can use the number, or the GUID of the camera.
	camera.setup();
    camera.setExposureAutoOnFlag(false);
    camera.setBrightnessAutoOnFlag(false);
    camera.setGammaAutoOnFlag(false);
    camera.setGainAutoOnFlag(false);
    camera.setShutterAutoOnFlag(false);
    isCameraSettingsAuto = true;
	
    // Setup GUI
	gui.setup(); // most of the time you don't need a name
	gui.add(shutter.setup( "shutter", 0.3, 0, 0.2 ));
	gui.add(exposure.setup( "exposure", 0.8, 0, 1.0 ));
    gui.add(brightness.setup("brightness", 0.5, 0, 1.0));
    gui.add(gamma.setup("gamma", 0.5, 0, 1.0));
    gui.add(gain.setup("gain", 0.5, 0, 0.5));
	gui.add(autoSettings.setup("auto camera settings", false));
	gui.add(autoExposure.setup("exposure", ""));
	gui.add(autoShutter.setup("shutter", ""));
	gui.add(autoBrightness.setup("brightness", ""));
	gui.add(autoGamma.setup("gamma", ""));
	gui.add(autoGain.setup("gain", ""));
    
	gui.loadFromFile("settings.xml");
    
	// After setup it's still possible to change a lot of parameters. If you want
	// to change a pre-setup parameter, the camera will auto-restart
	
	// Set the window size to the camera size.
	//ofSetWindowShape(camera.getWidth(), camera.getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
	// grabVideo() will place the most recent frame into curFrame. If it's a new
	// frame, grabFrame returns true. If there are multiple frames available, it
	// will drop old frames and only give you the newest. This guarantees the
	// lowest latency. If you prefer to not drop frames, set the second argument
	// (dropFrames) to false. By default, capture is non-blocking.
	if(camera.grabVideo(curFrame)) {
		curFrame.update();
	}
    
    if(autoSettings){
        if(isCameraSettingsAuto){
            isCameraSettingsAuto = false;
            camera.setExposureAutoOnFlag(true);
            camera.setBrightnessAutoOnFlag(true);
            camera.setGammaAutoOnFlag(true);
            camera.setGainAutoOnFlag(true);
            camera.setShutterAutoOnFlag(true);
            ofLog(OF_LOG_NOTICE, "olaaaaa " + ofToString(camera.getExposure()));
        }
    }else{
        if(!isCameraSettingsAuto){
            isCameraSettingsAuto = true;
            camera.setExposureAutoOnFlag(false);
            camera.setBrightnessAutoOnFlag(false);
            camera.setGammaAutoOnFlag(false);
            camera.setGainAutoOnFlag(false);
            camera.setShutterAutoOnFlag(false);
            ofLog(OF_LOG_NOTICE, "adios " + ofToString(camera.getExposure()));
        }
        camera.setShutter(shutter);
        camera.setExposure(exposure);
        camera.setBrightness(brightness);
        camera.setGamma(gamma);
        camera.setGain(gain);
        ofLog(OF_LOG_NOTICE, "exposure " + ofToString(camera.getExposure()));
        ofLog(OF_LOG_NOTICE, "gamma " + ofToString(camera.getGamma()));
        ofLog(OF_LOG_NOTICE, "gain " + ofToString(camera.getGain()));
        ofLog(OF_LOG_NOTICE, "brightness " + ofToString(camera.getBrightness()));
        ofLog(OF_LOG_NOTICE, "shutter " + ofToString(camera.getShutter()));
    }
    autoExposure = ofToString(camera.getExposure());
    autoShutter = ofToString(camera.getShutter());
    autoBrightness = ofToString(camera.getBrightness());
    autoGamma = ofToString(camera.getGamma());
    autoGain = ofToString(camera.getGain());
    
}

//--------------------------------------------------------------
void ofApp::draw(){
	// If the camera isn't ready, the curFrame will be empty.
	if(camera.isReady()) {
		// Camera doesn't draw itself, curFrame does.
		curFrame.draw(0, 0);
	}
    
    //GUI
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
