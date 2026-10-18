class Solution {
public:

    int deep(int i, vector<int>& energy, int k, vector<int>& dp) {
        if (i >= (int)energy.size()) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        dp[i] = energy[i] + deep(i + k, energy, k, dp);
        return dp[i];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);

        int ans = INT_MIN;
        for (int start = n-1; start >=0 ; start--) {
            ans =max(deep(start, energy, k, dp),ans);
        }
        return ans;
    }
};