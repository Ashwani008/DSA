class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();   
        vector<int> rmul(n);
        int val = 1, k = n-1;
        rmul[k--] = val;
        for(int i =n-1; i>0; i--){
            val *= nums[i];
            rmul[k--] = val;
        }

        int lmul = 1;
        for(int i =0; i<n; i++) {
            rmul[i] = (rmul[i] * lmul);
            lmul *= nums[i];
        }
        return rmul;
    }
};