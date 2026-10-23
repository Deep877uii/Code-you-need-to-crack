#include <iostream>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        for (int j = 0; j < m; j++) {
            mpp[t[j]]--;
        }

        int ans = 0;

        for (auto it : mpp) {
            if (it.second > 0) {
                ans += it.second;
            }
        }

        return ans;
    }
};