class Solution {
public:

    int solve(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int n = nums.size();
        int r = 0, l = 0, count = 0;

        unordered_map<int,int> mpp;

        while(r < n) {

            mpp[nums[r]]++;

            while(mpp.size() > k) {
                mpp[nums[l]]--;

                if(mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);

                l++;
            }
            count += (r - l + 1);
            r++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return solve(nums, k) - solve(nums, k - 1);
    }
};