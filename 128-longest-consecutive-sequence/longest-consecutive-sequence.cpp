class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxi = 0;
        for(auto n : nums)
            st.insert(n);

        for(auto s : st) {
            int cnt = 0;
            if(st.find(s-1) == st.end()) {
                cnt = 0;
                int v = s;
                while(st.find(v) != st.end()){
                    v++;
                    cnt++;
                }
                maxi = max(cnt, maxi);

            }
            // maxi = max(cnt, maxi);
        }
        return maxi;
    }
};