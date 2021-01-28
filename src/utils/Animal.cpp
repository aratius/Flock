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
    legStrength = ofRandom(1) + 1;  //脚力には個体差がある
    size = legStrength * 10;
}

void Animal::update(ofVec2f antiPower) {
    Parent::Update();//親クラスのメソッド実行

    //弧度法
    float direction = atan2(mousePosition.x - position.x, mousePosition.y - position.y);
    float dist = sqrt(pow(mousePosition.x - position.x, 2)+ pow(mousePosition.y - position.y, 2));
    float speed = dist * legStrength / 50; //スピードは距離に比例
    position.x += (sin(direction)) * speed + antiPower.x;
    position.y += (cos(direction)) * speed + antiPower.y;
}

void Animal::draw() {
    Parent::Draw();//親クラスのメソッド実行
    
    ofPushMatrix();
    ofTranslate(position);
    
    ofDrawCircle(0, 0, size);
    
    ofPopMatrix();
}
