// Subset Sum Problem

// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
// Constraints:
// 1 <= arr.size() <= 200
// 1<= arr[i] <= 200
// 1<= sum <= 104

class Solution {
  public:
  
  bool deep(int i , int sum , vector<int> & arr , vector<vector<int>>&dp ){
      
      if(0==sum) return true ;
      
      if(0==i){
          return sum==arr[0] ; 
      }
      if (dp[i][sum]!=-1) return dp[i][sum] ;
      
      bool not_pick = deep(i-1,sum,arr,dp);
      bool pick = false ;
      if(sum>=arr[i]){
          pick = deep(i-1,sum-arr[i] , arr,dp);
      }
      return dp[i][sum] = pick | not_pick ;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size() ;
        vector<vector<int>> dp (n+1, vector<int>(sum+1,-1));
        return deep(n-1,sum , arr ,dp) ;
    }
};
