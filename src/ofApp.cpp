#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(20);
    
    // GL_REPEAT for texture wrap only works with NON-ARB textures //
    ofDisableArbTex();
    //    texture.load("of.png");
    texture.load("Porte-Verso-A01.png");
    texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );
    
    //bFill       = true;
    /*
     bWireframe  = true;
     bDrawNormals= false;
     bDrawAxes   = false;
     bDrawLights = false;
     */
    //    bInfoText   = true;
    //    bMousePressed   = false;
    
    //    float width     = ofGetWidth() * .12;
    //    float height    = ofGetHeight() * .12;
    //
    //
    sphere.setRadius(1000);
    sphere.setResolution(64);
    
    //    mode = 0;
    
    //    ofSetSmoothLighting(true);
    //    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    //    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    //
    //    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    //    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    //
    //    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    //    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess(120);
    // the light highlight of the material //
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    material.setDiffuseColor(ofFloatColor::red);
    material.setAmbientColor(ofFloatColor::blue);
    
    ofSetSphereResolution(24);
    
    // ------------------------------------
    cam.setup();
    
    // ------------------------------------
    main.setName("main");
    main.add(drawUI.set("drawUI", true));
    
    panel.setup(main);
    panel.loadFromFile("main.xml");
    
    panel.setPosition(10, 10);
    
}

//--------------------------------------------------------------
void ofApp::update() {
    //    pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    //    pointLight2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
    //                            ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);
    //
    //    pointLight3.setPosition(
    //                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
    //                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
    //                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
    //                            );
    //
    //    pointLight.setPosition(0, 0, 0);
    //    pointLight2.setPosition(0, 0, 0);
    //    pointLight3.setPosition(0, 0, 0);
    
    // ------------------------------------
    cam.update();
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    cam.begin();
    
    ofEnableDepthTest();
    /*
     ofEnableLighting();
     pointLight.enable();
     pointLight2.enable();
     pointLight3.enable();
     */
    
    // Sphere //
    sphere.setPosition(ofGetWidth()*.0f, ofGetHeight()*.0f, 0);
    sphere.setScale(1, 1, 1);
    //sphere.setPosition(0,0,0);
    //sphere.rotate(spinX, 1.0, 0.0, 0.0);
    //sphere.rotate(spinY, 0, 1.0, 0.0);
    
    //    if(mode == 3) {
    //        sphere.setMode( OF_PRIMITIVE_TRIANGLES );
    //        //triangles = sphere.getMesh().getUniqueFaces();
    //    }
    
    //if(bFill) {
    material.begin();
    
    texture.getTexture().bind();
    
    ofFill();
    
    /*        if(mode == 3) {
     float angle = ofGetElapsedTimef()*3.2;
     float strength = (sin( angle+.25 )) * .5f * 5.f;
     ofVec3f faceNormal;
     for(size_t i = 0; i < triangles.size(); i++ ) {
     // store the face normal here.
     // we change the vertices, which makes the face normal change
     // every time that we call getFaceNormal //
     faceNormal = triangles[i].getFaceNormal();
     for(int j = 0; j < 3; j++ ) {
     triangles[i].setVertex( j, triangles[i].getVertex(j) + faceNormal * strength);
     }
     }
     sphere.getMesh().setFromTriangles( triangles );
     }*/
    sphere.draw();
    material.end();
    //}
    
    //    if(bWireframe) {
    //        ofNoFill();
    //        ofSetColor(0, 0, 0);
    //        sphere.setScale(1.01f);
    //        sphere.drawWireframe();
    //        sphere.setScale(1.f);
    //    }
    //
    //    if(bDrawLights) {
    //        ofFill();
    //        ofSetColor(pointLight.getDiffuseColor());
    //        pointLight.draw();
    //        ofSetColor(pointLight2.getDiffuseColor());
    //        pointLight2.draw();
    //        ofSetColor(pointLight3.getDiffuseColor());
    //        pointLight3.draw();
    //    }
    //
    ofDisableDepthTest();
    
    ofFill();
    
    cam.end();
    
    // ------------------------------------
    if(drawUI){
        panel.draw();x
        cam.panel.draw();
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
            //        case 's':
            //            bFill = !bFill;
            //            break;
            //        case 'w':
            //            bWireframe = !bWireframe;
            //            break;
            //        case '1':
            //            bSplitFaces=false;
            //            sphere.setResolution(4);
            //            // icosahedron //
            //            break;
            //        case '2':
            //            bSplitFaces=false;
            //            sphere.setResolution(8);
            //            break;
            //        case '3':
            //            bSplitFaces=false;
            //            sphere.setResolution(16);
            //            break;
            //        case '4':
            //            bSplitFaces=false;
            //            sphere.setResolution(48);
            //            break;
            //        case 'n':
            //            bDrawNormals = !bDrawNormals;
            //            break;
            //        case OF_KEY_RIGHT:
            //            mode++;
            //            if(mode > 3) mode = 0;
            //            if(mode==3){
            //                // to get unique triangles, you have to use triangles mode //
            //                sphere.setMode( OF_PRIMITIVE_TRIANGLES );
            //            }
            //            break;
            //        case OF_KEY_LEFT:
            //            mode--;
            //            if(mode < 0) mode = 3;
            //            if(mode==3){
            //                // to get unique triangles, you have to use triangles mode //
            //                sphere.setMode( OF_PRIMITIVE_TRIANGLES );
            //            }
            //            break;
            //        case 'a':
            //            bDrawAxes = !bDrawAxes;
            //            break;
            //        case 'l':
            //            bDrawLights = !bDrawLights;
            //            break;
            //        case 't':
            //            bInfoText=!bInfoText;
            //            break;
            ////        case 'z':
            //            bSplitFaces = !bSplitFaces;
            //
            //            if(mode == 3) bSplitFaces = false;
            //
            //            if(bSplitFaces) {
            //                sphere.setMode( OF_PRIMITIVE_TRIANGLES );
            //                vector<ofMeshFace> triangles = sphere.getMesh().getUniqueFaces();
            //                sphere.getMesh().setFromTriangles( triangles, true );
            //            } else {
            //                // vertex normals are calculated with creation, set resolution //
            //                sphere.setResolution( sphere.getResolution() );
            //            }
            //            break;
    }
    //
    //    if(mode == 1) {
    //        sphere.mapTexCoordsFromTexture( texture.getTexture() );
    //    }
    
    //
    //    if( mode == 3 ) {
    //
    //        bSplitFaces = false;
    //
    //        // if the faces were split, we can get some weird results, since we
    //        // might not know what the new strides were,
    //        // so reset the primitives by calling their setMode function
    //        // which recreates the mesh with the proper indicies //
    //        sphere.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    //        sphere.mapTexCoords(0, 0, 5, 5);
    //
    //    }
    
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
    //    bMousePressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //    bMousePressed = false;
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
