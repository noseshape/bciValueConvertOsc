#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(12345);
    sender.setup("localhost",8000);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages

    while(receiver.hasWaitingMessages()){
        // get the next message
//receiver
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        
            // unrecognized message: display on the bottom of the screen
            string msg_string;
            msg_string = m.getAddress();
            msg_string += ": ";
            msg_string += ofToString(m.getNumArgs());
            msg_string += ": \n";
        
            for(int i = 0; i < m.getNumArgs(); i++){
                // get the argument type
                msg_string += "|";
                msg_string += m.getArgTypeName(i);
                msg_string += ":";
                // display the argument - make sure we get the right type
                if(m.getArgType(i) == OFXOSC_TYPE_INT32){
                    msg_string += ofToString(m.getArgAsInt32(i));
                }
                else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                    msg_string += ofToString(m.getArgAsFloat(i));
                }
                else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
                    msg_string += m.getArgAsString(i);
                }
                else{
                    msg_string += "unknown";
                }
            }

//get brain wave (BandPower)
        bw[0]=m.getArgAsInt(0);
        for(int i=1;i<6;i++){
            bw[i] = m.getArgAsFloat(i);
        }
        

// choose 7th wave
        if(m.getArgAsInt(0)==7){
            for(int i=0;i<5;i++){
                bw7[i] = m.getArgAsFloat(i+1);
            }
        }

        
    
    
//sender
    ofxOscMessage n;
    n.setAddress("/bw78");
    for(int i=0;i<5;i++){
        n.addFloatArg(bw7[i]);
    }

    sender.sendMessage(n);





    }


}

//--------------------------------------------------------------
void ofApp::draw(){

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
