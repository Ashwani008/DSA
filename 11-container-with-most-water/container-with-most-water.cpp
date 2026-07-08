class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int i =0, j = height.size()-1;

        while(i < j){
            int length = min(height[i], height[j]);
            int breadth = j-i;

            maxi = max(maxi, length * breadth);

            if(height[i] > height[j])
                j--;
            else
                i++;
            
        }
        return maxi;
    }
};