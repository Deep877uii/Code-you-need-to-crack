class Solution {
public:

    bool found(vector<int>&arr , int n , int target){

        int low = 0 , high = n-1;
        bool flag = false ;
        while(low<=high){
            int mid = low + (high - low )/2 ;

            if(arr[mid]==target) flag = true ;

            if(arr[mid]>target){
                high=mid-1 ;
            }
            else{
                low=mid+1;
            }
        }
        return flag ;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag = false ;
        for(int row = 0 ; row<m ; row++){

            bool x = found(matrix[row],n,target);

            if(x==true){
                flag =true;
            }
        }
        return flag ;
    }
};