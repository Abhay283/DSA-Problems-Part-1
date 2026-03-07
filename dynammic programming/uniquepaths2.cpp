#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int uniquePathswithobstacle(vector<vector<int>>&obstacleGrid){
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        else{
            dp[0][0] = 1;
        }
        //row is 0-th column
        for(int row=1;row<n;row++){
            if(obstacleGrid[row][0]==1){
                dp[row][0]=0;
            }
            else{
                dp[row][0]=dp[row-1][0];
            }
        }
        //col is o-th row
        for(int col=1;col<m;col++){
            if(obstacleGrid[0][col]==1){
                dp[0][col]=0;
            }
            else{
                dp[0][col]=dp[0][col-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
  }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> obstacleGrid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>obstacleGrid[i][j];
        }
    }
    solution s;
    cout<<s.uniquePathswithobstacle(obstacleGrid)<<endl;
    return 0;
}