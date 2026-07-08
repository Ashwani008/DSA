class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l[n], r[n], maxi=-1;

        for(int i =0; i<n; i++) {
            if(maxi < height[i])
                maxi = height[i];
            l[i] = maxi;
        }   
        maxi = -1;
        for(int i=n-1; i>=0; i--){
            if(maxi < height[i])
                maxi= height[i];
            r[i] = maxi;
        }

        maxi = 0;
        for(int i=0; i<n; i++){
            int wt = min(l[i], r[i]) - height[i];
            maxi += wt;
        }
        return maxi;
    }
};