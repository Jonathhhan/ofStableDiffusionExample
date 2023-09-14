#pragma once

#include "stableDiffusion/stable-diffusion.h"

class stableDiffusionThread : public ofThread {
public:
	StableDiffusion stableDiffusion;
	std::vector<uint8_t> stableDiffusionPixelVector;
	std::string prompt;
	std::string negativePrompt;
	float cfgScale;
	int width;
	int height;
	SampleMethod sampleMethod;
	int sampleSteps;
	int seed;
	bool diffused;
	void threadedFunction() {
		stableDiffusionPixelVector = stableDiffusion.txt2img(prompt, negativePrompt, cfgScale, width, height, sampleMethod, sampleSteps, seed);
		diffused = true;
	}
};
