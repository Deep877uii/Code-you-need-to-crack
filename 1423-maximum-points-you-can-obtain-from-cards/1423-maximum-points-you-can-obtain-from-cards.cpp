class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left_sum= 0 , right_sum = 0 , max_sum = 0 ;

        for(int i = 0 ; i<= k-1 ; i++){
            left_sum +=cardPoints[i];
            max_sum = left_sum ;
        }
        int right_ind = n-1 ;
        for(int i = k-1 ; i>=0 ; i--){
            left_sum -=cardPoints[i];
            right_sum+= cardPoints[right_ind];
            right_ind--;

            max_sum = max(max_sum,(left_sum+right_sum));
        }
        return max_sum ; 
    }
};