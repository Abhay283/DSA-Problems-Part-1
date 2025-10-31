#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val (x),left(NULL),right(NULL){}
};

class solution{
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& Parent_track,
                     TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                Parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                Parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> Parent_track;
        markParents(root, Parent_track, target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (Parent_track[current] && !visited[Parent_track[current]]) {
                    q.push(Parent_track[current]);
                    visited[Parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};