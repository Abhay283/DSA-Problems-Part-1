#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
    class solution{
        public:
        void inorder(TreeNode*root,vector<int>&arr){
            if(!root)return;
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
        int rangeSumBST(TreeNode* root,int low,int high){
            vector<int>arr;
            inorder(root,arr);
            int n=arr.size();
            int sum=0;
            for(int i=0;i<n;i++){
                if(arr[i]>=low && arr[i]<=high){
                    sum+=arr[i];
                }
                else if(arr[i]>high){
                    break;
                }
                else{
                    continue;
                }
            }
            return sum;
        }
    };
    
