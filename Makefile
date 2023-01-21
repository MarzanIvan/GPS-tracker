
NameOfProgram = main
VersionOfMCU = atmega328p
Compiler = avr-g++
FolderOfBuilding = Build
FolderOfSourceCode = src
FolderOfHeaders = include
CommandForCleaning = rm

SourceCode = main.cpp Config_Interrupts.cpp IODataUSART.cpp Display_LCD.cpp
SOURCE = $(addprefix $(FolderOfSourceCode)/,$(SourceCode))
OBJECTS = $(addprefix $(FolderOfBuilding)/, $(SourceCode:.cpp=.o))

Build/%.o: src/%.*
	$(Compiler) -g -Os -mmcu=$(VersionOfMCU) -c $< -o $@

Build: $(OBJECTS) 
	$(Compiler) -g -mmcu=$(VersionOfMCU) -o Build/$(NameOfProgram).elf $(OBJECTS)
	avr-objcopy -j .text -j .data -O ihex Build/$(NameOfProgram).elf $(FolderOfBuilding)/$(NameOfProgram).hex 	

Clean:
	$(CommandForCleaning) $(FolderOfBuilding)/$(NameOfProgram).elf $(FolderOfBuilding)/$(NameOfProgram).hex $(OBJECTS)