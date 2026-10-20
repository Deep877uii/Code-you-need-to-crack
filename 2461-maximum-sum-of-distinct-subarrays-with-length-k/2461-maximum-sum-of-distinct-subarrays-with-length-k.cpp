class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        long long sum = 0, maxi = 0;

        while(r < n) {
            sum += nums[r];
            mpp[nums[r]]++;
            if(r - l + 1 > k) {
                sum -= nums[l];
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(r - l + 1 == k && mpp.size() == k) {
                maxi = max(maxi, sum);
            }
            r++;
        }
        return maxi;
    }
};