#include<iostream> 
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class solution {
    public:
    int widthbinaryTree(TreeNode* root){
        queue<pair<TreeNode*,unsigned long long>>q;
        int maxiwidth=0;
        q.push({root,0});
        while(q.size()>0){
            int currLevelSize=q.size();
            unsigned long long stIndex=q.front().second;
            unsigned long long endIndex=q.back().second;
            maxiwidth=max(maxiwidth,(int)(endIndex-stIndex+1));
            for(int i=0;i<currLevelSize;i++){
                auto curr=q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left,curr.second*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,curr.second*2+2});
                }
            }
        }
        return maxiwidth;
    }
};
