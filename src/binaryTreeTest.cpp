// #include "BinaryTree.h"

// int main(int argc, char const *argv[])
// {

//     User y("x");
//     User x("y");

//     bool bigger = x < y;

//     cout << bigger << endl;

//     BinaryTree bt;
//     cout << "Tree Created" << endl;

//     User a("a");
//     User b("b");
//     User c("c");
//     User d("d");
//     User e("e");
//     User f("f");
//     User g("g");
//     User testArrOfUsers[7] = {f, d, b, a, e, c, g};

//     for (int i = 0; i < sizeof(testArrOfUsers) / sizeof(testArrOfUsers[0]); ++i)
//     {
//         // Test add
//         bt.addNode(testArrOfUsers[i]);
//         cout << "User " << testArrOfUsers[i].getName() << " added" << endl;
//     }
//     cout << "All Users Created" << endl;

//     // Check Head Node
//     cout << "Head Node: " << bt.getHeadNode()->getUser()->getName() << endl;

//     // Test delete, works except for the case where both
    
//     //bt.removeNode("a");
//     //bt.removeNode("b");
//     //bt.removeNode("d");
//     //bt.removeNode("c");
    
//     //bt.removeNode("e");
//     //bt.removeNode("g");
//     //bt.removeNode("f");
//     string lookupTestStr = "d";
//     cout << lookupTestStr << " == " << bt.lookupUser(lookupTestStr)->getName() << endl;

//     bt.printInfo();
//     return 0;
// }
