#include "testApp.h"


//--------------------------------------------------------------

void testApp::setup() {

    //ofSetFrameRate(100);

    camWidth = 720; // try to grab at this size.
    camHeight = 576;

    /* Load video into ofTexture... */
    useTexture = true;

    /* deinterlace types are OF_DV_NO_DEINTERLACE, OF_DV_AVERAGE_DEINTERLACE
    and OF_DV_LINEAR_BLEND_DEINTERLACE (a little slower than average, but a bit more subtle) */
    /* video types are OF_DV_PAL and OF_DV_NTSC */
    dvUtils.initGrabber(useTexture, OF_DV_AVERAGE_DEINTERLACE, OF_DV_PAL);

    /* frame rate calculation for DV cam */
    mytimeThen = 0.0f;
    myframes = 0;

    // *************

    colorImg.allocate(320, 240);
    grayImage.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);

    bLearnBakground = true;
    threshold = 80;

    resizeTemp.allocate(720, 576);
}

//--------------------------------------------------------------

void testApp::update() {
    ofBackground(100, 100, 100);

    dvUtils.grabFrame();
    //printf("wait!\n");

    if (dvUtils.isFrameNew()) {

        mytimeNow = ofGetElapsedTimef();
        if ((mytimeNow - mytimeThen) > 0.05f) {
            myfps = (double) myframes / (mytimeNow - mytimeThen);
            mytimeThen = mytimeNow;
            myframes = 0;
            myframeRate = 0.9f * myframeRate + 0.1f * myfps;
            sprintf(captureFPS, "DV Capture framerate : %f", myframeRate);
        }
        myframes++;

        resizeTemp.setFromPixels(dvUtils.getPixels(), 720, 576);
        colorImg.scaleIntoMe(resizeTemp);
    }

    grayImage = colorImg;
    if (bLearnBakground == true) {
        grayBg = grayImage; // the = sign copys the pixels from grayImage into grayBg (operator overloading)
        bLearnBakground = false;
    }

    // take the abs value of the difference between background and incoming and then threshold:
    grayDiff.absDiff(grayBg, grayImage);
    grayDiff.threshold(threshold);

    // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
    // also, find holes is set to true so we will get interior contours as well....
    contourFinder.findContours(grayDiff, 20, (340 * 240) / 3, 10, true); // find holes
}

//--------------------------------------------------------------

void testApp::draw() {

    // draw the incoming, the grayscale, the bg and the thresholded difference
    ofSetColor(0xffffff);
    //resizeTemp.draw(20,20);
    colorImg.draw(20, 20);
    grayImage.draw(360, 20);
    grayBg.draw(20, 280);
    grayDiff.draw(360, 280);

    // then draw the contours:

    ofFill();
    ofSetColor(0x333333);
    ofRect(360, 540, 320, 240);
    ofSetColor(0xffffff);

    // we could draw the whole contour finder
    // contourFinder.draw(360, 540);

    // or, instead we can draw each blob individually,
    // this is how to get access to them:
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        contourFinder.blobs[i].draw(360, 540);
    }

    // finally, a report:

    ofSetColor(0xffffff);
    char reportStr[1024];
    sprintf(reportStr, "bg subtraction and blob detection\npress ' ' to capture bg\nthreshold %i (press: +/-)\nnum blobs found %i", threshold, contourFinder.nBlobs);
    ofDrawBitmapString(reportStr, 20, 600);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 700, 30);
    ofDrawBitmapString(captureFPS, 700, 42);

    for (int i = 0; i < contourFinder.nBlobs; i++) {
        ofDrawBitmapString("Blob " + ofToString(i) + ": " + ofToString((int) contourFinder.blobs[i].boundingRect.x) + ", " + ofToString((int) contourFinder.blobs[i].boundingRect.y), 700, 54 + (i * 12));
    }
}


//--------------------------------------------------------------

void testApp::keyPressed(int key) {

    switch (key) {
        case ' ':
            bLearnBakground = true;
            break;
        case '+':
            threshold++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold--;
            if (threshold < 0) threshold = 0;
            break;
    }
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

void testApp::windowResized(int w, int h) {

}