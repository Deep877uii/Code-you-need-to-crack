class Solution {
public:

bool possible(vector<int>&position , int dis , int m){
    
    int count_ball = 1 , last = position[0];

    for(int i = 1; i < position.size() ; i++){
        if(position[i]-last >=dis){
            count_ball++;            
            last = position[i];
        }
    }
    return count_ball>=m;
}

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int low = 1 , high = position.back()-position.front() ;
        int ans = 0 ;
        while(low<=high){
            int mid = low+(high-low)/2 ; 

            if(possible(position,mid,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans ; 
    }
};