#include <AudioToolbox/AudioToolbox.h>

const AudioServicesPropertyID kAudioServicesPropertySystemAlertVolume = 'ssvl';

OSStatus system_volume_get(Float32 *volume) {
	UInt32 volume_size = sizeof(*volume);

	OSStatus result = AudioServicesGetProperty(
		kAudioServicesPropertySystemAlertVolume,
		0,
		NULL,
		&volume_size,
		volume
	);

	// TODO: Sound PrefPane: If result != noErr, return 0.5?

	if (*volume != 0) {
		*volume = log(*volume) + 1.0;
	}
	else {
		*volume = 0;
	}

	return result;
}

OSStatus system_volume_set(Float32 volume) {
	volume = exp(volume - 1.0);

	return AudioServicesSetProperty(
		kAudioServicesPropertySystemAlertVolume,
		0,
		NULL,
		sizeof(volume),
		&volume
	);
}

int main() {
	OSStatus result;

	Float32 volume;

	result = system_volume_get(&volume);
	if (result != noErr) {
		printf("Error getting system volume: %d\n", result);
		return 1;
	}

	printf("System volume: %f\n", volume);


	Float32 new_volume = 0.5;
	result = system_volume_set(new_volume);
	if (result != noErr) {
		printf("Error setting system volume: %d\n", result);
		return 1;
	}

	printf("Set volume to: %f\n", new_volume);
}
