class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxi = 0;
        int rem = 0;

        while (numBottles > 0) {
            maxi += numBottles;
            rem += numBottles;

            numBottles = rem / numExchange;
            rem = rem % numExchange;
        }

        return maxi;
    }
};
