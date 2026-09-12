class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length(), l=0, r =0, maxi = 0;
        while(r < n) {
            if(mp.find(s[r]) != mp.end()) {
                if(l <= mp[s[r]]){
                    l = mp[s[r]] + 1;
                }
            }
            mp[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;

    }
};