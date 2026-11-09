class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  k =0,i =0, n = nums.size();
        
        nums[k++] = nums[i++];
        for(i = 1; i<n; i++) {
            if(nums[i] != nums[i-1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};