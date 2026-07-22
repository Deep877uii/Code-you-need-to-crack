class Solution {
public:


    bool possible(vector<int>&nums ,int threshold, int div ){
        int total = 0 ;
        bool flag = false ;
        for(int i = 0 ; i<nums.size() ; i++){
            total += (nums[i] + div - 1) / div;
        }
        if(total<=threshold){
            flag=true ;
        }
        return flag ;
    }

    int maxim(vector<int>& nums){

        int maxi = 0;

        for(int x : nums)
            maxi = max(maxi, x);

        return maxi;
    }    

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = maxim(nums); 

        int low = 1 , high = maxi , ans = -1 ;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(possible(nums,threshold,mid)==true){
                ans = mid ;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans ;
    }
};