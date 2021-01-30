//
//  Animal.hpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#ifndef Animal_hpp
#define Animal_hpp
#include "ofMain.h"
#include "Parent.hpp"

class Animal : public Parent {
public:
    void init();
    void update(ofVec2f antiPower, ofVec2f gotoCenterPower, ofVec2f directionPower);
    void draw();
    
    ofVec2f position;
    ofVec2f speed;
    float legStrength;
    float size;
};
#include <stdio.h>

#endif /* Animal_hpp */
