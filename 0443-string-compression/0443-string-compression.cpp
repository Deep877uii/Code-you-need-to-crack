class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0 , j = 0 ;
        int n = chars.size();
        int index = 0 ;
        while(i<chars.size()){
            j=i ;
            while(j<chars.size() && chars[j]==chars[i]){
                j++;
            }
            int count = j-i ; 
            chars[index++]=chars[i];
            if(count>1){
                string temp = to_string(count);
                for(int i = 0 ; i<temp.size();i++){
                chars[index++]=temp[i] ;
                }
            }
            i=j ;              
        }
        return index ;
    }
};