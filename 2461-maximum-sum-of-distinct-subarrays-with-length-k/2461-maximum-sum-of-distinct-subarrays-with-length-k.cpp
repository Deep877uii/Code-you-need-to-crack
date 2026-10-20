class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int l = 0 , r = 0 ;
        long long result = 0 , cwind = 0 ;
        unordered_set<int>st ;   
        while(r<n){

            while(st.count(nums[r])){
                cwind-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            cwind+=nums[r];
            st.insert(nums[r]);

            if(r-l+1 == k){
                result = max(result,cwind);

                cwind-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            r++;
        }
        return result ;
    }
};


// [2,9,9,9]   k = 3 
// 15 

// l = 0
// r = 0    sum = nums[l];
// len = r-l+1

