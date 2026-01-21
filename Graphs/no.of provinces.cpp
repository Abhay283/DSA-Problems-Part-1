#include<iostream>
#include<vector>
using namespace std;
class solution{
    private:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    public:
    int numProvinces(vector<vector<int>>& adj,int V){
        int n=adj.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>adj(V,vector<int>(V,0));
    for(int i=0;i<E;i++){
        for(int j=0;j<2;j++){
            int  u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
        }
    }
    solution obj;
    obj.numProvinces(adj,V);
    return 0;
}