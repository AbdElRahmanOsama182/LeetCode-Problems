class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0, x;
        while (numBottles >= numExchange) {
            x = numBottles / numExchange;
            total += x * numExchange;
            numBottles = x + numBottles % numExchange;
        }
        return total + numBottles;
    }
};