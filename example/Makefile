PRODUCT := sysalertvol

all: $(PRODUCT)

$(PRODUCT): main.c lib/*
	$(CC) \
		-framework AudioToolbox \
		-framework CoreFoundation \
		-o $@ \
		main.c lib/SSVLSystemAlertVolume.c
