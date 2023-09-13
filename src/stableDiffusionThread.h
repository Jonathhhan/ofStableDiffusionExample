#pragma once

#include "stableDiffusion/stable-diffusion.h"

class stableDiffusionThread : public ofThread {
public:
	StableDiffusion stableDiffusion;
	ofTexture tex;
	std::vector<uint8_t> stableDiffusionPixelVector;
	std::string prompt;
	bool diffused;
	void threadedFunction() {
		stableDiffusionPixelVector = stableDiffusion.txt2img(prompt, "", 7.0, 128, 128, EULER_A, 16, -1);
		diffused = true;
	}
};
