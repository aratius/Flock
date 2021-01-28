//
//  Parent.hpp
//  Flock
//
//  Created by 松本新 on 2021/01/28.
//

#ifndef Parent_hpp
#define Parent_hpp
#include "ofMain.h"

class Parent {
public:
    void Init();
    void Update();
    void Draw();
    
    ofVec2f mousePosition;
};

#include <stdio.h>

#endif /* Parent_hpp */
