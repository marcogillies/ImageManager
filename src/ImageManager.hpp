//
//  ImageManager.hpp
//  ImageManager
//
//  Created by Marco Gillies on 10/12/2015.
//
//

#ifndef ImageManager_hpp
#define ImageManager_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "ofMain.h"


/* 
 *  This class is a central place to store all images used in 
 *  the game so you only have to load them into memory once.
 */
class ImageManager {
    // the images are stored in a map so you can
    // index them by name rather than a number
    // each image is stored as a shared pointer
    // because they will be shared across many
    // images
    std::map<string, shared_ptr<ofImage> > images;
    
    // this is the singleton instance of the image
    // manager
    // it is stored as a unique_ptr because there is
    // only one object and it is not shared between
    // different objects (though they access is temporarily
    // through get).
    static unique_ptr<ImageManager> theImageManager;
    
    // the constructor is private so that it can only
    // be created via the static functions below
    ImageManager();
public:
    
    // get hold of the manager
    // returns a refernece. It is safe
    // to return a reference to an object stored
    // as a unique_ptr because a refernece cannot be deleted,
    // so we are sure that the pointer can only be deleted
    // through the unique_ptr (there is a danger
    // that the unique_ptr might delete the ImageManager
    // while a reference is still using it. In this case it
    // won't happen because the ImageManager will last for the entire
    // program, but in general you should not store the reference
    // returned by a function like this in anything but a local variable)
    static ImageManager & get();
    
    ~ImageManager();
    
    // reset the manager (deletes all images)
    void reset();
    
    // loads an image from file and loads it
    void add(string filename);
    
    // gets an image by name
    const shared_ptr<ofImage> get(string name) const {
        return images.at(name);
    };
    
};

#endif /* ImageManager_hpp */
