#include "tree.h"




void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";

            for (TreeNode* child : current->children) {
                q.push(child);
            }
             

        }
         cout<<endl;
    }
   
}











  




  
