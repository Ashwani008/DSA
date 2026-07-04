class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp;
        mp[0] = -1;
        int max_len = 0;
        int sum =0, k =0;
        
        for(int i =0; i<nums.size(); i++) {
            int v = nums[i]==1 ? 1 : -1;
            sum += v;
            if(mp.find(sum) != mp.end())
                max_len = max(max_len, i - mp[sum]);
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return max_len;
    }
};