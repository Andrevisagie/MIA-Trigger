#include "public.sdk/source/vst/vstaudioeffect.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"

namespace Mia {
static const Steinberg::FUID kProcessorUID(0xB2417A91,0x2C3E4D51,0x9F120A77,0xA0311001);
static const Steinberg::FUID kControllerUID(0xC3528B02,0x3D4F5E62,0xAF231B88,0xB1422002);

class Processor final : public Steinberg::Vst::AudioEffect {
public:
  Processor() { setControllerClass(kControllerUID); }

  static Steinberg::FUnknown* createInstance(void*) {
    return static_cast<Steinberg::Vst::IAudioProcessor*>(new Processor());
  }

  Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) override {
    auto result = AudioEffect::initialize(context);
    if (result != Steinberg::kResultOk) return result;
    addAudioInput(STR16("Input"), Steinberg::Vst::SpeakerArr::kStereo);
    addAudioOutput(STR16("Output"), Steinberg::Vst::SpeakerArr::kStereo);
    return Steinberg::kResultOk;
  }

  Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData& data) override {
    if (data.numInputs == 0 || data.numOutputs == 0) return Steinberg::kResultOk;
    auto& inBus = data.inputs[0];
    auto& outBus = data.outputs[0];
    if (!inBus.channelBuffers32 || !outBus.channelBuffers32) return Steinberg::kResultOk;

    const auto channels = (inBus.numChannels < outBus.numChannels) ? inBus.numChannels : outBus.numChannels;
    for (Steinberg::int32 ch = 0; ch < channels; ++ch) {
      auto* in = inBus.channelBuffers32[ch];
      auto* out = outBus.channelBuffers32[ch];
      if (!out) continue;
      if (!in) {
        for (Steinberg::int32 i=0;i<data.numSamples;++i) out[i]=0.f;
        continue;
      }
      for (Steinberg::int32 i=0;i<data.numSamples;++i) out[i]=in[i];
    }
    return Steinberg::kResultOk;
  }

  Steinberg::tresult PLUGIN_API setBusArrangements(
    Steinberg::Vst::SpeakerArrangement* inputs, Steinberg::int32 numIns,
    Steinberg::Vst::SpeakerArrangement* outputs, Steinberg::int32 numOuts) override {
    if (numIns != 1 || numOuts != 1) return Steinberg::kResultFalse;
    return AudioEffect::setBusArrangements(inputs,numIns,outputs,numOuts);
  }
};
} // namespace Mia

namespace Mia {
Steinberg::FUnknown* createProcessor(void*) { return Processor::createInstance(nullptr); }
}
