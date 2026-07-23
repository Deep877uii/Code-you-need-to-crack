class Solution {
public:


    bool possible(vector<int>& nums, int mid, int k){

        int student = 1;
        int pages = 0;

        for(int i = 0; i < nums.size(); i++){

            if(pages + nums[i] <= mid){
                pages += nums[i];
            }
            else{
                student++;
                pages = nums[i];
            }
        }

        return student <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int sum = 0  , maxi = INT_MIN;
        for(auto it : nums){
            sum+=it ;
        }

        for(auto st : nums){
            maxi = max(maxi,st);
        }

        int low = maxi , high = sum , ans = -1 ;
        
        while(low<=high){
            int mid = low +(high-low)/2 ; 

            if(possible(nums,mid,k)==true){
                ans = mid ; 
                high = mid-1 ;
            }
            else{
                low=mid+1 ;
            }
        }
        return ans ;
    }
};