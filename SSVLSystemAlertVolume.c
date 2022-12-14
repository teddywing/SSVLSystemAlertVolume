/*
 * Copyright (c) 2022  Teddy Wing
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

// Version: 0.1.0

#include "SSVLSystemAlertVolume.h"

// This property appears to be private, as it isn't defined in Apple's MacOSX
// SDK framework headers.
//
// The value comes from the Sound preference pane. Disassembling the
// `/System/Library/PreferencePanes/Sound.prefPane/Contents/MacOS/Sound` binary
// shows that functions accessing the system alert volume do so via the
// '0x7373766c' property. Converting that to a FourCharCode yields 'ssvl'.
const AudioServicesPropertyID SSVLAudioServicesPropertySystemAlertVolume = 'ssvl';

OSStatus SSVLGetSystemVolume(Float32 *volume) {
	UInt32 volume_size = sizeof(*volume);

	OSStatus result = AudioServicesGetProperty(
		SSVLAudioServicesPropertySystemAlertVolume,
		0,
		NULL,
		&volume_size,
		volume
	);

	if (*volume != 0) {
		*volume = log(*volume) + 1.0;
	}
	else {
		*volume = 0;
	}

	return result;
}

OSStatus SSVLSetSystemVolume(Float32 volume) {
	volume = exp(volume - 1.0);

	return AudioServicesSetProperty(
		SSVLAudioServicesPropertySystemAlertVolume,
		0,
		NULL,
		sizeof(volume),
		&volume
	);
}
