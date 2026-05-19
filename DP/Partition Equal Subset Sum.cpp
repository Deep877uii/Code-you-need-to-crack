// 416. Partition Equal Subset Sum

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
// Example 1:
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 
// Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
class Solution {
public:

bool deep(int i , int sum , vector<int> & nums , vector<vector<int>> &dp){
    if(0==sum) return true ;
    if(i==0) return sum == nums[0];
    
    if(dp[i][sum]!= -1 ) return dp[i][sum] ;
    bool not_pick = deep(i-1 , sum , nums , dp );
    bool pick = false ;
    if(sum>=nums[i]){
        pick = deep(i-1 , sum-nums[i] , nums , dp);
    }
    return dp[i][sum] = pick || not_pick ; 
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int totalsum = 0 ; 
        for(int i = 0 ; i<nums.size() ; i++){
            totalsum +=nums[i] ;
        }
        if(totalsum % 2) return false ;
        int target = totalsum/2 ;
        
        vector<vector<int>> dp (n+1, vector<int>(target+1,-1));
        return deep(n-1 , target , nums , dp);
    }
};
