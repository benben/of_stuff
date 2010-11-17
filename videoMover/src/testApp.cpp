#include "testApp.h"

//--------------------------------------------------------------

void testApp::setup() {
    ofLogLevel(OF_LOG_VERBOSE);

    //dirty little path hack is needed for netbeans :(
    //ofSetDataPathRoot("bin/data/");
    
    ofSetFrameRate(25);
    ofBackground(0, 0, 0);
    ofSetColor(0xFFFFFF);
    videoCount = 0;
}
//--------------------------------------------------------------

void testApp::update() {

    for (int i = 0; i < videoCount; i++) {
        videoArray[i].update();
    }
}

//--------------------------------------------------------------

void testApp::draw() {

    for (int i = 0; i < videoCount; i++) {
        videoArray[i].proc();
    }
    ofDrawBitmapString("FPS   : " + ofToString(ofGetFrameRate()), 10, 10);
    ofDrawBitmapString("Videos: " + ofToString(videoCount), 10, 22);

}
//--------------------------------------------------------------

void testApp::keyPressed(int key) {
    switch (key) {
        case '+':
            if (videoCount < NUM) {
                videoArray[videoCount].loadMovie("movies/test320x240.avi");
                videoArray[videoCount].setLoopState(3);
                videoArray[videoCount].play();
                videoArray[videoCount].proc_ini(ofRandomWidth(), ofRandomHeight(), ofRandomWidth(), ofRandomHeight());
                videoCount++;
            }
            break;
        case '-':
            if (videoCount > 0) {
                //videoArray[videoCount];
                videoCount--;
            }
            break;
    }
}

//--------------------------------------------------------------

void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------

void testApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------

void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------

void testApp::mousePressed(int x, int y, int button) {

}


//--------------------------------------------------------------

void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------

void testApp::resized(int w, int h) {

}