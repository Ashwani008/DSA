class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++) {
            int v = abs(nums[i]);
            if(nums[v-1] < 0){
                ans.push_back(abs(nums[i]));
                continue;
            }
            
            nums[v-1] *= -1;

        }   
        return ans;
    }
};