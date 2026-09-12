class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
        int num = 0, i =0;
        int n = s.length();

        while(i < n){
            if(i<n-1 && mp[s[i]] < mp[s[i+1]]) {
                num = num + (mp[s[i+1]] - mp[s[i]]);
                i += 2;
            } else{
                num = num + mp[s[i]];
                i += 1;
            }
        }
        return num;
        
        
        return num;
    }
};