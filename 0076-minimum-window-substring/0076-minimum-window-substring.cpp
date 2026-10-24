#include<iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};

        for(int i = 0 ; i < t.size() ; i++){
            hash[t[i]]++;
        }
        int i = 0 , j = 0 ;
        int count = 0 , min_len = INT_MAX , startInd=-1;
        while(j<s.size()){
            if(hash[s[j]]>0){
                count++;
            }
            hash[s[j]]--;

            while(count==t.size()){
                if(j-i+1 < min_len){
                    min_len = j-i+1;
                    startInd = i;
                }
                hash[s[i]]++;
                if(hash[s[i]]>0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return (startInd==-1)?"" : s.substr(startInd,min_len);
    }
};