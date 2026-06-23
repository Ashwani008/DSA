class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp;
        int curSum =0;
        mp[curSum] = -1;
        int maxlen= 0;

        for(int i =0; i<nums.size(); i++) {
            if (nums[i] == 0)
                nums[i] = -1;
            curSum += nums[i];
            if(mp.find(curSum) != mp.end()) {
                maxlen = max(maxlen, i - mp[curSum]);
            } else {
                mp[curSum] =i;
            }
        }
        return maxlen;
    }
};