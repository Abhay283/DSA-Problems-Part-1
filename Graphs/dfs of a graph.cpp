//DFS of a graph using stack
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;
// class solution{
//     public:
//     vector<int>Dfs(vector<vector<int>>& adj){
//         int n=adj.size();
//         vector<int>vis(n,0);
//         vis[0]=1;
//         vector<int>res;
//         stack<int>st;
//         st.push(0);
//         while(!st.empty()){
//             int node=st.top();
//             st.pop();
//             if(!vis[node]){
//                 vis[node]=1;
//                 res.push_back(node);
//                 for(int i=adj[node].size()-1;i>=0;i--){
//                     int it=adj[node][i];
//                     if(!vis[it]){
//                         st.push(it);
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };
//DFS of a graph using recrusion
#include<iostream>
#include<vector>
using namespace std;
class solution{
    private:
    void dfs(int node,vector<int>&vis,vector<int>&res,vector<vector<int>>& adj){
        vis[node]=1;
        res.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,res,adj);
            }
        }
    }
    public:
    vector<int>Dfs(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>res;
        dfs(0,vis,res,adj);
        return res;
    }
};