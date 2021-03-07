class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxProfit = 0;
        int maxRun = 0;
        int waitNum = 0;
        int p = 0;
        int profit = 0;
        int run = 0;
        while (waitNum || p < customers.size()) {
            if (p < customers.size())
                waitNum += customers[p++];
            int boardNum = min(waitNum, 4);
            profit = profit + boardNum * boardingCost - runningCost;
            run++;
            if (profit > maxProfit) {
                maxProfit = profit;
                maxRun = run;
            }
            waitNum -= boardNum;
        }
        if (maxProfit <= 0) maxRun = -1;
        return maxRun;
    }
};
