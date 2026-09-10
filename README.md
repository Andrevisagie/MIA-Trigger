# MIA Trigger

## Stage 1: Cubase-safe foundation

This repository builds a minimal 64-bit Windows VST3 effect:
- separate processor and controller IDs
- separate processor/controller factories
- stereo input/output
- safe audio pass-through
- GitHub Actions Windows x64 build

It deliberately does not yet contain sample playback, waveform rendering, licensing, or the final UI.

## Build without Visual Studio on your PC

1. Create a GitHub repository named `MIA-Trigger`.
2. Upload all files from this folder, preserving folders.
3. Commit to the `main` branch.
4. Open **Actions** in GitHub.
5. Run **Build MIA Trigger VST3**.
6. Open the successful workflow run.
7. Download the artifact `MIA-Trigger-VST3-Windows-x64`.
8. Extract it and locate `MIA Trigger.vst3`.
9. Install the `.vst3` bundle to:
   `C:\Program Files\Common Files\VST3`
10. Restart Cubase and scan plugins.

## Important

Do not copy the VST3 into Cubase 11's old `VSTPlugins` VST2 folder.

This first stage should be validated before adding the drum-trigger engine.

## Planned stages

1. Safe load and audio pass-through
2. Parameters and trigger detector
3. Trigger meter/event feedback
4. WAV sample loading
5. Sample playback
6. Velocity layers and round robin
7. Waveform visualization
8. Polished MIA Trigger UI
9. Presets and MIDI
10. Commercial activation and installer
