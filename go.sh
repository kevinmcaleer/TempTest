make
avrdude -p m328p -c gpio -e -U flash:w:build-uno/TempTest.hex

