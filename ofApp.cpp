#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(300);

	ofColor color;
	auto noise_seed = ofRandom(1000);
	for (int deg = 0; deg < 360; deg += 6) {

		color.setHsb(ofMap(deg, 0, 360, 0, 255), 200, 255);
		ofSetColor(color);

		ofPushMatrix();
		ofRotate(deg);
		ofTranslate(glm::vec2(0, 250));
		
		auto location = glm::vec2(cos(deg * DEG_TO_RAD), sin(deg * DEG_TO_RAD));
		auto rotate_deg = ofMap(ofNoise(noise_seed, location.x * 0.08, location.y * 0.08, ofGetFrameNum() * 0.01), 0, 1, -360, 360);
		ofRotateX(rotate_deg);

		ofDrawLine(glm::vec2(0, 0), glm::vec2(0, -50));
		ofDrawLine(glm::vec2(0, 0), glm::vec2(0, 50));

		ofDrawSphere(glm::vec3(0, -70, 0), 3);
		ofDrawSphere(glm::vec3(0, 70, 0), 3);

		ofPopMatrix();
	}

	noise_seed = ofRandom(1000);
	for (int deg = 3; deg < 360; deg += 6) {

		color.setHsb((int)ofMap(deg, 0, 360, 128, 255 + 128) % 255, 200, 255);
		ofSetColor(color);

		ofPushMatrix();
		ofRotate(deg);
		ofTranslate(glm::vec2(0, 250));

		auto location = glm::vec2(cos(deg * DEG_TO_RAD), sin(deg * DEG_TO_RAD));
		auto rotate_deg = ofMap(ofNoise(noise_seed, location.x * 0.08, location.y * 0.08, ofGetFrameNum() * 0.01), 0, 1, -360, 360);
		ofRotateX(rotate_deg);

		ofDrawLine(glm::vec2(0, 0), glm::vec2(0, -25));
		ofDrawLine(glm::vec2(0, 0), glm::vec2(0, 25));

		ofDrawSphere(glm::vec3(0, -35, 0), 3);
		ofDrawSphere(glm::vec3(0, 35, 0), 3);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 300;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}