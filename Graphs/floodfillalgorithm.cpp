#include<iostream>
#include<vector>
using namespace std;
class solution{
    private:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newcolor,int delrow[],int delcol[],int inicolor){
        ans[row][col]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int r=row+delrow[i];
            int ncol=col+delcol[i];
            if(r>=0 && r<n && ncol>=0 && ncol<m && image[r][ncol]=inicolor && ans[r][ncol]!=newcolor){
                dfs(r,ncol,ans,image,newcolor,delrow,delcol,inicolor);
            }
        }

    };
    public:
    vector<vector<int>>floodfill(vector<vector<int>>image,int sr,int sc,int newcolor){
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,newcolor,delrow,delcol,inicolor);
    }
};