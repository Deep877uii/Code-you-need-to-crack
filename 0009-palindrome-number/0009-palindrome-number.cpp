class Solution {
public:

    int reverse_num(int x){
        int reverse = 0 ;

        while(x!=0){
            int last_d = x%10 ;

            if(reverse > INT_MAX / 10 || reverse <INT_MIN /10){
                return 0 ;
            }

            reverse = reverse*10 + last_d ;
            x=x/10 ;
        }
        return reverse ;
    }

    bool isPalindrome(int x) {
        if(x<0) return false ;
        return (reverse_num(x) == x) ;
    }
};