class Solution {
public:

    int day (vector<int>&weights , int capacity){

        int dayreq= 1  , load = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(capacity>=weights[i]+load){
                load+=weights[i];
            }
            else{
                dayreq++;
                load=weights[i];
            }
        }
        return dayreq ;
    }

    int maxim(vector<int>&weights){
        int maxi = 0 ;
        for(auto x : weights){
            maxi = max(maxi,x);
        }
        return maxi ;
    }

    int sumof(vector<int>&weights){
        int sum = 0 ;
        for(auto x : weights){
            sum+= x ;
        }
        return sum ; 
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxi = maxim(weights) , sum = sumof(weights) , ans = -1;


        int low = maxi , high = sum  ;

        while(low<=high){
            int mid = low+(high-low)/2 ; 
            int dayreq = day(weights,mid) ;

            if(dayreq<=days){
                ans =  mid ;
                high=mid-1; 
            }
            else{
                low=mid+1;
            }
        }
        return ans ;
    }
};