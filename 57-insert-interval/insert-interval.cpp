class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size() == 0){
            vector<int> temp(newInterval);
            ans.push_back(temp);
            return ans;
        }
        
        int newele = newInterval[0];
        int findindex = intervals.size();
        for(int i = 0; i<intervals.size(); i++) {
            int st = intervals[i][0];
            if(st > newele){
                findindex = i;
                break;
            }
        }
        
        intervals.insert(intervals.begin() + findindex, newInterval);


        int st = intervals[0][0];
        int en = intervals[0][1];
    
        
        for(int i = 1; i<intervals.size(); i++){

            if(en >= intervals[i][0]){
                en = max(en, intervals[i][1]);
            } else {
                ans.push_back({st, en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }
        ans.push_back({st, en});
        return ans;
    }
};