class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> me(n, 1);

        // Prefix product
        for(int i = 1; i < n; i++) {
            me[i] = me[i - 1] * nums[i - 1];
        }

        // Suffix product
        int right = 1;

        for(int i = n - 1; i >= 0; i--) {

            me[i] = me[i] * right;

            right *= nums[i];
        }

        return me;
    }
};