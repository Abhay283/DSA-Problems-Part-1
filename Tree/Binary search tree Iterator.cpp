#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class BSTIterator{
    private: stack<TreeNode*>myStack;
    public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }
    bool hasNext(){
        return !myStack.empty();
    }
    int next(){
        TreeNode* tmpNode=myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    private:
    void pushAll(TreeNode* node){
        for(;node!=NULL;myStack.push(node),node=node->left);
    }
};

int main(){
    TreeNode* root=new TreeNode(7);
    root->left=new TreeNode(3);
    root->right=new TreeNode(9);
    root->left=new TreeNode(1);
    root->right=new TreeNode(12);
    BSTIterator it(root);
    cout<<"Enter the inorder Traversal Iterator";
    while(it.hasNext()){
        cout<<it.next()<<" ";
    }
    cout<<endl;
    return 0;
}