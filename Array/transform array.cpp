#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>constructTransformedArray(vector<int>&nums){
        int n=nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int new_index=(i+nums[i])%n;
                result[i]=nums[new_index];
            }
            else if(nums[i]<0){
                int steps=abs(nums[i]);
                int new_index=(i-steps)%n;
                if(new_index<0){
                    new_index+=n;
                }
                result[i]=nums[new_index];
            }
            else{
                result[i]=nums[i];
            }
        }
        return result;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solution obj;
    vector<int> ans=obj.constructTransformedArray(nums);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}