class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l =0, r= 0, maxlen = 0;
        map<char, int> mp;
        
        while(r<n) {
            if(mp.find(s[r]) != mp.end()){
                if(l <= mp[s[r]]){
                    l = mp[s[r]] + 1;
                }
            }
            mp[s[r]] = r;
            r++;
            maxlen = max(maxlen, r-l);
        }
        return maxlen;
    }
};