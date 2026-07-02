class Solution {
public:

vector<vector<int>>ans;
void deep(int i ,int sum ,vector<int>&arr, int n , int k ,vector<int>&result){

    if(i == arr.size()){
        if(sum == n && result.size() == k)
            ans.push_back(result);
        return;
    }

    if(sum+arr[i]<=n){
        result.push_back(arr[i]);
        deep(i+1,sum+arr[i],arr,n,k,result);
        result.pop_back() ;
    }
    deep(i+1,sum,arr,n,k,result);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int>result;
        deep(0,0,arr,n,k,result);
        return ans ;
    }
};