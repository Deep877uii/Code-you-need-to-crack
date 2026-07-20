class Solution {
public:
    int search(vector<int>& nums, int target) {

        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]] = i;
        }

        if(mpp.find(target) != mpp.end())
            return mpp[target];

        return -1;
    }
};