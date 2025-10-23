#include<iostream>
using namespace std;
// class Solution {
// public:
//     bool hasSameDigits(string s) {
//         while (s.size() > 2) {
//             string res = "";
//             for (int i = 0; i < s.size() - 1; i++) {
//                 int sum = (s[i] - '0') + (s[i + 1] - '0');
//                 res += (sum % 10) + '0';
//             }
//             s = res;
//         }
//         return s.size() == 2 && s[0] == s[1];
//     }
// };

class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        string res = "";
        while (s.size() > 2 && i < s.size() - 1) {
            res += (s[i] + s[i + 1]) % 10;
            i++;
            if (i == s.size() - 1) {
                s = res;
                i = 0;
                res = "";
            }
        }
        return s.size() == 2 && s[0] == s[1];
    }
};