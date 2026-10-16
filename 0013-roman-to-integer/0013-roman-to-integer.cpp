class Solution {
public:

    int convert(string &s , unordered_map<char,int>&mpp){
        int n = s.size();
        int sum = 0 ; 

        for(int i = 1 ; i <= n ; i++){
            if(mpp[s[i]]>mpp[s[i-1]]){
                sum-=mpp[s[i-1]];
            }
            else{
                sum+=mpp[s[i-1]];
            }
        }
        return sum ; 
    }

    int romanToInt(string s) {
        unordered_map<char, int> mpp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        return convert(s,mpp);
    }
};