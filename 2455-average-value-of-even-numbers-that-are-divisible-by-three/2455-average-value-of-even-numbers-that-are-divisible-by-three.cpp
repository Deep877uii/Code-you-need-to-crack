class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n = nums.size() ; 
        int cnt = 0 , sum = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(nums[i]%6 == 0){
                sum += nums[i] ; 
                cnt++;
            }
        }
        if(cnt == 0) return 0;        
        return (sum/cnt);
    }
};