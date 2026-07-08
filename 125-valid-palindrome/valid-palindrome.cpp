class Solution {
public:
    bool validate(string t) {
        int i =0, j = t.size()-1;

        while(i < j) {
            if(t[i] != t[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string t="";
        for(int i =0; i<s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                char ch = (tolower(s[i]));
                t += ch;
            }
        }
        if(validate(t))
            return true;
        else
            return false;

    }
};