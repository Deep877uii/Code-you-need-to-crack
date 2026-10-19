class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() ; 

        vector<int>fre(26,0);
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            fre[s[i]-'a'] += 1 ;
            if(fre[s[i]-'a']==3){
                fre[s[i]-'a']-=2;
            }
        }
        for(int i = 0 ; i<26 ; i++){
            if(fre[i]==0) continue;
            sum+=fre[i];
        }
        return sum ;
    }
};