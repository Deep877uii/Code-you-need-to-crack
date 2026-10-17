class Solution {
public:
    bool solve(string word) {
        int n = word.size();

        if(n == 0) return false;

        string vowels = "aeiou";

        if(vowels.find(word[0]) != string::npos &&
           vowels.find(word[n-1]) != string::npos) {
            return true;
        }

        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int q = queries.size();
        vector<int> res(q);
        vector<int> cusum(n);

        int sum = 0 ; 
        for(int i = 0 ; i<n ; i++){
            if(solve(words[i])){
                sum++;
            }
            cusum[i] = sum ;
        }
        for(int i = 0 ; i < q ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            res[i] = cusum[r]-((l>0) ? cusum[l-1] : 0) ;
        }
        return res ;
    }
};