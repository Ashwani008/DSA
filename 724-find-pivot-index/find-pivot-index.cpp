class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1, sum =0,lsum =0, rsum =0;
        for(int i=0; i<n; i++)
            sum += nums[i];

        for(int i=0; i<n; i++){
            if(i > 0)    
                lsum = lsum + nums[i-1];
            rsum = sum - lsum -nums[i];
            if(lsum == rsum)
                return i;
        }

        return pivot;
    }
};