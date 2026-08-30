class Solution {
public:
    string minWindow(string s, string t) {
        int l =0, r =0, n = s.length(), wordlen = t.length();

        if(n < wordlen)
            return "";
        unordered_map<char, int> mp;
        for(auto it : t)
            mp[it]++;

        unordered_map<char, int> wmp;
        int required = mp.size();
        int formed = 0;
        int ix = 0, minlen = INT_MAX;
        while(r < n) {
            wmp[s[r]]++;

            if(mp.count(s[r]) && mp[s[r]] == wmp[s[r]])
                formed++;

            while((l <= r) && (formed == required)) {
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    ix = l;
                }

                wmp[s[l]]--;
                if(mp.count(s[l])  && wmp[s[l]] < mp[s[l]])
                    formed--;

                l++;
            }
            r++;
        }
        if(minlen == INT_MAX)
            return "";
        string ans = s.substr(ix, minlen);
        return ans;
    }
};