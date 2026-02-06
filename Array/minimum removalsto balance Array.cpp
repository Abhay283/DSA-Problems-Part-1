#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    int minRemoval(vector<int>&nums,int k){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int maxlen=0;
        for(int j=0;j<n;j++){
            while((long long)nums[j]>(long long)nums[i]*k){
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return n-maxlen;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solution obj;
    int ans=obj.minRemoval(nums,k);
    cout<<ans<<endl;
}