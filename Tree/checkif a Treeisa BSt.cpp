#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
    bool isValidBST(TreeNode *root, long maxval, long minval)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxval || root->val <= minval)
        {
            return false;
        }
        return isValidBST(root->left, root->val, minval) && isValidBST(root->right, maxval, root->val);
    }
};
