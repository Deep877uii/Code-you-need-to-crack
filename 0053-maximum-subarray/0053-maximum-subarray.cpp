class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0 ; 
        int maxi = nums[0] ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            pre += nums[i] ;
            maxi = max(pre,maxi);

            if(pre<0){
                pre=0;
            }
        }
        return maxi ; 
    }
};