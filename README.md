# CS375-Group-Project

main file takes 1 argument (in range of 1-3, inclusive), and creates a hash table based on inputted argument, then allows user command-line control of the system
  1 = linear probing
  2 = buckets containing linked list
  3 = buckets containing BST
"make all" to make the main file
"./runme <1,2,3>" to run the main file


test files takes 1 argument (input file name), creates 1 heap and 1 of each hash table (meaning 3 hash tables), runs the same tests from input file on each hash table, and outputs the time taken by each test on each hash table.
"make test" to make the test file
"./test <input_file_name>" to run test file
