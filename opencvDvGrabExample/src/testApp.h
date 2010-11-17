#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofDVUtils.h"

class testApp : public ofBaseApp {
public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);


    ofVideoPlayer vidPlayer;


    ofxCvColorImage colorImg;

    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;

    ofxCvContourFinder contourFinder;

    int threshold;
    bool bLearnBakground;

    ofxCvColorImage resizeTemp;

    //stuff for dvGrabber

    int camWidth;
    int camHeight;
    ofDVUtils dvUtils;

private:
    char captureFPS[255];
    float mytimeNow, mytimeThen, myframeRate;
    double myfps;
    int myframes;

    bool useTexture;

};

#endif