class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0, j = height.size()-1;
        int maxi = INT_MIN;

        while(i < j){
            int len = min(height[i], height[j]);
            int bdt = j-i;
            int area = len * bdt;

            maxi = max(maxi, area);

            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return maxi;
    }
};