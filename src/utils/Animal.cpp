//
//  Animal.cpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#include "Animal.hpp"
#define outside_type "repulsion"

void Animal::init() {
    Parent::Init();  //親クラスのメソッド実行
    
    position = ofVec2f(ofRandom(1) * ofGetWidth(), ofRandom(1) * ofGetHeight());
    speed = ofVec2f(ofRandom(1)-0.5, ofRandom(1)-0.5);
    legStrength = ofRandom(1) + 1;  //脚力には個体差がある
    size = legStrength * 10;
}

void Animal::update(ofVec2f antiPower, ofVec2f gotoCenterPower, ofVec2f directionPower) {
    Parent::Update();//親クラスのメソッド実行

    speed.x += antiPower.x + gotoCenterPower.x/20 + directionPower.x/20;
    speed.y += antiPower.y + gotoCenterPower.y/20 + directionPower.y/20;
    speed.x *= 0.95;
    speed.y *= 0.95;
    
    position.x += speed.x;
    position.y += speed.y;
    
    checkOutSide();
}

void Animal::checkOutSide(){
    if(position.x > ofGetWidth() - size) {
        position.x = ofGetWidth() - size;
        speed.x *= -1;
    }else if(position.x < size){
        position.x = size;
        speed.x *= -1;
    }else if(position.y > ofGetHeight() - size) {
        position.y = ofGetHeight() - size;
        speed.y *= -1;
    }else if(position.y < size) {
        position.y = size;
        speed.y *= -1;
    }
}

void Animal::draw() {
    Parent::Draw();//親クラスのメソッド実行
    
    ofPushMatrix();
    ofTranslate(position);
    
    ofDrawCircle(0, 0, size);
    
    ofPopMatrix();
}
