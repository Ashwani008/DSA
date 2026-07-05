class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int lsum[n];
        int rsum[n];
        lsum[0]=0;
        rsum[n-1]=0;
        int j = n-1, k = n-1;
        for(int i=1; i<nums.size(); i++) {
            lsum[i] = lsum[i-1] + nums[i-1];
        }
        for(int i = n-2; i>=0; i--) {
            rsum[i] = rsum[i+1] + nums[i+1];
        }
        int pivot = -1;
        for(int i=0; i<nums.size(); i++) {
            if(lsum[i] == rsum[i])
                return i;
        }
        return pivot;
    }
};