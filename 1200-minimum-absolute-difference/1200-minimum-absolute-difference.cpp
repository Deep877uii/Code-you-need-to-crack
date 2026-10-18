class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int d = INT_MAX;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            d = min(d, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == d) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
