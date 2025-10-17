#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode{
int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        if (lh == 0 || rh == 0) {
            return 1 + lh + rh;
        }
        return 1 + min(lh, rh);
    }
};