//
//  GameObject.cpp
//  ImageManager
//
//  Created by Marco Gillies on 10/12/2015.
//
//

#include "GameObject.hpp"
#include "ImageManager.hpp"

// the constructor gets the image manager and initialises
// its img member from there
GameObject::GameObject(string imgName, float x, float y)
:img(ImageManager::get().get(imgName)),
position(x,y)
{
    // very common to have empty constructor bodies
}

// we probably don't actually need to define a
// copy constructor because it does the same as the
// automatically generated one
GameObject::GameObject(const GameObject &go)
:img(go.img),position(go.position)
{
    
}

void GameObject::draw() const{
    img.draw(position.x, position.y);
}