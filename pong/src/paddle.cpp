#include "paddle.h"
#include "ofGraphics.h"

#include "ofAppRunner.h"

#include "ofTypes.h"

paddle::paddle() {
    x = 50;
    width = 10;
    height = 100;
}

paddle::paddle(int _x) {
    x = _x;
    width = 10;
    height = 100;
}


void paddle::draw() {
    ofDrawBitmapString("vel: " + ofToString(vel),x+10,y+(height/2));
    ofDrawBitmapString(ofToString(y),x+10,y+10);
    ofDrawBitmapString(ofToString(bottom),x+10,bottom);
    ofRect(x,y,width,height);
}

void paddle::update(float mouseY) {
    //printf("%d\n",);
    oldy = y;
    y = mouseY;

    bottom = y + height;
    vel = y - oldy;
}
