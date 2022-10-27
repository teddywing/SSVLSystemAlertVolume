#ifndef SSVLSystemAlertVolume_h
#define SSVLSystemAlertVolume_h

#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>

// Get the system alert volume.
//
// Sets `volume` to the current system alert volume.
//
// Returns the result of `AudioServicesGetProperty`.
OSStatus SSVLGetSystemVolume(Float32 *volume);

// Set the system alert volume.
//
// The input `volume` must be a float between 0 an 1.
//
// Returns the result of `AudioServicesSetProperty`.
OSStatus SSVLSetSystemVolume(Float32 volume);

#endif /* SSVLSystemAlertVolume_h */
