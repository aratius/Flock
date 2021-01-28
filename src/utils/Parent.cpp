//
//  Parent.cpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#include "Parent.hpp"

void Parent::Init() {
    cout << "parent init" << endl;
    mousePosition = ofVec2f(ofGetMouseX(), ofGetMouseY());
}

void Parent::Update(){
    cout << "parent update" << endl;
    mousePosition = ofVec2f(ofGetMouseX(), ofGetMouseY());
}

void Parent::Draw() {
    cout << "parent draw" << endl;
}
