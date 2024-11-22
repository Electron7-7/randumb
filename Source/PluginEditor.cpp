#include "PluginProcessor.h"
#include <cstdlib>
#include "PluginEditor.h"

RandumbAudioProcessorEditor::RandumbAudioProcessorEditor (RandumbAudioProcessor& p): AudioProcessorEditor (&p), audioProcessor (p)
{
	setTitle("Randumb Generator");
	setSize(400, 300); // Set the editor's size before the constructor has finished
}

RandumbAudioProcessorEditor::~RandumbAudioProcessorEditor()
{
	// Reminder: destructors like this are for cleanup and deallocation (probably gonna be important for optimization)
}

void RandumbAudioProcessorEditor::paint (juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

	g.setColour (juce::Colours::white);
	g.setFont (15.0f);
	g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void RandumbAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any subcomponents in your editor.
}

void RandumbAudioProcessorEditor::setRandomSeed(int seed)
{
	srand(seed);
}

float RandumbAudioProcessorEditor::generateRandomNumber()
{
	return static_cast<float>(rand() % 1001) / 1000.0f;
}