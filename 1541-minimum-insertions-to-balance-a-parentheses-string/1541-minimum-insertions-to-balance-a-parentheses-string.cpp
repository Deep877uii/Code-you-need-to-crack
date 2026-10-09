class Solution {
public:
    int minInsertions(string s) {
        int n = s.size() ; 
        int count = 0 , result = 0 , i = 0 ; 

        while(i<n){
            if(s[i] == '('){
                count++;
                i++;
            }
            else{
                if(count>0){
                    count--;
                }
                else{
                    result++;
                }
                if(s[i+1]==')'){
                    i+=2;
                }
                else{
                    result++;
                    i++;
                }
            }
        }
        return result+count*2 ;
    }
};