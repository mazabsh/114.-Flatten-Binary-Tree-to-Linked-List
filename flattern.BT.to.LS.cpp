#include<iostream>

using namespace std; 

struct TreeNode{
public: 
  int val; 
  TreeNode* left; 
  TreeNode* right; 
  TreeNode(): val(0), left(nullptr), right(nullptr){}
  TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
  TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};
class Solution{
public:
     TreeNode* prev = nullptr; 
     void flattern(TreeNode* root){
       if(!root) return; 

       flattern(root->right); 
       flattern(root->left); 
       root->right = prev; 
       root->left = nullptr;
       prev = root; 
       
     }
};
void printFlattened(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        cout << cur->val;
        if (cur->right) cout << " -> ";
        cur = cur->right;
    }
    cout << endl;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    // Print the flattened linked list
    printFlattened(root);   // Expected output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

    return 0;
}
