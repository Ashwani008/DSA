class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;

        int wtr = 0, maxl = 0, maxr = 0;
        while( l <= r){
            if(height[l] < height[r]){
                maxl = max(maxl, height[l]);
                wtr = wtr + (maxl - height[l]);
                l++;
            } else {
                maxr = max(maxr, height[r]);
                wtr = wtr + (maxr - height[r]);
                r--;
            }
        }
        return wtr;
    }
};