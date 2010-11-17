#include "ball.h"
#include "ofGraphics.h"

#include "ofAppRunner.h"

#include "ofTypes.h"

ball::ball() {
    x = 200;
    y = 200;
    r = 20;
    dx = -3;
    dy = -3;
}

void ball::draw() {

    ofDrawBitmapString(ofToString(x-r),x+20,y-10);
    ofDrawBitmapString(ofToString(y+r),x+20,y+r);

    ofFill();
    ofSetColor(0xFF0000);
    ofCircle(x,y,r);
    ofSetColor(0xffffff);
}

void ball::update() {
    //printf("%d\n",);

    x = x + dx;
    y = y + dy;
}

void ball::bounds() {
    if(x+r >= ofGetWidth() || x-r < 0) {
        dx = dx * -1;
    }

    if(y+r > ofGetHeight() || y-r < 0) {
        dy = dy * -1;
    }
}

void ball::collision(int paddle_x,int paddle_top,int paddle_bottom) {
    if(x-r-10 <= paddle_x && y-r >= paddle_top  && y+r <= paddle_bottom) {
        dx = dx * -1;
        printf("collision!\n");
        printf("ball x bound was: %f\n",x-r);
        printf("paddle x bound was: %f\n",paddle_x);
    }
}
