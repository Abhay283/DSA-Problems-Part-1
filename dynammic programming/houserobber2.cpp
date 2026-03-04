#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int houserob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int prev = nums[0];
        int prev1 = 0;
        for (int i = 0; i < n; i++) {
            int pick = nums[i];
            if (i > 1)
                pick += prev1;
            int notpick = prev;
            int curr = max(pick, notpick);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>&nums){
        int n=nums.size();
        vector<int>temp,temp1;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp.push_back(nums[i]);
            }
            if(i!=n-1){
                temp1.push_back(nums[i]);
            }
        }
        return max(houserob(temp), houserob(temp1));
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