class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size() ;
        int count = 0 ;
        vector<string> result;  
        for(int i = 0 ; i<word.size(); i++){
            for(int j = 1 ; j<=word.size()-i ; j++){
                result.push_back(word.substr(i,j));
            }
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<result.size() ; j++){
                if(result[j]==patterns[i]){
                    count++;
                    break;
                }
            }
        }
        return count ; 
    }
};