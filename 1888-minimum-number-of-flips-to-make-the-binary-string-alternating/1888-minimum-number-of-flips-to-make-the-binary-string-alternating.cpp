class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        string s1 , s2 ; 

        int result = INT_MAX ; 
        int flip1 = 0 , flip2 = 0 ;

        int i = 0 , j = 0 ; 

        while(j<2*n){

            char expchars1 = (j%2)?'1':'0';
            char expchars2 = (j%2)?'0':'1';

            if(s[j%n]!=expchars1){
                flip1++;
            }
            if(s[j%n]!=expchars2){
                flip2++;
            }

            if((j-i+1) > n){

                expchars1 = (i%2)?'1':'0';
                expchars2 = (i%2)?'0':'1';

                if(s[i%n]!=expchars1){
                    flip1--;
                }
                if(s[i%n]!=expchars2){
                    flip2--;
                }
                i++;
            }
            if((j-i+1) == n){
                result = min(result,min(flip1,flip2));
            }
            j++;
        }
        return result ;
    }
};