#include "public.sdk/source/main/pluginfactory.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivsteditcontroller.h"

namespace Mia {
class Processor;
class Controller;
static const Steinberg::FUID kProcessorUID(0xB2417A91,0x2C3E4D51,0x9F120A77,0xA0311001);
static const Steinberg::FUID kControllerUID(0xC3528B02,0x3D4F5E62,0xAF231B88,0xB1422002);
}

// Factories are implemented in the respective translation units.
namespace Mia {
Steinberg::FUnknown* createProcessor(void*);
Steinberg::FUnknown* createController(void*);
}

BEGIN_FACTORY_DEF("MIA Audio", "https://github.com", "support@mia-audio.example")

DEF_CLASS2(
  INLINE_UID_FROM_FUID(Mia::kProcessorUID),
  PClassInfo::kManyInstances,
  kVstAudioEffectClass,
  "MIA Trigger",
  Vst::kDistributable,
  "Fx|Dynamics",
  "0.1.0",
  kVstVersionString,
  Mia::createProcessor)

DEF_CLASS2(
  INLINE_UID_FROM_FUID(Mia::kControllerUID),
  PClassInfo::kManyInstances,
  kVstComponentControllerClass,
  "MIA Trigger Controller",
  0,
  "",
  "0.1.0",
  kVstVersionString,
  Mia::createController)

END_FACTORY
