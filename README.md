# CS375-Group-Project

main file takes 1 argument (1-3, inclusive), and creates a hash table based on inputted argument, then allows user command-line control of the system
  1 = linear probing
  2 = buckets containing linked list
  3 = buckets containing BST
"make Main" to make the main file
"make run" to run the main file


test files takes 0 arguments, creates 1 heap and 1 of each hash table (meaning 3 hash tables), runs the same preset tests on each hash table, and outputs the time taken by each test on each hash table.
"make Test" to make the test file
"make runTest" to run the test file

====================================================================
BRANCH bst_heap

Created a program which runs the whole auction using BST + Maxheap
to run, 
make all
./runme <number>

TODO: 
1. create a way to end the bid
2. random assasination
3. put timer 

