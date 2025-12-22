#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int SumofSquares(vector<int>&arr){
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
          if(n%(i+1)==0){
            sum+=(arr[i]*arr[i]);
          }  
        }
        return sum;
    }
};