class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(),weights.end());
        int hi = accumulate(weights.begin(),weights.end(),0);
        int ans = 0 ;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int cnt = 1 ; 
            int sum = 0 ; 
            for(int i = 0 ; i < n ; i++){
                if(sum+weights[i]<=mid){
                    sum+= weights[i];
                }
                else{
                    cnt++;
                    sum=weights[i];
                }
            }
            if(cnt<=days){
                ans = mid ;
                hi = mid-1;;
            }
            else{
                
                lo = mid+1;
            }
        }
        return ans;
    }
};