class Solution {
public:
    int mod = 1e9 + 7;

    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();

        sort(ranges.begin(), ranges.end());

        int count = 0;
        int end = -1;

        for(int i = 0; i < n; i++) {
            if(i == 0 || ranges[i][0] > end) {
                count++;
                end = ranges[i][1];
            }
            else {
                end = max(end, ranges[i][1]);
            }
        }

        long long ans = 1;

        for(int i = 0; i < count; i++) {
            ans = (ans * 2) % mod;
        }

        return ans;
    }
};