class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int end = n-1, flag = 1,ans =0, i;
        for(i=n-1; i>=0; i--) {
            if ((flag == 1) && (s[i] != ' ')) {
                end = i;
                flag = 0;
            }
            if ((flag == 0) && (s[i] == ' ')) {
                ans = end -i;
                return ans;
            }
        }
        return end+1;
    }
};