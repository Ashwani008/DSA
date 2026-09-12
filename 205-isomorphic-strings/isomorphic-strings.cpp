class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> st;
        // unordered_map<char, char> mp2;
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                if(st.find(t[i]) == st.end()){
                    mp[s[i]] = t[i];
                    st.insert(t[i]);
                }
                else
                    return false;
            } else {
                if(mp[s[i]] != t[i])
                    return false;
                // if(mp2[t[i]] != s[i])
                //     return false;
            }
            
        }
        return true;
    }
};