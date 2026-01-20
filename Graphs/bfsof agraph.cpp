#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class solution{
    public:
    vector<int>bfsOfGraph(vector<vector<int>>&adj){
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>Bfs;
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            Bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return Bfs;
    }
};