class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count =0, n = points.size();
        if(n == 0)
            return count;
        
        sort(points.begin(), points.end());
        int prevstart = points[0][0];
        int prevend = points[0][1];
        for(int i =1; i<n; i++){
            int currstart = points[i][0];
            int currend = points[i][1];

            if(prevend < currstart){
                count++;
                prevstart = currstart;
                prevend = currend;
            } else {
                prevstart = max(prevstart, currstart);
                prevend = min(prevend, currend);
            }
            
        }
        return count+1;

    }
};