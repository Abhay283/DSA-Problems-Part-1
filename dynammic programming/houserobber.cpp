#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int rob(vector<int>&nums){
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solution s;
    cout<<s.rob(nums)<<endl;
    return 0;
}