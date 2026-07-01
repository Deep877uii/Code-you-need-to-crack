class Solution {
public:

vector<vector<int>>ans;

void deep(int i , int n , vector<int>&nums , vector<int>&result){

    if(i==n){
        ans.push_back(result);
        return ;
    }

    if(i<=n){
        result.push_back(nums[i]);
        deep(i+1,n,nums,result);
        result.pop_back();         
    }
    deep(i+1,n,nums,result);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>result;
        int n = nums.size();
        deep(0,n,nums,result);
        return ans;
    }
};