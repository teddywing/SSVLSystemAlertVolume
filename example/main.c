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
