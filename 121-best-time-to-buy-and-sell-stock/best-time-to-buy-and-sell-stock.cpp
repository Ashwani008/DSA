class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mindayP = prices[0];
        int maxProfit = 0;

        for(int i =1; i<prices.size(); i++) {
            if(mindayP > prices[i]){
                mindayP = prices[i];
            }
            int profit  = prices[i] - mindayP;
            if(profit >= maxProfit)
                maxProfit = profit;
        }
        return maxProfit;
    }
};