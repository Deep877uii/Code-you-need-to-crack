// 123. Best Time to Buy and Sell Stock III

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

class Solution {
public:
int deep(int i , int buy , int turn ,vector<int> &prices ,int n ,vector<vector<vector<int>>> &dp){

    if(n==i) return 0 ; 
    if(0==turn) return 0 ;

    if(dp[i][buy][turn]!=-1) return dp[i][buy][turn] ;

    int profit = 0 ;
    if (buy){
    profit = max(-prices[i]+deep(i+1,0,turn,prices,n,dp), deep(i+1,1,turn,prices,n,dp));
    }
    else{
        profit = max(prices[i]+deep(i+1,1,turn-1,prices, n,dp),deep(i+1,0,turn, prices, n,dp));
    }

    return dp[i][buy][turn] = profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();        
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3, -1)));
        return deep(0,1,2,prices,n,dp);
    }
};
