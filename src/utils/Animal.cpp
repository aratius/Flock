//
//  Animal.cpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#include "Animal.hpp"

void Animal::init() {
    Parent::Init();  //親クラスのメソッド実行
    
    position = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
}

void Animal::update() {
    Parent::Update();//親クラスのメソッド実行
    
    //弧度法
    float direction = atan2(mousePosition.x - position.x, mousePosition.y - position.y);
    float dist = sqrt(pow(mousePosition.x - position.x, 2)+ pow(mousePosition.y - position.y, 2));
    float speed = dist/30; //スピードは距離に比例
    position.x += sin(direction) * speed;
    position.y += cos(direction) * speed;
}

void Animal::draw() {
    Parent::Draw();//親クラスのメソッド実行
    
    ofPushMatrix();
    ofTranslate(position);
    
    ofDrawCircle(0, 0, 50);
    
    ofPopMatrix();
}
