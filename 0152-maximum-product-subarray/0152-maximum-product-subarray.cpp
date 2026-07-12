class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = nums[0];

        for(int i = 0 ; i < n ; i++){
            int prod = 1 ;
            for(int j = i ; j<n ; j++){
                prod*=nums[j];
                max_prod = max(max_prod,prod);
            }
        }
        return max_prod;
    }
};