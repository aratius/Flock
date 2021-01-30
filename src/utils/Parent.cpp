//
//  Parent.cpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#include "Parent.hpp"

void Parent::Init() {
    
    mousePosition = ofVec2f(ofGetMouseX(), ofGetMouseY());
}

void Parent::Update(){
    
    mousePosition = ofVec2f(ofGetMouseX(), ofGetMouseY());
}

void Parent::Draw() {
    
}
