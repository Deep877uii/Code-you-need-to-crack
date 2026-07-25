class Solution {
public:

    int findmax(vector<vector<int>>&mat , int mid , int n , int m){
        int maxvalue = -1 ; 
        int index = - 1;
        for(int i = 0 ; i < n ; i++){
            if(mat[i][mid]>maxvalue){
                maxvalue = mat[i][mid];
                index = i ;
            }
        }
        return index ;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0 , high = m-1 ; 

        while(low<=high){
            int mid = low+(high-low)/2 ; 
            int maxRowIndex = findmax(mat,mid,n,m) ; 

            int left = mid-1>=0 ? mat[maxRowIndex][mid-1] : -1 ;
            int right = mid+1<m ? mat[maxRowIndex][mid+1] : -1 ;

            if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right){
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid]<left){
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1,-1} ;
    }
};