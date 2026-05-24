// 188. Best Time to Buy and Sell Stock IV
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

class Solution {
public:

int deep(int i , int buy , int k , vector<int>&prices,int n , vector<vector<vector<int>>>&dp){
   
   if(n==i) return 0 ;
   if(k == 0) return 0;
   
   if(dp[i][buy][k]!=-1) return dp[i][buy][k];
   int profit=0;
   if(buy){
      profit = max(-prices[i]+deep(i+1,0,k,prices,n,dp),deep(i+1,1,k,prices,n,dp));
      }
        else{
            profit = max(prices[i]+deep(i+1,1,k-1,prices,n,dp),deep(i+1,0,k,prices,n,dp));
        }

        return dp[i][buy][k] = profit ;  

}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return deep(0,1,k,prices,n,dp);
    }
};
