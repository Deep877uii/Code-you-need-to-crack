
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int weight = 0;

        sort(boxTypes.begin(), boxTypes.end(),[](vector<int>& a, vector<int>& b) {
                 return a[1] > b[1];
             });

        for (int i = 0; i < n; i++) {
            int box = boxTypes[i][0];
            int unitW = boxTypes[i][1];

            int take = min(truckSize, box);

            weight += take * unitW;
            truckSize -= take;

            if (truckSize == 0) break;
        }

        return weight;
    }
};
