class Solution {
public:
    string reverseWords(string s) {
        vector<string> q;

        stringstream ss(s);
        string w;
        while(ss >> w){
            q.push_back(w);
        }
        string ans = "";
        if (q.size() == 0)
            return ans;
        
        for(int i=q.size()-1; i>0; i--){
            ans += q[i];
            ans +=" ";
        }
        ans += q[0];
        return ans;

    }
};