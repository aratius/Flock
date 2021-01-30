#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    animals.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    animals.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    animals.draw();
    
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
