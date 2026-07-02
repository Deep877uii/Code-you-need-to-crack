class Solution {
public:

    vector<string>ans;

    void deep(int ind , string &digits , string &result, unordered_map<char,string>&mpp){

        if(ind>=digits.size()){
            ans.push_back(result);
            return;
        }

        char ch = digits[ind];
        string str = mpp[ch];

        for(int i = 0 ; i<str.size();i++){
            result.push_back(str[i]);
            deep(ind+1,digits,result,mpp);
            result.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return{};
        }
        unordered_map<char,string>mpp;

        mpp['2']= "abc";
        mpp['3']= "def";
        mpp['4']= "ghi";
        mpp['5']= "jkl";
        mpp['6']= "mno";
        mpp['7']= "pqrs";
        mpp['8']= "tuv";
        mpp['9']= "wxyz";

        string result = "" ;

        deep(0,digits,result,mpp);
        return ans;
    }
};