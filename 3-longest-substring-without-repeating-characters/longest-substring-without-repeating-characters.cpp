class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int i=0, j =0, n= s.length();
        int maxlen = 0;
        while(j<n) {
            if (mp.find(s[j]) != mp.end()) {
                i = max(i,mp[s[j]]+1);
            }
            mp[s[j]] = j;
            maxlen = max(maxlen, j-i+1);

            j++;
        }
        return maxlen;
        
    }
};