class Solution {
public:

    string generate(string &word){
        int arr[26]={0};

        for(char &ch : word){
            arr[ch-'a']++ ;
        }

        string new_word ="";
        
        for(int i = 0 ; i<26 ; i++){
            int freq = arr[i];

            if(freq>0){
                new_word += string(freq,i+'a');
            }
        }
        return new_word ;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans ;

        int n = strs.size() ;

        unordered_map<string,vector<string>> mpp ;



        for(int i = 0 ; i< n ; i++){
            string temp = strs[i] ;
            string new_word = generate(temp);
            mpp[new_word].push_back(temp);
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans ;
    }
};