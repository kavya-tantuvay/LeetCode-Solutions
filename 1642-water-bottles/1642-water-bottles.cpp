class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0, eb = 0;
        while (numBottles > 0) {
            drink += numBottles;
            eb += numBottles;
            numBottles = eb / numExchange;
            eb = eb % numExchange;
        }
        return drink;
    }
};