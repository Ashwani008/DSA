class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p = 0, maxP = 0;
        for(int i =0; i<n-1; i++) {
            if (prices[i+1] > prices[i]) {
                p = prices[i+1] - prices[i];
                maxP += p;
            }
        }
        return maxP;
    }
};