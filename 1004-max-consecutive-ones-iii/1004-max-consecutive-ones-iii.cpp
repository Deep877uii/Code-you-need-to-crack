class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n  = nums.size(); 

        int r = 0 , l = 0 ,max_len = 0 , zero=0;

        while(r<n){
            if(nums[r]==0) zero++;
            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            if(zero<=k){
                int len = r-l+1;
                max_len = max(len,max_len);
            }
            r++;
        }
        return max_len;
    }
};