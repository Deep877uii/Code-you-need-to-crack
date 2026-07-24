class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> me;

        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                me.push_back(nums1[i]);
                i++;
            }
            else{
                me.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m){
            me.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            me.push_back(nums2[j]);
            j++;
        }

        int total = m + n;

        if(total % 2 == 1){
            return me[total / 2];
        }

        return (me[total / 2] + me[total / 2 - 1]) / 2.0;
    }
};