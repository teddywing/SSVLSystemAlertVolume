#ifndef SSVLSystemAlertVolume_h
#define SSVLSystemAlertVolume_h

#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>

OSStatus SSVLGetSystemVolume(Float32 *volume);
OSStatus SSVLSetSystemVolume(Float32 volume);

#endif /* SSVLSystemAlertVolume_h */
