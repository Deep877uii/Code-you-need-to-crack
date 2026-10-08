class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0 ; 
        int n = s.size() ;
        string p = "" ;
        for(int i = 0 ; i<=n ; i++){
            if('('==s[i]){
                count++;
                if(count>1) {
                    p.push_back(s[i]) ;
                    }
            }
            else{
                count--;
                if(count>0){
                 p.push_back(s[i]);
                }
            }
        }
        return p ;
    }
};