//searlize and deserialize in binary tree 
#include<iostream>
#include<queue>
#include<sstream>
#include<string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class solution{
    public:
    string serialize(TreeNode* root){if (!root)
            return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(curNode->val) + ",");

                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }
    TreeNode* deSerialize(string data){
         if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        std::getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!getline(s, str, ','))
                break;
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            if (!getline(s, str, ','))
                break;
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
