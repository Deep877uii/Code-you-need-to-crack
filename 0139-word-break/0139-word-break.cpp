class Solution {
public:

    unordered_set<string> st;

    bool deep(int ind, string &s, vector<int>& dp) {

        if(ind == s.size()) {
            return true;
        }

        if(dp[ind] != -1) {
            return dp[ind];
        }

        for(int l = 1; ind + l <= s.size(); l++) {

            string temp = s.substr(ind,l);

            if(st.find(temp) != st.end() && deep(ind+l,s,dp)) {
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for(int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }

        vector<int> dp(s.size(),-1);

        return deep(0,s,dp);
    }
};