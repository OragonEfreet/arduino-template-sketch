# Makefile for Arduino CLI

Just a naïve makefile implementation for wrapping up arduino-cli commands.

## Requirements

- (Arduino CLI)[https://www.arduino.cc/pro/cli]
- `GNU Make`

## Usage

The main .ino file is based on the current folder name.
If your folder is called _MyProject_, you must at least provide a _MyProject.ino_ file.
It must be placed in the same folder as this makefile.

Build files will be generated under the _./target_ folder.

- `make`: Compile the sketch file
- `make upload`: Compile and upload the sketch file to the board
- `make clean`: Removes the build files

## Configuration

Open the _Makefile_ and change the `FQBN` and `PORT` values to your needs:
```
FQBN:=arduino:avr:uno
PORT:=/dev/ttyACM1
```

Then run `make clean` to remove previous artifacts.

## TODO

- Use `arduino-cli board` to automatically set `PORT` according to `FQBN` and `FQBN` according to a board name.
- Add Verbose option
- Add verify option





