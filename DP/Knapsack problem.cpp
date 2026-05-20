// Problem statement
// A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
//There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum 
//weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10^2
// 1<= wi <= 50
// 1 <= vi <= 10^2
// 1 <= W <= 10^3
// Time Limit: 1 second
// Sample Input:
// 1 
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output:
// 13

#include <bits/stdc++.h> 

  int deep(int i , vector<int>&weight , vector<int>&value,int maxWeight ,vector<vector<int>>&dp){
    if(i == 0) {

        if(weight[0] <= maxWeight)
            return value[0];

        return 0;
    }
	  if(dp[i][maxWeight]!= -1) return dp[i][maxWeight] ;
	  int npick = 0+deep(i-1,weight,value,maxWeight,dp);
	  int pick = INT_MIN ; 
	  if(maxWeight>=weight[i]){
		  pick = value[i] + deep(i-1,weight,value,maxWeight-weight[i],dp) ;
	  }
	  return dp[i][maxWeight] = max(npick,pick) ;
  }
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return deep(n-1,weight,value,maxWeight,dp);
}
