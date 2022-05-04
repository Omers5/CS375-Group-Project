# CS375-Group-Project

./runme:
main file takes 1 argument (in range of 1-3, inclusive), and creates a hash table based on inputted argument, then allows user command-line control of the system.
  1 = linear probing
  2 = buckets containing linked list
  3 = buckets containing BST
"make all" to make the main executable file
"./runme <1,2,3>" to run the main executable file


./test:
test file takes 1 argument (input file name), creates 1 heap and 1 of each hash table (meaning 3 hash tables), runs the same tests from input file on each hash table, and outputs the time taken by each test on each hash table.
"make test" to make the test executable file
"./test <input_file_name>" to run test executable file


./inputGenerator:
input generator file takes 2 arguments (output file name, k commands to output), and creates a randomly generated input file for ./test.
"make inputGenerator" to make the input generator executable file
"./inputGenerator <output_file_name> <k where k is greater than 0>" to run input generator executable file




notes:

To change the number of buckets in either program, must go into either Main.cpp or test.cpp and change const int TABLESIZE

Can choose to have ./test print the output of each command or not, by changing const bool BOOLPRINTCMDS (true prints, false does not print)
