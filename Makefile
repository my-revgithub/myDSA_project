CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -Wall -std=gnu11 -O0
INC= -Iinclude/

main.o: main.c
	$(CC) $(CFLAGS) $(INC) -O $@ $^