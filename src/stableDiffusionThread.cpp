#include "stableDiffusionThread.h"

void stableDiffusionThread::threadedFunction() {
	stableDiffusionPixelVector = stableDiffusion.txt2img(prompt, negativePrompt, cfgScale, width, height, sampleMethod, sampleSteps, seed);
	diffused = true;
}