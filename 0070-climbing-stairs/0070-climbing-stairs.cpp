class Solution {
public:

    int deep(int n , vector<int>&dp){
        if(n==0 || n==1) return 1 ; 

        if(dp[n]!=-1) return dp[n]  ;

        dp[n]= deep(n-1,dp)+deep(n-2,dp) ;
        return dp[n] ; 
    }

    int climbStairs(int n){
        vector<int>dp(n+1,-1) ;
        return deep(n , dp) ; 
    }
};