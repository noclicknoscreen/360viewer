#pragma once

#include "ofMain.h"
#include "ofxOscCam.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void stopChanged(bool & stopChange);
    
    //bool bFill;
//    bool bInfoText;
//    bool bMousePressed;
//    
    ofImage texture;
    ofEasyCam cam;
    
    ofSpherePrimitive sphere;
    
//    ofLight pointLight;
//    ofLight pointLight2;
//    ofLight pointLight3;
    ofMaterial material;
    
//    int mode;
    ofxPanel          panel;
    ofParameterGroup  main;
    ofParameter<bool> drawUI;
    
    ofxPanel panelCam;
    ofxOscParameterSync sync;
    ofParameterGroup pgCam;
    
    ofParameter<bool>   stop;
    ofParameter<bool>   up;
    ofParameter<bool>   down;
    ofParameter<bool>   left;
    ofParameter<bool>   right;
    
    ofParameter<float>  speedX;
    ofParameter<float>  speedY;
    ofParameter<int>  depth;
    
    ofParameter<float>  angleX;
    ofParameter<float>  angleY;
    
};
