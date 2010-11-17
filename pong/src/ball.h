#ifndef _BALL_H
#define	_BALL_H

#include "ofMain.h"

class ball : ofPoint{

        public:
            ball();
            void draw();
            void update();
            void bounds();
            void collision(int paddle_x,int paddle_top,int paddle_bottom);
            float x;
            float y;
            float r;
            float dx;
            float dy;


};

#endif

