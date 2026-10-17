class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        map<int, vector<int>> mpp;

        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++) {
            int k = queries[i];

            if(k <= mpp[x].size()) {
                ans.push_back(mpp[x][k - 1]);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};