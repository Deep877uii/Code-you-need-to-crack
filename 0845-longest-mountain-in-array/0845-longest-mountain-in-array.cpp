class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size() ; 
        int max_len = 0 ;
        for(int i = 1 ; i<= n-2 ; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int count = 1; 
                int left  = i;
                int right = i;

                while(left>0 && arr[left-1]<arr[left]){
                    count++;
                    left--;
                }
                while(right<n-1 && arr[right+1]<arr[right]){
                    count++;
                    right++;
                }
                max_len = max(max_len,count);
            }
        }
        return max_len ;
    }
};