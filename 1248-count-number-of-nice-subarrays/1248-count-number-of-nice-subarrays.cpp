class Solution {
public:

        int solve(vector<int>& nums, int k) {

        int n = nums.size();

        int r = 0, l = 0, sum = 0, count = 0;

        if(k < 0) return 0;

        while(r < n) {

            sum += (nums[r]%2);
            while(sum > k) {
                sum -= (nums[l]%2);
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
         return solve(nums, k) - solve(nums, k - 1);
    }
};

