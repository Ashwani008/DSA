class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int firstlen = strs[0].size();
        string ans="";
        for(int i=0; i<firstlen; i++) {
            char ch = strs[0][i];
            for(int j =0; j<n; j++){
                if(strs[j].length() <= i)
                    return ans;
                if(strs[j][i] != ch){
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
    }
};