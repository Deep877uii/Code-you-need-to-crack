class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size() ; 
        int total = 0 ;
        for(auto it : possible){
            if(it==1) total+=1;
            else total-=1;
        }
        int preSum = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            preSum += (possible[i]==1 ? 1 : -1) ;
            int remSum = total - preSum ;

            if(preSum > remSum) return i+1;
        }
        return -1 ; 
    }
};