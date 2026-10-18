class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = n / 2;
        long long ans = 0;

        if (nums[mid] > k) {
            for (int i = mid; i >= 0; i--) {
                if (nums[i] > k) {
                    ans += (long long)(nums[i] - k);
                }
            }
        } else if (nums[mid] < k) {
            for (int i = mid; i < n; i++) {
                if (nums[i] < k) {
                    ans += (long long)(k - nums[i]);
                }
            }
        }
        return ans;
    }
};