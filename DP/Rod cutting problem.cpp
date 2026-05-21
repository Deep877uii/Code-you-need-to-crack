// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size 
//has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

// Note:
// 1. The sizes will range from 1 to ‘N’ and will be integers.

// 2. The sum of the pieces cut should be equal to ‘N’.

// 3. Consider 1-based indexing.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 50
// 1 <= N <= 100
// 1 <= A[i] <= 100

// Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

// Time limit: 1 sec.
// Sample Input 1:
// 2
// 5
// 2 5 7 8 10
// 8
// 3 5 8 9 10 17 17 20
// Sample Output 1:
// 12
// 24
// Explanation of sample input 1:
// Test case 1:

// All possible partitions are:
// 1,1,1,1,1           max_cost=(2+2+2+2+2)=10
// 1,1,1,2             max_cost=(2+2+2+5)=11
// 1,1,3               max_cost=(2+2+7)=11
// 1,4                 max_cost=(2+8)=10
// 5                   max_cost=(10)=10
// 2,3                 max_cost=(5+7)=12
// 1,2,2               max _cost=(1+5+5)=12    

// Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.

int cutRod(vector<int> &price, int n) {
vector<vector<int>> dp(n,vector<int>(n + 1, 0));

for(int N = 0; N <= n; N++) {

        dp[0][N] = N * price[0];
    }

    for(int i = 1; i < n; i++) {
        for(int N = 0; N <= n; N++) {
            int not_take =dp[i - 1][N];
            int take = INT_MIN;
            int rodlength = i + 1;

            if(N >= rodlength) {

                take =price[i] +dp[i][N - rodlength];
            }

            dp[i][N] =max(take, not_take);
        }
    }

    return dp[n - 1][n];
}
