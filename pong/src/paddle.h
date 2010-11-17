#ifndef _PADDLE_H
#define	_PADDLE_H

#include "ofMain.h"

class paddle : ofPoint{

        public:
            paddle();
            paddle(int _x);
            void draw();
            void update(float mouseY);
            float x;
            float y;
            float width;
            float height;

            float bottom;

            float oldy;
            float vel;
};

#endif

