MCU=atmega32
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g -Os -mmcu=${MCU}
TARGET=ATGD
OBJFILES = program1.o program2.o
SRCS=program1.c
SRCSS=program2.c

all:	$(TARGET)

$(TARGET): $(OBJFILES) 

	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS} ${SRCSS}

	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb

clean:
	rm -f *.bin *.hex
