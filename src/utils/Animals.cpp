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
        ofVec2f goToCenterPower = ofVec2f(0, 0);
        Animal animal = animals[i];
        for(int j = 0; j < animal_num; j ++) {
            Animal other = animals[j];
            if(j == i) break;  //自身ならスルー
            
            float dist = sqrt(pow(animal.position.x - other.position.x, 2) + pow(animal.position.y - other.position.y, 2));
            
            //1. 反発 TODO: 現状一つしか検知してないので複数検知して平均を取るようにしなければ
            float threshold_repulsion = 50;  //反発力が発生するときの閾値
            if(dist < threshold_repulsion) {  //dist N 以下で逆方向のイカらをかける
                float direction = atan2(animal.position.x - other.position.x, animal.position.y - other.position.y);
                float power = (threshold_repulsion - dist) / threshold_repulsion;  //1~0 dist0で最大値1を取る
                antiPower = ofVec2f(sin(direction)*power, cos(direction)*power);
            }
            
            //2. 近い人たちの重心に向かう
            float threshold_center_of_gravity = 700;
            ofVec2f positionSum = ofVec2f(0, 0);
            int count = 0;
            if(dist < threshold_center_of_gravity) {
                positionSum.x += other.position.x;
                positionSum.y += other.position.y;
                count ++;
            }
            ofVec2f positionAverage = ofVec2f(positionSum.x/count, positionSum.y/count);  //重心座標
            
            if(count != 0) {
                float direction = atan2(animal.position.x - positionAverage.x, animal.position.y - positionAverage.y);
                float power = 1;
                goToCenterPower = ofVec2f(-sin(direction)*power, -cos(direction)*power);
                cout << goToCenterPower.x << endl;
                
            }
            
            //3. 近くの人たちの向かう方向の平均にゆく
            
        }
        
        animals[i].update(antiPower, goToCenterPower);
    }
}

void Animals::draw() {
    for(int i = 0; i < animal_num; i ++) {
        animals[i].draw();
    }
}
