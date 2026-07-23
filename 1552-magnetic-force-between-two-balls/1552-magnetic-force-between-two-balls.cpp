class Solution {
public:

    bool possible(vector<int>& position, int m, int dis){

        int count_ball = 1, last = position[0];

        for(int i = 1; i < position.size(); i++){
            if(position[i] - last >= dis){
                count_ball++;
                last = position[i];
            }
        }

        return count_ball >= m;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int maxDis = position.back() - position.front();

        int low = 1, high = maxDis, ans = 0;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(possible(position, m, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};