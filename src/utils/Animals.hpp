//
//  Animals.hpp
//  Flock
//
//  Created by 松本新 on 2021/01/27.
//

#ifndef Animals_hpp
#define Animals_hpp
#include "ofMain.h"
#include "Parent.hpp"
#include "Animal.hpp"

#define animal_num 100
#define THRESHOLD_1 50  //同士の反発力が発生する閾値
#define THRESHOLD_2 200  //近所の重心に向かうその近所判定の閾値
#define THRESHOLD_3 200  //近所の同じ方向に進むその近所判定の閾値

class Animals : public Parent {
  
public:
    void init();
    void update();
    void draw();
    
    Animal animals[animal_num];

private:
    
};

#include <stdio.h>

#endif /* Animals_hpp */
