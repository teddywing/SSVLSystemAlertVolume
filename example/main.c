#include "./lib/SSVLSystemAlertVolume.h"

int main() {
	OSStatus result;

	Float32 volume;

	result = SSVLGetSystemVolume(&volume);
	if (result != noErr) {
		printf("Error getting system volume: %d\n", result);
		return 1;
	}

	printf("System volume: %f\n", volume);


	Float32 new_volume = 0.5;
	result = SSVLSetSystemVolume(new_volume);
	if (result != noErr) {
		printf("Error setting system volume: %d\n", result);
		return 1;
	}

	printf("Set volume to: %f\n", new_volume);
}
