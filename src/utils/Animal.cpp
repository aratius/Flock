//
//  Animal.cpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#include "Animal.hpp"

void Animal::init() {
    Parent::Init();  //親クラスのメソッド実行
    
    position = ofVec2f(ofRandom(1) * ofGetWidth(), ofRandom(1) * ofGetHeight());
    speed = ofVec2f(ofRandom(1)-0.5, ofRandom(1)-0.5);
    legStrength = ofRandom(1) + 1;  //脚力には個体差がある
    size = legStrength * 10;
}

void Animal::update(ofVec2f antiPower) {
    Parent::Update();//親クラスのメソッド実行

    speed.x += antiPower.x/100;
    speed.y += antiPower.y/100;
    
    position.x += speed.x;
    position.y += speed.y;
}

void Animal::draw() {
    Parent::Draw();//親クラスのメソッド実行
    
    ofPushMatrix();
    ofTranslate(position);
    
    ofDrawCircle(0, 0, size);
    
    ofPopMatrix();
}
