class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> np;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                p.push_back(nums[i]);
            }
            else{
                np.push_back(nums[i]);
            }
        }

        int index = 0;

        for(int i = 0; i < p.size(); i++){
            nums[index] = p[i];     
            nums[index + 1] = np[i]; 
            index += 2;
        }

        return nums;
    }
};
