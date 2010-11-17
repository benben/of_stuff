#ifndef _TEST_APP
#define _TEST_APP
#include "ofMain.h"

static int compare (const void * a, const void * b);

class testApp : public ofBaseApp{

	public:

		testApp();
		void setup();
		void update();
		void draw();

                void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void resized(int w, int h);

        ofSerial mySerial;

        ofRectangle rect;
        ofRectangle rect2;
		char byteReturned;

		int i;
        int distanceCollect[8];
        int distanceSort[8];
        double distance;
        double distanceOld;
        int diff;
        //char buffer[4];
        //bool getBytes;

        char buffer[10];
        char readByte;
        bool getP;
        int d;

        ofTrueTypeFont Font;

        string text;
        string text2;

        int Move;
        int Move2;

        float size;

        float posY;

        float offset;

        float speed;

        float percent;

        float gradient;
        float shift;

        double scale;
        double height;

        int skeller;
        int anton[5];
        int u;
        int sum;
        int z;
        //int compare (const void * a, const void * b);

        //Konstanten für die Projektion Beginn
        static const float minDistance = 150;
        static const float maxDistance = 600;

        static const float minSpeed = 100;
        static const float maxSpeed = 300;

        static const float minScale = -5985;
        static const float maxScale = 597;

        static const float minHeight = 520;
        static const float maxHeight = 55;

        float getValue(float min, float max, float min2, float max2, float value);


};

#endif
