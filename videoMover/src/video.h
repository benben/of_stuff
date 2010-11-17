#ifndef VIDEO_H
#define VIDEO_H

#include "ofMain.h"

class video : public ofVideoPlayer
{
    public:
        void    draw(float x, float y);
        void 	draw(float x, float y, float w, float h);
        void    proc_ini(float _startX, float _startY,float _endX, float _endY);
        void    proc();
        float x;
        float y;
        float startX;
        float startY;
        float endX;
        float endY;
        float steps;
        float stepX;
        float stepY;
        float stepcount;
    protected:
    private:
};

#endif // VIDEO_H
