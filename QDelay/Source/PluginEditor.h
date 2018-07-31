/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "MainWindowComponent.h"

//==============================================================================
/**
*/
class QdelayAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    QdelayAudioProcessorEditor (QdelayAudioProcessor&);
    ~QdelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    QdelayAudioProcessor& processor;
    MainWindowComponent mainWindowComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QdelayAudioProcessorEditor)
};
