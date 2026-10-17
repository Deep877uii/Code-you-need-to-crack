class Solution {
public:

    int t[1001][1001];

    bool solve(string &s , int i , int j){

        if(i>=j) return t[i][j] = true ; 

        if(t[i][j]!=-1){
            return t[i][j];
        }

        if(s[i]==s[j]){
            return t[i][j] = solve(s,i+1,j-1);
        }
        return t[i][j]=false ;
    }

    string longestPalindrome(string s) {
        int n = s.size() , max_len = INT_MIN , sp = -1 ;
        memset(t,-1,sizeof(t));
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solve(s,i,j)==true){
                    if(max_len<(j-i+1)){
                        max_len=(j-i+1);
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,max_len);
    }
};