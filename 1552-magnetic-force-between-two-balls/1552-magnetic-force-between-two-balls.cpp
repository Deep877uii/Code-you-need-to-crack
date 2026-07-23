class Solution {
public:
    
    bool possible(vector<int>&position , int m , int dis){

        int count_ball = 1 , last = position[0] ;
        bool flag = false ;
        for(int i = 1 ; i<position.size() ; i++){
            if(position[i]-last>=dis){
                    count_ball++;
                    last=position[i] ; 
                }
            }
            if(count_ball>=m) {
                flag = true ; 
                }   
            return flag ;
        }


    int maxim(vector<int>&position){
        int maxi = 0 ;
        for(auto it : position){
            maxi = max(maxi,it);
        }
        return maxi ;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());
        int maxDis = position.back() - position.front();
        int low = 1 , high = maxim(position) , ans = maxDis ;
        
        while(low<=high){
            int mid = low+(high-low)/2 ;
            if(possible(position,m,mid)==false){
                ans = mid-1;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans ;
    }
};