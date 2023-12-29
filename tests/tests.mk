ifndef BUILD_DIR
	BUILD_DIR=build
endif
ifndef BOOT_DISK
	BOOT_DISK = floppy-1.img
endif


$(BUILD_DIR)/$(BOOT_DISK) : $(BUILD_DIR)/boot.bin
	qemu-img create -f raw $@ 10M
	printf '\x00' | dd of=$@ bs=1 count=512 conv=notrunc
	dd if=$< of=$@ conv=notrunc
	printf '\x55\xAA' | dd of=$@ bs=1 count=2 conv=notrunc seek=510
	
booting : $(BUILD_DIR)/$(BOOT_DISK)
	qemu-system-i386  -fda $(BUILD_DIR)/$(BOOT_DISK) -boot a



.PHONY:  clean

clean :
	rm -rf $(BUILD_DIR)/$(BOOT_DISK)
	
