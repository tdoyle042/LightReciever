#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define LISTEN_PORT 9000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    private:
        ofxOscReceiver reciever;
        ofSerial serial;
        ofTrueTypeFont helvetica;
};
