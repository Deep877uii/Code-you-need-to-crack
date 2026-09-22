class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr;
        double median = 0;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()) {
            arr.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()) {
            arr.push_back(nums2[j]);
            j++;
        }

        if(arr.size() % 2 == 0) {
            median = (arr[arr.size()/2] + arr[arr.size()/2 - 1]) / 2.0;
        }
        else {
            median = arr[arr.size()/2];
        }

        return median;
    }
};