//
//  Animals.cpp
//  Flock
//
//  Created by 松本新 on 2021/01/27.
//

#include "Animals.hpp"

void Animals::init() {
    for(int i = 0; i < animal_num; i ++) {
        animals[i].init();
    }
}

void Animals::update() {
    for(int i = 0; i < animal_num; i ++) {
        
        ofVec2f antiPower = ofVec2f(0, 0);  //反発方向の力（オフセット）
        Animal animal = animals[i];
        for(int j = 0; j < animal_num; j ++) {
            Animal other = animals[j];
            if(j == i) break;  //自身ならスルー
            float dist = sqrt(pow(animal.position.x - other.position.x, 2) + pow(animal.position.y - other.position.y, 2));
            if(dist < 400) {  //dist N 以下で逆方向の力をかける
                float direction = atan2(animal.position.x - other.position.x, animal.position.y - other.position.y);
                antiPower = ofVec2f(-sin(direction), -cos(direction));
            }
        }
        
        animals[i].update(antiPower);
    }
}

void Animals::draw() {
    for(int i = 0; i < animal_num; i ++) {
        animals[i].draw();
    }
}
