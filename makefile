HEADERPATH := headers/
SRCPATH := src/
CFLAGS := g++ -c -g -I $(HEADERPATH) -c $(SRCPATH)

EXECUTABLES := btest \
runme

OBJECTS := main.o \
BinaryTree.o \
BinaryTreeNode.o \
Maxheap.o \
User.o

HEADERS := BinaryTree.h \
BinaryTreeNode.h \
Maxheap.h \
User.h

all:	runme

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
runme:	$(OBJECTS)
	g++ -g $(OBJECTS) -o $@

# Specify how the object files should be created from source files
main.o: $(SRCPATH)main.cpp 
	$(CFLAGS)main.cpp -o $@

BinaryTreeNode.o:	$(SRCPATH)BinaryTreeNode.cpp $(HEADERPATH)BinaryTreeNode.h
	$(CFLAGS)BinaryTreeNode.cpp -o $@

BinaryTree.o:	$(SRCPATH)BinaryTree.cpp $(HEADERPATH)BinaryTree.h
	$(CFLAGS)BinaryTree.cpp -o $@

User.o: $(SRCPATH)User.cpp $(HEADERPATH)User.h
	$(CFLAGS)User.cpp -o $@

Maxheap.o: $(SRCPATH)Maxheap.cpp $(HEADERPATH)Maxheap.h
	$(CFLAGS)Maxheap.cpp -o $@

#Test main program

r: runme
	./runme

#Test main program with test input
ri: runme testInput.txt
	./runme < testInput.txt

rd: runme
	gdb ./runme
#Tests for Binary Tree
binaryTreeTest.o: $(SRCPATH)binaryTreeTest.cpp
	$(CFLAGS)binaryTreeTest.cpp -o $@


btest: BinaryTreeNode.o BinaryTree.o User.o binaryTreeTest.o
	g++ -g BinaryTree.o BinaryTreeNode.o User.o binaryTreeTest.o -o $@

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(OBJECTS) $(EXECUTABLES)

wipeScreen:
	clear

clear: clean wipeScreen
