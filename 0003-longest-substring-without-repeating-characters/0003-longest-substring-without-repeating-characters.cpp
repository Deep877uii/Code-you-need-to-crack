class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;
        int n = s.size() ;
        int l = 0, r=0 , max_len = 0 ;

        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                l = max(l, mpp[s[r]] + 1);
            }
            mpp[s[r]]=r;
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len ;
    }
};