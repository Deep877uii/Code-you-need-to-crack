class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3 ; 
        map<int,int>mpp;
        vector<int>arr;

        for(int i = 0 ; i<n ; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second>k){
                arr.push_back(it.first);
            }

        }
        return arr;
    }
};