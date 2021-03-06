HEADERPATH := headers/
SRCPATH := src/
CFLAGS := g++ -c -g -I $(HEADERPATH) -c $(SRCPATH)
CFLAGSH := g++ -c -g -I $(HEADERPATH) -c $(HEADERPATH)

EXECUTABLES := btest \
runme \
test

OBJECTS := Main.o \
BinaryTree.o \
Maxheap.o \
User.o \
ProbeHash.o \

OBJTEST := test.o \
BinaryTree.o \
Maxheap.o \
User.o \
ProbeHash.o \

HEADERS := BinaryTree.h \
Maxheap.h \
User.h \
LinkedList.h \
ProbeHash.h \
HashTemplate.h

all:	runme

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
#runme is used to choose 1 hashtable implementation, and allow user commandline control
runme:	$(OBJECTS)
	g++ -g $(OBJECTS) -o $@
	
#test is used to time all of the different implementations of hashtable
#		while running the same commands with same inputs
test: $(OBJTEST)
	g++ -g $(OBJTEST) -o $@
	
inputGenerator: inputGenerator.o
	g++ -g inputGenerator.o -o $@
	
inputGenerator.o: $(SRCPATH)inputGenerator.cpp
	$(CFLAGS)inputGenerator.cpp -o $@

# Specify how the object files should be created from source files
Main.o: $(SRCPATH)Main.cpp $(HEADERPATH)HashTemplate.h $(HEADERPATH)LinkedList.h
	$(CFLAGS)Main.cpp -o $@
	
test.o: $(SRCPATH)test.cpp $(HEADERPATH)HashTemplate.h $(HEADERPATH)LinkedList.h
	$(CFLAGS)test.cpp -o $@

BinaryTree.o:	$(SRCPATH)BinaryTree.cpp $(HEADERPATH)BinaryTree.h
	$(CFLAGS)BinaryTree.cpp -o $@

User.o: $(SRCPATH)User.cpp $(HEADERPATH)User.h
	$(CFLAGS)User.cpp -o $@

ProbeHash.o:	$(SRCPATH)ProbeHash.cpp $(HEADERPATH)ProbeHash.h
	$(CFLAGS)ProbeHash.cpp -o $@

Maxheap.o: $(SRCPATH)Maxheap.cpp $(HEADERPATH)Maxheap.h
	$(CFLAGS)Maxheap.cpp -o $@

#Test main program

r: runme
	./runme

#Test main program with test input
ri: runme testInput.txt
	./runme < testInput.txt

#below command commented out because ./runme needs commandline args
#rd: runme
#	gdb ./runme

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(OBJECTS) $(EXECUTABLES) test.o inputGenerator.o inputGenerator

wipeScreen:
	clear

clear: clean wipeScreen
