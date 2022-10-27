/*
 * Copyright (c) 2022  Teddy Wing
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

// Version: 0.1.0

#ifndef SSVLSystemAlertVolume_h
#define SSVLSystemAlertVolume_h

#if defined(__cplusplus)
extern "C"
{
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* SSVLSystemAlertVolume_h */
