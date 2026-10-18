class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = n / 2;
        long long ops = 0;

        for (int i = mid; i >= 0 && nums[i] > k; i--) {
            ops += nums[i] - k;
        }
        
        for (int i = mid; i < n && nums[i] < k; i++) {
            ops += k - nums[i];
        }

        return ops;
    }
};