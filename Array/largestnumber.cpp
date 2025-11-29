#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class solution{
    public:
    struct comp{
        bool operator()(const string &a,const string&b)const{
            return a+b>b+a;
        }
    };
    string largestnumber(vector<int>&nums){
        vector<string>ans;
        for(int &ch:nums){
            ans.push_back(to_string(ch));
        }
        sort(ans.begin(),ans.end(),comp());
        if(ans[0]=="0")return "0";
        string res="";
        for(string &x:ans){
            res+=x;
        }
        return res;
    }
};