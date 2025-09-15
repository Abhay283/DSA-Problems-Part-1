#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int count = 0;
        vector<int> broken(26, 0);
        for (char& ch : brokenLetters) {
            broken[ch - 'a'] = 1;
        }
        bool cantype = true;
        for (int i = 0; i <=n; i++) {
            if (i==n || text[i] == ' ') {
                if (cantype)
                    count++;
                cantype = true;
            } else if (broken[text[i] - 'a']) {
                cantype = false;
            }
        }
        return count;
    }
};