class Solution {
public:
    int reverse(int x) {
        int reversed_number = 0 ;
        while (x!=0){
            int last_d = x%10;
            if (reversed_number > INT_MAX / 10 || reversed_number < INT_MIN / 10) {
                return 0;
            }
            reversed_number =  reversed_number*10+ last_d; 
            x=x/10;
        }
        return reversed_number;
    }
};