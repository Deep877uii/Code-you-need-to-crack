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

        int answer = INT_MIN;
        for (int start = 0; start < n; start++) {
            int current = deep(start, energy, k, dp);
            if (current > answer) {
                answer = current;
            }
        }
        return answer;
    }
};