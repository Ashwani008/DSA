class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int prevstart = prev[0];
        int prevend = prev[1];

        int count = 1;
        for(int i =1; i<points.size(); i++) {
            

            int curstart = points[i][0];
            int curend = points[i][1];

            if(prevend < curstart) {
                count++;
                prevstart = curstart;
                prevend = curend;
            } else {
                prevstart = max(curstart, prevstart);
                prevend = min(curend, prevend);
            }
        }
        return count;

    }
};