#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
long long countPairs(vector<int>& nums,int limit){
 int n=nums.size();
        int low=0;
        int high=n-1;
        long long count=0;
        while(low<high){
            // count+=(r-l);
            
            if(nums[low]+nums[high]<=limit){
               count+=(high-low);
               low++;
            }
            else{
                // low=mid+1;
                high--;
            }
        }
        return count;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       
        sort(nums.begin(),nums.end());
       return countPairs(nums,upper)-countPairs(nums,lower-1);
    }
};