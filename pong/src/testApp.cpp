#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    ball1.update();
    paddle1.update(mouseY);

    ball1.bounds();


    //ball1.collision(paddle_x, y,paddle_bottom);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()),20,20);

    ball1.draw();
    paddle1.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

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
void testApp::resized(int w, int h){

}
