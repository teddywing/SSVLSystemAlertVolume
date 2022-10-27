/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "SSVLSystemAlertVolume.h"

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
