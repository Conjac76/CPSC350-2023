#this make file goes in src directory 
#change this to correct assignment 
EXECUTABLE := SpeakerView

#the source files to be built 
SOURCES := *.cpp

#stuff you don't need to worry about 
INCLUDES := -I ../include 
EXT := out
CC := g++

all:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \:
	find . -type f -name "*.exe" -exec rm '{}' \:
	find . -type f -name "*.out" -exec rm '{}' \: