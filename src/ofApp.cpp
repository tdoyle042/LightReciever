#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    serial.listDevices();
    serial.setup(0, 9600);
    reciever.setup(LISTEN_PORT);
    helvetica.loadFont("Helvetica Neue", 14);
}

//--------------------------------------------------------------
void ofApp::update(){
    while (reciever.hasWaitingMessages()) {
        ofxOscMessage m;
        reciever.getNextMessage(&m);
        
        if(m.getAddress() == "/key/released") {
            if (m.getNumArgs() > 0 && m.getArgAsInt64(0) == 'j') {
                cout << "Recieved j!";
                serial.writeByte('j');
            } else if(m.getNumArgs() > 0 && m.getArgAsInt64(0) == 'k') {
                cout << "Recieved k!";
                serial.writeByte('k');
            } else if(m.getNumArgs() > 0 && m.getArgAsInt64(0) == 'l') {
                cout << "Recieved l";
                serial.writeByte('l');
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
