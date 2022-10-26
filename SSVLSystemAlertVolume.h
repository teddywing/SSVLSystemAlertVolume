#ifndef SSVLSystemAlertVolume_h
#define SSVLSystemAlertVolume_h

#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>

// TODO: docs
// Float between 0 an 1.
OSStatus SSVLGetSystemVolume(Float32 *volume);

// TODO: docs
OSStatus SSVLSetSystemVolume(Float32 volume);

#endif /* SSVLSystemAlertVolume_h */
