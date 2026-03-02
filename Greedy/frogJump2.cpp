#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
    int frogJump(vector<int>&stones){
      int n=stones.size();
      int maxi=stones[1];
      for(int i=2;i<n;i++){
        maxi=max(maxi,stones[i]-stones[i-2]);
      }
      return maxi;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>stones(n);
    solution obj;
    obj.frogJump(stones);
    return 0;
}

