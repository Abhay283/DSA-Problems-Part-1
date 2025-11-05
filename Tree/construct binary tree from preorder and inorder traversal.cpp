#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
    TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> mp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        // int inroot=preorder[preStart];
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inroot = mp[root->val];
        int numsLeft = inroot - inStart;
        root->left = helper(preorder, preStart + 1, preStart + numsLeft + 1, inorder, inStart, inroot - 1, mp);
        root->right = helper(preorder, preStart + numsLeft + 1, preEnd, inorder, inroot + 1, inEnd, mp);
        return root;
    }
};