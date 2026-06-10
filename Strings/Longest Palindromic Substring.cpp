// 5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

class Solution {
public:

bool deep(string &s , int i , int j ){

    if(i>=j) return true ;

    if(s[i]==s[j]) return deep(s , i+1 , j-1);

    else return false ;
}

    string longestPalindrome(string s) {
        int n = s.size();
        int maxl = 0;
        int sp = -1 ;
        for(int i = 0 ; i< n ; i++){
            for(int j = i ; j< n ; j++){
                if(deep(s,i,j)==true){
                    if((j-i+1)>maxl){
                        maxl=j-i+1 ; 
                        sp=i ;
                    }
                }
            }
        }
        return s.substr(sp,maxl);
    }
};
