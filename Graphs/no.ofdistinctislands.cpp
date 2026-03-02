#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
class solution{
    private:
    void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>shape){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        int baserow=row;
        int basecol=col;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            shape.push_back({r-baserow,c-basecol});
            int delrow[]={1,0,-1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    public:
    int countdistinctIslands(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>>shape;
                bfs(i,j,grid,vis,shape);
                st.insert(shape);
            }
        }
        return st.size();
    }
};
