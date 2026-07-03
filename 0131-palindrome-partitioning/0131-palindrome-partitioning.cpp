class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }

    void solve(int index, string &s, vector<string> &curr) {

        // Entire string is partitioned
        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }
        // Try every substring starting from 'index'
        for (int end = index; end < s.size(); end++) {
            if (isPalindrome(s, index, end)) {
                curr.push_back(s.substr(index, end - index + 1));
                solve(end + 1, s, curr);
                curr.pop_back();     // Backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(0, s, curr);
        return ans;
    }
};