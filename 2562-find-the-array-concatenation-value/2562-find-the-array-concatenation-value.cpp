class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        string g = "";
        int n = nums.size();
        int i = 0 , j = n-1 ;
        long long sum = 0 ; 
        while(i<=j){
            if(i==j){
                sum+=nums[i];
                break;
            }
            g = to_string(nums[i])+to_string(nums[j]);
            i++;
            j--;

            sum += stoll(g) ;
        }
        return sum ;
    }
};