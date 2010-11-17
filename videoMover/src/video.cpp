#include "video.h"
void video::draw(float _x, float _y){
	draw(_x, _y, (float)width, (float)height);
}
void video::draw(float _x, float _y, float _w, float _h){
	if (bUseTexture){
		tex.draw(_x, _y, _w, _h);
	}
	x = _x;
	y = _y;
}
void video::proc_ini(float _startX, float _startY,float _endX, float _endY) {
    startX = _startX;
    startY = _startY;
    endX = _endX;
    endY = _endY;
    //vector
    steps = (sqrt( (endX - startX)*(endX - startX) + (endY - startY)*(endY - startY) ));
    steps = steps / 5;
    stepcount = 0;

    x = startX;
    y = startY;

    stepX = ((endX - startX)/steps);
    stepY = ((endY - startY)/steps);
}

void video::proc() {
    x = x + stepX;
    y = y + stepY;
    ++stepcount;
    if(stepcount >= steps) {
        proc_ini(x,y,ofRandomWidth(),ofRandomHeight());
    }
    draw(x,y);
    ofLine(startX,startY,endX,endY);
}
