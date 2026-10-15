class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre(n),succ(n);

        pre[0]=height[0];
        for(int i = 1 ; i<n ; i++){
            pre[i]=max(pre[i-1],height[i]);
        }
        succ[n-1]=height[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            succ[i]=max(succ[i+1],height[i]);
        }
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            sum+= min(pre[i],succ[i])-height[i];
        }
        return sum ;
    }
};