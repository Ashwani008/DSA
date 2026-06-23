class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=1, len = nums.size(), minlen=INT_MAX;
        int sum = nums[0];
        while(j < len) {
            while (sum >= target) {
                minlen = min(minlen, j-i);
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            j++;
        }
        while (sum >= target) {
            minlen = min(minlen, j-i);
            sum -= nums[i];
            i++;
        }
        if (minlen == INT_MAX)
            return 0;
        return minlen;
    }
};