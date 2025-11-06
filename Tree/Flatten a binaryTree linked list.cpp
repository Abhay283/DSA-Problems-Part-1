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
    TreeNode* nextRight=NULL;
    void flatten(TreeNode* root){
        if(root==NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=nextRight;
        nextRight=root;
    }
};