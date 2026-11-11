class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totP = 0, n = prices.size();
        if(n == 1)
            return totP;
        for(int i = 1; i<n; i++){
            if(prices[i-1] <= prices[i]) {
                totP += (prices[i] - prices[i-1]);
            }
        }
        return totP;
    }
};