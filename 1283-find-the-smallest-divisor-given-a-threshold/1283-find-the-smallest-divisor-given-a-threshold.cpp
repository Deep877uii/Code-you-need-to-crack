class Solution {
public:

    bool possible(vector<int>& nums, int threshold, int mid) {
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += (nums[i] + mid - 1) / mid;
        }

        if (total <= threshold) return true;
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
