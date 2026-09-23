class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {

        map<int,int> mpp;
        int l = 0, r = 0;
        int n = nums.size();
        int max_len = 0;
        int max_freq = 0;
        while(r < n) {
            mpp[nums[r]]++;
            max_freq = max(max_freq, mpp[nums[r]]);
            while((r-l+1) - max_freq > k) {
                mpp[nums[l]]--;
                l++;
            }
            max_len = max(max_len, max_freq);
            r++;
        }
        return max_len;
    }
};