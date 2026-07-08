class Solution {
public:
int findDuplicate(vector<int>& arr) {
            unordered_set<int> seen;
            for (int i = 0; i < arr.size(); i++) {
                if (seen.count(arr[i])) {
                    return arr[i];
                }
                seen.insert(arr[i]);
            }
            return -1; 
        }
};