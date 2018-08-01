/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainWindowComponent  : public Component,
                             public Slider::Listener
{
public:
    //==============================================================================
    MainWindowComponent ();
    ~MainWindowComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setProcessor(QdelayAudioProcessor* processor);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    QdelayAudioProcessor*   m_processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> m_sliderTime;
    std::unique_ptr<Slider> m_sliderDryWet;
    std::unique_ptr<Label> m_timeLabel;
    std::unique_ptr<Label> m_dryWetLabel;
    std::unique_ptr<Slider> m_sliderFeedback;
    std::unique_ptr<Label> m_feedbackLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindowComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
