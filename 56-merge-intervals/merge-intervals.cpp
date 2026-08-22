class Solution {
public:

    static bool comp(vector<int> a, vector<int> b) {
        if(a[0] < b[0])
            return true;
        else
            return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(), interval.end(), comp);

        vector<vector<int>> ans;
        int st = interval[0][0];
        int en = interval[0][1];

        for(int i =1; i< interval.size(); i++) {

            if (en  >= interval[i][0]) {
                en = max(en, interval[i][1]);
            } else {
                ans.push_back({st, en});

                st = interval[i][0];
                en = interval[i][1];
            }
        }
        ans.push_back({st, en});
        return ans;
        
    }
};