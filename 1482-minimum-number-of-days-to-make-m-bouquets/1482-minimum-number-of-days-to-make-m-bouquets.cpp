class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k){

        int count = 0;
        int noBoquet = 0;

        for(int i = 0; i < bloomDay.size(); i++){

            if(bloomDay[i] <= day){
                count++;
            }
            else{
                noBoquet += count / k;
                count = 0;
            }
        }

        noBoquet += count / k;

        return noBoquet >= m;
    }

    int maxim(vector<int>& bloomDay){

        int maxi = 0;

        for(int x : bloomDay)
            maxi = max(maxi, x);

        return maxi;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long)m * k > bloomDay.size())
            return -1;

        int maxi = maxim(bloomDay);

        int low = 1 , high = maxi ,ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1 ; 
            }
        }
        return ans ; 
    }
};