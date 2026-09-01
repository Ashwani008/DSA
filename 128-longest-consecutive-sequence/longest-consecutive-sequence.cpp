class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++)
            s.insert(nums[i]);
        int maxlen =0;
        for(auto it : s) {
            int len = 0;

            if (s.find(it -1) == s.end()) {
                len = 0;
                int v = it;
                while(s.find(v) != s.end()) {
                    len++;
                    v++;
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
        
    }
};