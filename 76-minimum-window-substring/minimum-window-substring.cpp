class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(const auto& c : t)
            mp[c]++;
        int l =0, r=0, n = s.length(),ix =0, minlen=INT_MAX;

        if(n < t.length())
            return "";
        unordered_map<char, int> othmp;
        int found = 0, req = mp.size();
        while(r < n){
            othmp[s[r]]++;
            if(mp.find(s[r]) != mp.end() && mp[s[r]] == othmp[s[r]])
                found++;
            
            while(l <= r && found == req){
                if(minlen > r-l+1) {
                    ix = l;
                    minlen = r-l+1;
                }
                othmp[s[l]]--;
                if(mp.count(s[l]) && mp[s[l]] > othmp[s[l]])
                    found--;
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