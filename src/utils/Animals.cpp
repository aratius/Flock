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
        
        //1
        ofVec2f repulsionSum = ofVec2f(0, 0);
        int countRepulsion = 0;
        
        //2. 近い人たちの重心に向かう
        ofVec2f positionSum = ofVec2f(0, 0);
        int countPos = 0;
        
        //3. 近くの人たちの向かう方向の平均にゆく
        ofVec2f speedSum = ofVec2f(0, 0);
        int countSpeed = 0;
        
        Animal animal = animals[i];
        for(int j = 0; j < animal_num; j ++) {
            Animal other = animals[j];
            if(j == i) break;  //自身ならスルー
            
            //1, 2, 3全部で使う
            float dist = sqrt(pow(animal.position.x - other.position.x, 2) + pow(animal.position.y - other.position.y, 2));
            
            //1. 反発 TODO: 現状一つしか検知してないので複数検知して平均を取るようにしなければ
            float threshold_repulsion = 100;  //反発力が発生するときの閾値
            if(dist < threshold_repulsion) {  //dist N 以下で逆方向のイカらをかける
                float direction = atan2(animal.position.x - other.position.x, animal.position.y - other.position.y);
                float power = (threshold_repulsion - dist) / threshold_repulsion;  //1~0 dist0で最大値1を取る
                ofVec2f antiPower = ofVec2f(sin(direction)*power, cos(direction)*power);
                repulsionSum.x += antiPower.x;
                repulsionSum.y += antiPower.y;
                countRepulsion ++;
            }
            
            //2. 近い人たちの重心に向かう
            float threshold_center_of_gravity = 1000;
            if(dist < threshold_center_of_gravity) {
                positionSum.x += other.position.x;
                positionSum.y += other.position.y;
                countPos ++;
            }
            
            //3. 近くの人たちの向かう方向の平均にゆく
            float threshold_direction = 1000;
            if(dist < threshold_direction) {
                speedSum.x += other.speed.x;
                speedSum.y += other.speed.y;
                countSpeed ++;
            }

        }
        //1. 反発
        ofVec2f repulsionAverage = ofVec2f(repulsionSum.x/countRepulsion, repulsionSum.y /countRepulsion);
        if(!(repulsionAverage.x > -1 && repulsionAverage.y < 1)) {
            repulsionAverage = ofVec2f(0, 0);
        }
        
        //2. 近い人たちの重心に向かう
        ofVec2f positionAverage = ofVec2f(positionSum.x/countPos, positionSum.y/countPos);  //重心座標
        ofVec2f goToCenterPower = ofVec2f(0, 0);
        if(countPos != 0) {
            float direction = atan2(animal.position.x - positionAverage.x, animal.position.y - positionAverage.y);
            goToCenterPower = ofVec2f(-sin(direction), -cos(direction));

        }
        
        //3. 近くの人たちの向かう方向の平均にゆく
        ofVec2f speedAverage = ofVec2f(speedSum.x/countSpeed, speedSum.y/countSpeed);  //スピードの平均値
        float directionAverage = atan2(speedAverage.x, speedAverage.y);
        ofVec2f directionPower = ofVec2f(sin(directionAverage), cos(directionAverage));
        //有効値でないなら
        if(!(directionPower.x > -1 && directionPower.x < 1)) {
            directionPower = ofVec2f(0, 0);
        }
        
        animals[i].update(repulsionAverage, goToCenterPower, directionPower);
    }
}

void Animals::draw() {
    for(int i = 0; i < animal_num; i ++) {
        animals[i].draw();
    }
}
