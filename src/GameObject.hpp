//
//  GameObject.hpp
//  ImageManager
//
//  Created by Marco Gillies on 10/12/2015.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "ofMain.h"

/* 
 *  This is a simple version of a class
 *  for a game object
 *  a real version would be much more complex 
 *  and use inheritance. In this example I am 
 *  just focusing on how the image is handled
 */
class GameObject {
    // the image is stored as a reference
    // because the actual instance is handled by the image manager
    const ofImage &img;
    // position of the game object
    ofVec2f position;
public:
    // the constructor takes the name of the image
    // and will find it via the image manager
    GameObject(string imgName, float x, float y);
    
    // copy constructor
    GameObject(const GameObject & go);
    
    // draw is const because it does not change the object
    void draw() const;
    
};

#endif /* GameObject_hpp */
