#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=1;
        int ans=0;
        int maxi=1;
        for(int i=1;i<=n;i++){
            if(i<n && nums[i]==nums[i-1]){
                count++;
            }
            else{
                if(count>maxi){
                    maxi=count;
                    ans=count;
                }
                else if(count==maxi){
                    ans+=count;
                }
                count=1;
            }
        }
        return ans;
    }
};