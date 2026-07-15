class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int r = 0 , l = 0 , max_len = 0 ;
        int k = 2;
        map<int,int>mpp;

        while(r<n){
            mpp[fruits[r]]++;
            while (mpp.size() > 2) {
                mpp[fruits[l]]--;

                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);

                l++;
            }
            if(mpp.size()<=k){
                max_len=max(max_len,r-l+1);
            }
            r++;
        }
        return max_len;
    }
};