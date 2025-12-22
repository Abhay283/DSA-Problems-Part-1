#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> mp;
        set<int> st;
        int n = matches.size();
        ;
        for (int i = 0; i < n; i++)
        {
            int x = matches[i][0];
            int y = matches[i][1];
            st.insert(x);
            mp[y]++;
        }
        for (int i = 0; i < n; i++)
        {
            int x = matches[i][0];
            int y = matches[i][1];
            if (st.find(y) != st.end())
            {
                st.erase(y);
            }
        }
        vector<int> v1, v2;
        for (int x : st)
        {
            v1.push_back(x);
        }
        for (auto m : mp)
        {
            if (m.second == 1)
            {
                v2.push_back(m.first);
            }
        }
        return {v1, v2};
    }
};