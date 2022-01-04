FQBN:=arduino:avr:uno
PORT:=/dev/ttyACM1

ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT:=$(shell basename $(CURDIR))

BUILD_DIR:=$(ROOT_DIR)/target

$(BUILD_DIR)/$(PROJECT).ino.elf: $(PROJECT).ino
	arduino-cli compile -b $(FQBN) --output-dir $(BUILD_DIR)

upload: $(BUILD_DIR)/$(PROJECT).ino.elf
	arduino-cli upload -i $(BUILD_DIR)/$(PROJECT).ino.elf -b $(FQBN) -p $(PORT)


clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean



