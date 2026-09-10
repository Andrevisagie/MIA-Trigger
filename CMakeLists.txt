cmake_minimum_required(VERSION 3.22)
project(MIATrigger VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  vst3sdk
  GIT_REPOSITORY https://github.com/steinbergmedia/vst3sdk.git
  GIT_TAG v3.8.0
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(vst3sdk)

set(SMTG_ADD_VST3_PLUGINS_SAMPLES OFF CACHE BOOL "" FORCE)
set(SMTG_ADD_VST3_HOSTING_SAMPLES OFF CACHE BOOL "" FORCE)

smtg_add_vst3plugin(MIA_Trigger
  src/processor.cpp
  src/controller.cpp
  src/entry.cpp
)

target_compile_features(MIA_Trigger PRIVATE cxx_std_17)

if(MSVC)
  target_compile_options(MIA_Trigger PRIVATE /EHsc /W4)
endif()
