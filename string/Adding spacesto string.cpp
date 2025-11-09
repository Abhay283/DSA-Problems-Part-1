#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
    string addSpaces(string s, vector<int>& spaces){
        int n=s.size();
        int m=spaces.size();
        int i=0,j=0;
        string ans="";
        while(i<n){
            if(j<m && i==spaces[j]){
                ans+=" ";
                j++;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};