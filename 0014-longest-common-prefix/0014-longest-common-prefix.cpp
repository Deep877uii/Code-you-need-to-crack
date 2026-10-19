class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());

        string ans ="";

        string start = strs[0];
        string end = strs[n-1];
        
        int min_len = min(start.size(),end.size());

        for(int i = 0 ; i < min_len ; i++){
            if(start[i]!=end[i]){
                break;
            }
            ans+=start[i];
        }
        return ans ;
    }
};