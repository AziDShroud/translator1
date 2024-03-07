#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <queue>
#include <sstream>


// Node structure for the  tree
struct TreeNode {
    char data;
    vector <TreeNode*> children;
    TreeNode(char value) : data(value){}
};

void printLevelOrder(TreeNode* root) ;

