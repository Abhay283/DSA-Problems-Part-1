#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class solution{
    public:
     TreeNode* searchBST(TreeNode* root,int val){
        while(root!=NULL && root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        return root;
     }
};