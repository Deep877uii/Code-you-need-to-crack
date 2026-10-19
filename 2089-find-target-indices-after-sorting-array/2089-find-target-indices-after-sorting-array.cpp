class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> list;

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                list.push_back(mid);

                // Search both sides for duplicate targets
                int i = mid - 1;
                while(i >= 0 && nums[i] == target) {
                    list.push_back(i);
                    i--;
                }

                i = mid + 1;
                while(i < n && nums[i] == target) {
                    list.push_back(i);
                    i++;
                }

                sort(list.begin(), list.end());
                return list;
            }
        }

        return list;
    }
};