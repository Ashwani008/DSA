class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int mulres=1;
        vector<int> rmul(nums.size());
        int k = nums.size() -1;
        rmul[k--]  = 1;
        for(int i=nums.size()-1; i>0; i--) {
            mulres *= nums[i];
            rmul[k--] = mulres;
        }
        // return rmul;
        int lmul =1;
        for(int i =0; i<nums.size(); i++) {
            
            int val = rmul[i] * lmul;
            ans.push_back(val);
            lmul *= nums[i]; 
        }
        return ans;

    }
};