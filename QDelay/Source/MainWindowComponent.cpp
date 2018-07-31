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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainWindowComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainWindowComponent::MainWindowComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_sliderTime.reset (new Slider ("sliderTime"));
    addAndMakeVisible (m_sliderTime.get());
    m_sliderTime->setRange (0, 10, 0.5);
    m_sliderTime->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_sliderTime->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    m_sliderTime->addListener (this);

    m_sliderTime->setBounds (16, 104, 80, 80);

    m_sliderDryWet.reset (new Slider ("sliderDryWet"));
    addAndMakeVisible (m_sliderDryWet.get());
    m_sliderDryWet->setRange (0, 100, 1);
    m_sliderDryWet->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_sliderDryWet->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    m_sliderDryWet->addListener (this);

    m_sliderDryWet->setBounds (112, 104, 80, 80);

    m_timeLabel.reset (new Label ("time label",
                                  TRANS("Delay Time (s)")));
    addAndMakeVisible (m_timeLabel.get());
    m_timeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.070f));
    m_timeLabel->setJustificationType (Justification::centredTop);
    m_timeLabel->setEditable (false, false, false);
    m_timeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    m_timeLabel->setBounds (8, 80, 100, 24);

    m_dryWetLabel.reset (new Label ("dry/wet label",
                                    TRANS("Dry/Wet")));
    addAndMakeVisible (m_dryWetLabel.get());
    m_dryWetLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.070f));
    m_dryWetLabel->setJustificationType (Justification::centredTop);
    m_dryWetLabel->setEditable (false, false, false);
    m_dryWetLabel->setColour (TextEditor::textColourId, Colours::black);
    m_dryWetLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    m_dryWetLabel->setBounds (104, 80, 100, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainWindowComponent::~MainWindowComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_sliderTime = nullptr;
    m_sliderDryWet = nullptr;
    m_timeLabel = nullptr;
    m_dryWetLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

void MainWindowComponent::setProcessor(QdelayAudioProcessor* processor)
{
    m_processor = processor;
}

//==============================================================================
void MainWindowComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff505050));

    {
        float x = 0.0f, y = 0.0f, width = 200.0f, height = 200.0f;
        Colour fillColour = Colour (0x7a51ff87);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        int x = 25, y = 13, width = 164, height = 44;
        String text (TRANS("QDelay"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Perpetua Titling MT", 27.30f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainWindowComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainWindowComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_sliderTime.get())
    {
        //[UserSliderCode_m_sliderTime] -- add your slider handling code here..
        m_processor->setDelayTime(sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_sliderTime]
    }
    else if (sliderThatWasMoved == m_sliderDryWet.get())
    {
        //[UserSliderCode_m_sliderDryWet] -- add your slider handling code here..
        m_processor->setDryWet(sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_sliderDryWet]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainWindowComponent" componentName=""
                 parentClasses="public Component" constructorParams="QdelayAudioProcessor processor"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="200" initialHeight="200">
  <BACKGROUND backgroundColour="ff505050">
    <ROUNDRECT pos="0 0 200 200" cornerSize="10.00000000000000000000" fill="solid: 7a51ff87"
               hasStroke="0"/>
    <TEXT pos="25 13 164 44" fill="solid: ffffffff" hasStroke="0" text="QDelay"
          fontname="Perpetua Titling MT" fontsize="27.30000000000000071054"
          kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="sliderTime" id="80dcb766e086455f" memberName="m_sliderTime"
          virtualName="" explicitFocusOrder="0" pos="16 104 80 80" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.50000000000000000000" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="sliderDryWet" id="6e5f6de45dc4121f" memberName="m_sliderDryWet"
          virtualName="" explicitFocusOrder="0" pos="112 104 80 80" min="0.00000000000000000000"
          max="100.00000000000000000000" int="1.00000000000000000000" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="time label" id="be0e3319791096ee" memberName="m_timeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 80 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay Time (s)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="-0.07000000000000000666"
         bold="0" italic="0" justification="12"/>
  <LABEL name="dry/wet label" id="8f1ed327b7e0ec4" memberName="m_dryWetLabel"
         virtualName="" explicitFocusOrder="0" pos="104 80 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry/Wet" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="-0.07000000000000000666" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
