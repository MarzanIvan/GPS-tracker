
NameOfProgram = main
VersionMCU = atmega328p
Compiler = avr-g++

Clean:
	clean.cmd

CreateObjectsHpps: 
	$(Compiler) -g -Os -mmcu=$(VersionMCU) -c src/Config_Interrupts.cpp
	$(Compiler) -g -Os -mmcu=$(VersionMCU) -c src/IODataUSART.cpp
	$(Compiler) -g -Os -mmcu=$(VersionMCU) -c src/Display_LCD.cpp

Build: $(NameOfProgram).cpp Config_Interrupts.o IODataUSART.o Display_LCD.o
	$(Compiler) -g -Os -mmcu=$(VersionMCU) -c $(NameOfProgram).cpp
	$(Compiler) -g -mmcu=$(VersionMCU) -o $(NameOfProgram).elf $(NameOfProgram).o Config_Interrupts.o IODataUSART.o Display_LCD.o
	avr-objcopy -j .text -j .data -O ihex $(NameOfProgram).elf $(NameOfProgram).hex