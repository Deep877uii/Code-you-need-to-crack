class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() ; 
        map<char,int>mpp;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
        }

        for(auto it : mpp){
            while(it.second>=3){
                it.second-=2 ;
            }
            sum+= it.second ;
        }
        return sum ;
    }
};