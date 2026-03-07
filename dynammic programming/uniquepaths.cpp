#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int uniquepaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        //row is 0-th column
        for (int row = 1; row < m; row++)
        {
            dp[row][0] = 1;
        }
        //col is 0th row
        for (int col = 1; col < n; col++)
        {
            dp[0][col] = 1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
int main(){
    int n,m;
    cin>>m>>n;
    Solution s;
    cout<<s.uniquepaths(m,n)<<endl;
    return 0;
}