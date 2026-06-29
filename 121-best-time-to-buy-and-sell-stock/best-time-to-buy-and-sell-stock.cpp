class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int arr[n];
        arr[n-1] = prices[n-1];
        int max = arr[n-1];
        for(int i =n-2 ; i>=0; i--) {
            if(max < prices[i])
                max = prices[i];
            arr[i] = max;
        }

        int maxP = 0;
        for(int i =0; i<n; i++) {
            int p = arr[i] - prices[i];
            if (maxP < p)
                maxP = p;

        }
        return maxP;
    }
};