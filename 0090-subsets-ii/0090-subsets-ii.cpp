class Solution {
public:

set<vector<int>>ans;

void deep(int i , int n , vector<int>&nums , vector<int>&result){

    if(i==n){
        ans.insert(result);
        return ;
    }

        result.push_back(nums[i]);
        deep(i+1,n,nums,result);
        result.pop_back();         

        deep(i+1,n,nums,result);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        deep(0,n,nums,result);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};