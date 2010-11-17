#include "testApp.h"


static int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


//--------------------------------------------------------------
testApp::testApp(){

}

//--------------------------------------------------------------
void testApp::setup(){
ofBackground(255,255,255);
ofSetVerticalSync(true);

Font.loadFont("times.ttf", 220, true, true, true);

text = "Die Omnipräsenz des digitalen Textes nimmt ihm die Besonderheit als Verbreitungsmedium ####";

distance = 350;
distanceOld = 350;
Move = 5;
u = 0;
sum = 0;
z = 0;
}

//--------------------------------------------------------------
void testApp::update(){

ofSetWindowTitle(ofToString(ofGetFrameRate())+" fps");


/*getP = true;
d = 0;



    while(getP) {
        readByte = mySerial.readByte();
        if((readByte != 0) && (d < 10)) {
        buffer[d] = readByte;
        d++;
        }
        if(readByte == 10) {
            getP = false;
            d = 0;
        }
    }

    for(int w = 0;w<10;w++) {
            if(buffer[w] == 13) {
                buffer[w] = 0;
            }
    }


    distanceCollect[skeller] = atoi(buffer);
    skeller++;
    if (skeller == 8) {
        //printf("dCollect: %d %d %d %d %d %d %d %d\n", distanceCollect[0], distanceCollect[1], distanceCollect[2], distanceCollect[3], distanceCollect[4], distanceCollect[5], distanceCollect[6], distanceCollect[7]);
        qsort(distanceCollect,8, sizeof(int), compare);
        skeller = 0;
    }

    distanceOld = distance;
    distance = distanceCollect[0];

    //memcpy(distanceSort, distanceCollect, sizeof(distanceCollect));

    //qsort(distanceSort,4, sizeof(int), compare);




    //distance = distanceSort[0];

    diff = abs((int)(distance - distanceOld));


    if((diff < 350) && (distance != 700)) {
     //printf("%d \n",diff);
     //distance = (distance + distanceOld)/2;

    }
    else {
        distance = distanceOld;

    }*/
    /*
    u++;
    if (u == 5) {
        u = 0;
    }
    /*
    for(int i = 0; i < 5; i++) {
        sum = sum + anton[i];
    }
    distance = sum / 5;
    sum = 0;*/
// distance = atoi(buffer);
/*printf("skeller: %d \n", skeller);
printf("mess: %d \n", atoi(buffer));
printf("dCollect: %d %d %d %d %d %d %d %d\n", distanceCollect[0], distanceCollect[1], distanceCollect[2], distanceCollect[3], distanceCollect[4], distanceCollect[5], distanceCollect[6], distanceCollect[7]);
printf("distSort: %d %d %d %d %d %d %d %d\n", distanceSort[0], distanceSort[1], distanceSort[2], distanceSort[3], distanceSort[4], distanceSort[5], distanceSort[6], distanceSort[7]);*/
//printf("anton   : %d %d %d %d %d \n", anton[0], anton[1], anton[2], anton[3], anton[4]);
//printf("distance: %f\n", distance);


/* this is functional

int values[] = { 40, 10, 100, 90, 20, 25 };

qsort (values, 6, sizeof(int), compare);

for (int n=0; n<6; n++) {
     printf ("%d ",values[n]);
}

printf("\n"); */



/*
if(distance <= 150) {
    distance = 150;
}
if(distance >= 600) {
    distance = 600;
}*/
speed = getValue(minDistance,maxDistance,minSpeed,maxSpeed,distance);
//scale = getValue(minDistance,maxDistance,minScale,maxScale,distance);
scale = getValue(minDistance,maxDistance,0.001,10,distance);
height = getValue(minDistance,maxDistance,minHeight,maxHeight,distance);

speed = 5;
Move = Move - (int)speed;
}

//--------------------------------------------------------------
void testApp::draw(){



//glMatrixMode(GL_PROJECTION);
//Font.drawString(ofToString((int)distance),400,100);
ofPushMatrix();
   //glViewport();
    //ofScale(1,1,100);
//    ofTranslate(100,ofGetHeight()/2+100,scale);
    //glTranslated(0,ofGetHeight()/2+height,scale);
    glTranslated(0,ofGetHeight()/2,0);
    glScalef(scale,scale,1);
    ofSetColor(0, 0, 0);
    ofFill();
    ofRectangle rect;
    ofRectangle rect2;

    Font.drawString(text,Move,0);

    rect = Font.getStringBoundingBox(text,Move,0);

    //if(rect.x <= 0) {
    //glTranslatef(rect.width, 0,0);

    Font.drawString(text,Move-rect.width,0);
    Font.drawString(text,Move+rect.width,0);
    rect2 = Font.getStringBoundingBox(text,Move+rect.width,0);
   // }
    if(rect.x + rect.width <= -1) {
        Move = 0;
    }
ofPopMatrix();
ofSetColor(255, 100, 100);
ofFill();

ofDrawBitmapString("fps     : " + ofToString(ofGetFrameRate(), 2), 15, 20);
ofDrawBitmapString("width   : " + ofToString(ofGetWidth()),15,35);
ofDrawBitmapString("height  : " + ofToString(ofGetHeight()/2-100),15,50);
ofDrawBitmapString("distance: " + ofToString(distance),15,65);
ofDrawBitmapString("rect.x  : " + ofToString(rect.x),15,80);
ofDrawBitmapString("rect2.x : " + ofToString(rect2.x),15,95);
ofDrawBitmapString("Move    : " + ofToString(Move),15,110);
ofDrawBitmapString("sizeFont: " + ofToString(Font.stringHeight("O")),15,125);
//ofDrawBitmapString("widthmatr: " + ofToString(getValue()),15,140);

ofDrawBitmapString("distance: " + ofToString(distance),15,155);

ofDrawBitmapString("speed   : " + ofToString(speed),15,185);
ofDrawBitmapString("scale   : " + ofToString(scale),15,200);

}




//--------------------------------------------------------------
void testApp::keyPressed  (int key){
 if (key == OF_KEY_UP){
  distance -= 5;
 } else if (key == OF_KEY_DOWN){
  distance += 5;
 }
}

//--------------------------------------------------------------
float testApp::getValue(float min, float max, float min2, float max2, float value) {
    gradient = (min2-max2) / (max - min);
    shift = max2 - (gradient * min);

    return (gradient*value) + shift;
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