class Solution {
public:
    int mod = 1e9 + 7;

    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();

        sort(ranges.begin(), ranges.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(ans.empty() || ans.back()[1] < ranges[i][0]) {
                ans.push_back(ranges[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], ranges[i][1]);
            }
        }

        long long count = 1;

        for(int i = 0; i < ans.size(); i++) {
            count = (count * 2) % mod;
        }

        return count;
    }
};