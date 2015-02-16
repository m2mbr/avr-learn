PROG=pro
DF_CPU=16000000
MMCU=atmega328p

hex:
	avr-g++ -Os -DF_CPU=$(DF_CPU) -mmcu=$(MMCU) -c $(PROG).cc
	avr-g++ -DF_CPU=$(DF_CPU) -mmcu=$(MMCU) -o $(PROG).elf $(PROG).o
	avr-objcopy -O ihex $(PROG).elf $(PROG).hex
	rm $(PROG).o
	rm $(PROG).elf

flash:
	avrdude  -c arduino -p $(MMCU) -P /dev/ttyACM0 -U flash:w:$(PROG).hex
