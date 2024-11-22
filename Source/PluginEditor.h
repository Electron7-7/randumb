#pragma once

/*#define RAND_STEP_ONES 0
#define RAND_STEP_TENTHS 1
#define RAND_STEP_HUNDREDTHS 2
#define RAND_STEP_THOUSANDTHS 3*/

#include <JuceHeader.h>
#include "PluginProcessor.h"

class RandumbAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
	RandumbAudioProcessorEditor (RandumbAudioProcessor&);
	~RandumbAudioProcessorEditor() override;

	void paint (juce::Graphics&) override;
	void resized() override;

private:
	// This reference is provided as a quick way for your editor to access the processor object that created it
	RandumbAudioProcessor& audioProcessor;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RandumbAudioProcessorEditor)

	void setRandomSeed(int seed = 177013);

	// float generateRandomNumber(long seed = 4815162342, float range_end = 0.0f, float range_start = 0.0f, int granularity = RAND_STEP_ONES);
	float generateRandomNumber();
};
