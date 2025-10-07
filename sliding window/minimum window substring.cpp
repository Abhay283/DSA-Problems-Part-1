#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
    int minlen = INT_MAX, start = -1;
    vector<int> hash(256, 0);

    for (char c : t) hash[c]++;

    int cnt = 0;
    for (int i = 0, j = 0; j < n; j++) {
        if (hash[s[j]] > 0) cnt++;
        hash[s[j]]--;

        while (cnt == m) {
            if (j - i + 1 < minlen) {
                minlen = j - i + 1;
                start = i;
            }
            hash[s[i]]++;
            if (hash[s[i]] > 0) cnt--;
            i++;
        }
    }
    return (start == -1 ? "" : s.substr(start, minlen));
    }
};