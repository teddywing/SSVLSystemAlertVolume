#include <stdlib.h>
#include <sysexits.h>

#include <CoreFoundation/CoreFoundation.h>

#include "./lib/SSVLSystemAlertVolume.h"

int main(int argc, char *argv[]) {
	OSStatus result = noErr;
	Float32 volume;

	// Print the current system alert volume when no arguments are given.
	if (argc == 1) {
		result = SSVLGetSystemVolume(&volume);
		if (result != noErr) {
			printf("error: can't get system volume: %d\n", result);

			return EX_UNAVAILABLE;
		}

		printf("%f\n", volume);

		return EX_OK;
	}

	// Set the system alert volume to the first argument.
	volume = strtof(argv[1], NULL);

	result = SSVLSetSystemVolume(volume);
	if (result != noErr) {
		printf("error: can't set system volume: %d\n", result);

		return EX_UNAVAILABLE;
	}
}
