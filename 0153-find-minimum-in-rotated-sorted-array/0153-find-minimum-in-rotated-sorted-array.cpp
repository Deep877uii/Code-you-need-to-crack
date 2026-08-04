class Solution {
public:
    int findMin(vector<int>& nums) {
        int n  = nums.size() ; 

        int low = 0 , high = n-1  , minimum = INT_MAX; 

        while(low<=high){
            int mid = low +(high-low)/2 ; 

            if(nums[low]<=nums[mid]){
                minimum = min(minimum,nums[low]);
                low=mid+1 ; 
            }
            else{
                minimum = min (minimum,nums[mid]);
                high=mid-1 ;
            }
        }
        return minimum ;
    }
};