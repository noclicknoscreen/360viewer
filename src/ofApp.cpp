#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Basics
    ofSetVerticalSync(true);
    ofBackground(0);
    ofFill();
    
    // Setup texture
    // GL_REPEAT for texture wrap only works with NON-ARB textures //
    ofDisableArbTex();
    texture.load("Porte-Verso-A01.png");
    texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );
    
    // Setup the sphere
    sphere.setRadius(2000);
    sphere.setResolution(64);
    sphere.setPosition(0, 0, 0);
    sphere.rotate(-180, 0, 0, 1);
    sphere.setScale(1, 1, 1);

    // Setup Cam ------------------------------------
    cam.setGlobalPosition(0, 10, 0);
    cam.setTarget(ofVec3f(0, -10, -100));
    
    pgCam.setName("cam");
    
    pgCam.add(stop.set("stop", false));
    pgCam.add(up.set("up", false));
    pgCam.add(down.set("down", false));
    pgCam.add(left.set("left", false));
    pgCam.add(right.set("right", false));
    pgCam.add(speedX.set("speedX", 0, -1, 1));
    pgCam.add(speedY.set("speedY", 0, -1, 1));
    
    pgCam.add(depth.set("depth", 300, 0, 300));
    
    pgCam.add(angleX.set("angleX", 0, -180, 180));
    pgCam.add(angleY.set("angleY", 0, 0, 360));
    
    panelCam.setup(pgCam);
    stop.addListener(this, &ofApp::stopChanged);
    
    // by now needs to pass the gui parameter groups since the panel internally creates it's own group
    sync.setup((ofParameterGroup&)panelCam.getParameter(),8040,"localhost", 8041);
    
    // Setup UI ------------------------------------
    main.setName("main");
    main.add(drawUI.set("drawUI", true));
    
    panel.setup(main);
    panel.loadFromFile("main.xml");
    
    panel.setPosition(10, 10);
    panelCam.setPosition(10, 90);
    
}

//--------------------------------------------------------------
void ofApp::update() {
    // ------------------------------------
    sync.update();

    // -------------------------------------------
    if(up || down){
        if(up && speedX < 1)      speedX += 0.1;
        if(down && speedX > -1)    speedX -= 0.1;
    }else{
        speedX = 0.5*speedX;
        if(abs(speedX) < 0.2)  speedX = 0;
    }
    // -------------------------------------------
    if (left || right) {
        if(right && speedY < 1)    speedY += 0.1;
        if(left && speedY > -1)     speedY -= 0.1;
    }else{
        speedY = 0.5*speedY;
        if(abs(speedY) < 0.2)  speedY = 0;
    }
    
    angleX += speedX;
    if(angleX < 0)   angleX = 0;
    if(angleX > 180)   angleX = 180;
    
    angleY += speedY;
    
    /*
    sphere.tilt(speedX);
    sphere.pan(speedY);
     */
    sphere.setOrientation(ofVec3f(angleX, angleY, -180));
    ofLog() << "Orientation = " << sphere.getOrientationEuler();
    
    cam.setFov(ofMap(depth, 0, 300, 35, 120, true));
    //ofLog() << cam.getFov();
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    // 3D cam stuff --------------------------------------------
    cam.begin();
    ofEnableDepthTest();
    
    // Draw the image on the sphere
    material.begin();
    
    texture.getTexture().bind();
    
    sphere.draw();
    material.end();
    
    ofDisableDepthTest();
    
    cam.end();
    
    // ------------------------------------
    if(drawUI){
        panel.draw();
        panelCam.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        case 'u':
            // Hide UI -----------------------------------------------
            if(drawUI == true){
                drawUI = false;
            }else{
                drawUI = true;
            }
            break;
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

// -------------------------------------------
void ofApp::stopChanged(bool & stopChange){
    stop = up = down = left = right = false;
    angleX = 0;
    angleY = 0;
    //speed = 0;
}

