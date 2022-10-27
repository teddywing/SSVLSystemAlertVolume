SSVLSystemAlertVolume
=====================

A library to access the system alert volume on Mac OS X. The alert volume is
set relative to the output volume, and is used for beeps and sound effects.

This volume level is commonly set in the System Preferences’ Sound preference
pane. Under the pane’s “Sound Effects” tab, it is controlled using the “Alert
volume” slider.

![Alert volume slider in the Sound preference
pane](./Alert%20volume%20slider.png)


## Use
Include the two files “SSVLSystemAlertVolume.h” and “SSVLSystemAlertVolume.c”
in your project directly, via submodule, or another means.

[See the example](./example/main.c) for an illustration of how to use the
library.


## License
Copyright © 2022 Teddy Wing. Licensed under the Mozilla Public License v. 2.0
(see the included LICENSE file).
