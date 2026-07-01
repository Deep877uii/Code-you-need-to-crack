class Solution {
public:

vector<vector<int>>ans ;
void deep(int i , vector<int>&candidates , int target ,int n ,int sum , vector<int>&result){

        if (i == n) {
            if (sum == target)
                ans.push_back(result);
            return;
        }

        if (sum + candidates[i] <= target) {
            result.push_back(candidates[i]);
            deep(i+1, candidates, target,n, sum + candidates[i],result);
            result.pop_back(); 
        }
        while (i + 1 < n && candidates[i] == candidates[i + 1])
            i++;
        deep(i+1, candidates, target,n, sum,result); 

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>result;
        sort(candidates.begin(), candidates.end());
        deep(0,candidates,target,n,0,result);
        return ans;
    }
};