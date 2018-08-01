/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
QdelayAudioProcessor::QdelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    m_readPos = 0;
    m_writePos = 0;
    addParameter(m_delayTime = new AudioParameterFloat(
        "time",
        "Time",
        0.0f,
        10.0f,
        1.0f));
    addParameter(m_dryWet = new AudioParameterFloat(
        "dryWet",
        "DryWet",
        0.0f,
        1.0f,
        0.25f));
    addParameter(m_feedback= new AudioParameterFloat(
        "feedback",
        "Feedback",
        0.0f,
        1.0f,
        0.25f));
    m_delayBufferLength = 1;
}

QdelayAudioProcessor::~QdelayAudioProcessor()
{
}

//==============================================================================
const String QdelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool QdelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool QdelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool QdelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double QdelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int QdelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int QdelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void QdelayAudioProcessor::setCurrentProgram (int index)
{
}

const String QdelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void QdelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void QdelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    m_delayBufferLength = (int) 2.0 * sampleRate;
    if (m_delayBufferLength < 1)
    {
        m_delayBufferLength = 1;
    }
    m_delayBuf.setSize(2, m_delayBufferLength);
    m_delayBuf.clear();
 
    m_readPos = (int)(m_writePos - (*m_delayTime * getSampleRate()) + m_delayBufferLength) % m_delayBufferLength;
}

void QdelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool QdelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void QdelayAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    int rPos, wPos;
    float out;

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        float* delayData = m_delayBuf.getWritePointer(jmin(channel, m_delayBuf.getNumChannels() - 1));

        // ..do something to the data...
        rPos = m_readPos;
        wPos = m_writePos;
        for (int i = 0; i < buffer.getNumSamples(); i++)
        {
            out = ((1 - *m_dryWet) * channelData[i]) + (*m_dryWet * delayData[rPos]);
            delayData[wPos] = channelData[i] + (*m_feedback * delayData[rPos]);

            if (++rPos >= m_delayBufferLength)
            {
                rPos = 0;
            }
            if (++wPos >= m_delayBufferLength)
            {
                wPos = 0;
            }
            channelData[i] = out;
        }
    }
    m_readPos = rPos;
    m_writePos = wPos;
}

//==============================================================================
bool QdelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* QdelayAudioProcessor::createEditor()
{
    return new QdelayAudioProcessorEditor (*this);
}

//==============================================================================
void QdelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void QdelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void QdelayAudioProcessor::setDelayTime(float newTime)
{
    *m_delayTime = newTime;
    m_readPos = (int)(m_writePos - (*m_delayTime * getSampleRate()) + m_delayBufferLength) % m_delayBufferLength;
}

void QdelayAudioProcessor::setDryWet(int newDryWet)
{
    *m_dryWet = (float)newDryWet / (float)100;
}

void QdelayAudioProcessor::setFeedback(int newFeedback)
{
    *m_feedback = (float)newFeedback / (float)100;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new QdelayAudioProcessor();
}
