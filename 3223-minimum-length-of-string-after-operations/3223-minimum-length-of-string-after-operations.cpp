class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() ; 
        int deleted = 0 ;
        vector<int>fre(26,0);
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            fre[s[i]-'a'] += 1 ;
            if(fre[s[i]-'a']==3){
                fre[s[i]-'a']-=2;
                deleted+=2;
            }
        }
        return n-deleted ;
    }
};