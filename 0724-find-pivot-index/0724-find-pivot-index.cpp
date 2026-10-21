
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int pre = 0;

        for (int x : nums) {
            total += x;
        }

        for (int i = 0; i < nums.size(); i++) {
            int suff = total - pre - nums[i];

            if (pre == suff) {
                return i;
            }

            pre += nums[i];
        }

        return -1;
    }
};
