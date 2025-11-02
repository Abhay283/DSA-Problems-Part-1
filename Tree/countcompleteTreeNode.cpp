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
    int countNodes(TreeNode*  root){
        if(root==NULL){
            return 0;
            int lh=FindheightLeft(root);
            int rh=FindheightRight(root);
        }
        return 1+ countNodes(root->left)+countNodes(root->right);
    }
    int FindheightLeft(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int FindheightRight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
}; 