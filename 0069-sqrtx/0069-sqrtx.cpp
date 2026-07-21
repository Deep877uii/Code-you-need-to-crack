class Solution {
public:
    long long mySqrt(long long x) {
        long long ans = 0 ;
        for(long long i = 0 ; i <=x ; i++){
            if(i*i<=x){
                ans=i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};