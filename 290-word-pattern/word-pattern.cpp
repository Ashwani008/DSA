class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        stringstream ss(s);
        for(int i = 0; i<pattern.size(); i++) {
            string w;
            getline(ss,w,' ');
            if(w == "")
                return false;
            if(mp.find(pattern[i]) == mp.end()) {
                if(mp2.find(w) == mp2.end()){
                    mp[pattern[i]] = w;
                    mp2[w] = pattern[i];
                } else {
                    return false;
                }
            } else {
                if (mp[pattern[i]] != w)
                    return false;
            }
        }
        string w;
        getline(ss,w,' ');
        if(w == "")
            return true;
        else
            return false;
    }
};