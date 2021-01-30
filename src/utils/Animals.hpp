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

#define animal_num 10

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
