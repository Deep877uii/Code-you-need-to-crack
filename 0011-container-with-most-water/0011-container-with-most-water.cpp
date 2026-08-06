class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ; 

        int maxi = 0 ; 
        int i = 0 , j = n-1 ; 

        while(i<j){
            int area = 0 ;
            area = (j-i)*min(height[i],height[j]);
            maxi = max(area,maxi);            
            if(height[i]<height[j]){
                i++;
            }
            else{               
                j--;
            }
        }
        return maxi;
    }
};