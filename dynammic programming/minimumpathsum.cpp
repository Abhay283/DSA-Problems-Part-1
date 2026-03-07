#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int minimumpathsum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        // row 0th column
        for (int row = 1; row < n; row++)
        {
            dp[row][0] = grid[row][0] + dp[row - 1][0];
        }
        // col is 0th row
        for (int col = 1; col < m; col++)
        {
            dp[0][col] = grid[0][col] + dp[0][col - 1];
        }
        // no.of possible ways
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
int main()
{
    int n, m;
    cin >> n, m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    solution s;
    cout << s.minimumpathsum(grid);
    return 0;
}