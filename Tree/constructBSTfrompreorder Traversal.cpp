#include <iostream>
#include <climits>
#include <vector>
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
    TreeNode *bstfrompreorder(vector<int> &A)
    {
        int i = 0;
        return build(A, i, INT_MAX);
    }
    TreeNode *build(vector<int> &A, int &i, int bound)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};