class Solution {
public:

    vector<vector<int>> ans;

    void deep(int i, vector<int>& candidates, int target,vector<int>& result, int n, int sum) {

        if (i == n) {
            if (sum == target)
                ans.push_back(result);
            return;
        }

        if (sum + candidates[i] <= target) {
            result.push_back(candidates[i]);
            deep(i, candidates, target, result, n, sum + candidates[i]);
            result.pop_back(); 
        }

        deep(i + 1, candidates, target, result, n, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> result;
        int n = candidates.size();

        deep(0, candidates, target, result, n, 0);

        return ans;
    }
};