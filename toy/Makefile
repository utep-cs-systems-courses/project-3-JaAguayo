COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

CC		= msp430-elf-gcc
AS		= msp430-elf-gcc -mmcu=${CPU} -c

all: toy.elf

toy.elf: ${COMMON_OBJECTS} main.o stateMachines.o led.o wdt_handler.o p2_interrupt_handler.o switches.o buzzer.o display.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lTimer -lShape 

load: toy.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
