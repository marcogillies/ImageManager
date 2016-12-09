#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

void ofApp::exit(){
    ImageManager::deleteMangager();
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw all of the objects
    // get them as const pointers
    // to avoid copying but ensure
    // that they aren't changed
    for(const auto &obj : objects){
        obj.draw();
    }
}

/*
 * loads a new level
 */
void ofApp::loadLevel(string levelName){
    
    // clear all of the object
    // and the image manager
    // (deletes all of the pointers)
    objects.clear();
    ImageManager::get().reset();
    
    // get all of the .png images in the
    // directory
    ofDirectory dir(ofToDataPath( levelName));
    //only show png files
    dir.allowExt("png");
    //populate the directory object
    dir.listDir();
    
    //go through and add each image to the image manager
    for(int i = 0; i < dir.size(); i++){
        ImageManager::get().add(dir.getPath(i));
    }
    
    // load a level definition file (very simple format)
    std::ifstream levelFile(ofToDataPath( levelName ) + "/" + levelName + ".tsv");
    string name;
    float x, y;
    // load image name and position from the file
    // and use them to create a new object
    while(levelFile >> name >> x >> y){
        objects.push_back(GameObject(name, x, y));
    }
};

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        loadLevel("level1");
    }
    
    if(key == '2'){
        loadLevel("level2");
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
