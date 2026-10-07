class Solution {
public:

    int reversed(int x){
        int rever = 0  ;

        while(x!=0){
            int last_di = x%10;
            if(rever>INT_MAX/10 || rever<INT_MIN/10) return 0;
            rever = rever*10+last_di ; 
            x=x/10;
        }
        return rever ;
    }

    bool isPalindrome(int x) {
        if(x<0) return false ;
        return (reversed(x)==x);
    }
};