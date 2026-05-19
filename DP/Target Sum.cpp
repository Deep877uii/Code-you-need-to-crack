// 494. Target Sum
// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.
// Example 1:
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Constraints:
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

class Solution {
public:

    int deep(int i,int target,vector<int> &nums,vector<vector<int>> &dp) {

        if(i == 0) {
            if(target == 0 &&nums[0] == 0)return 2;

            if(target == 0 ||target == nums[0])return 1;

            return 0;
        }

        if(dp[i][target] != -1)return dp[i][target];

        int npick =deep(i - 1,target,nums,dp);

        int pick = 0;

        if(target >= nums[i]) {
            pick =deep(i - 1,target - nums[i],nums,dp);
        }
        return dp[i][target] =pick + npick;
    }

    int findTargetSumWays(vector<int>& nums,int target) {

        int total_Sum = 0;

        for(auto &it : nums)total_Sum += it;
        if((total_Sum - target) < 0 ||(total_Sum - target) % 2)return 0;
        int req =(total_Sum - target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(req + 1, -1)
        );

        return deep(n - 1,req,nums,dp);
    }
};
