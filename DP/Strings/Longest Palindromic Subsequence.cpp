// 516. Longest Palindromic Subsequence
// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.size() ;
        vector<int>ahead(n+1),curr(n+1) ;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        for(int i =1 ; i<=n ; i++){
            for(int j = 1 ; j<=n ; j++){
                if(s[i-1]==s2[j-1]) curr[j] = 1+ ahead[j-1];
                else
                curr[j] = max((ahead[j]),curr[j-1]);               
            }

            ahead = curr ; 
        }
        return curr[n];
    }
};
