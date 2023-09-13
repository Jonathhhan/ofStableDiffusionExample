#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	printf("%s", sd_get_system_info().c_str());
	set_sd_log_level(INFO);
	thread.stableDiffusion.load_from_file("data/models/stable-diffusion-nano-2-1-ggml-model-f16.bin");
	texture.allocate(128, 128, GL_RGB);
	texture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	prompt = "a lovely cat";
}

//--------------------------------------------------------------
void ofApp::update(){
	if (thread.diffused == true){
		texture.loadData(&thread.stableDiffusionPixelVector[0], 128, 128, GL_RGB);
		ofPixels pixels;
		texture.readToPixels(pixels);
		ofSaveImage(pixels, "output/image_of_" + prompt + "_" + ofGetTimestampString("%Y-%m-%d-%H-%M-%S") + ".png");
		thread.diffused = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	texture.draw(20, 20, 512, 512);
	ofDrawBitmapString("Type something and press enter to generate an image.", 40, 550);
	ofDrawBitmapString("Prompt: " + prompt, 40, 570);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
		if (!thread.isThreadRunning()){
			thread.prompt = prompt;
			thread.startThread();
		}
	}
	else {
		if (key == 8 && prompt.size() > 0) {
			prompt = prompt.substr(0, prompt.size() - 1);
		}
		else if (key == 127) {
			prompt  = "";
		}
		else if (prompt.size() < 50) {
			prompt.append(1, (char)key);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//------------- -------------------------------------------------
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
