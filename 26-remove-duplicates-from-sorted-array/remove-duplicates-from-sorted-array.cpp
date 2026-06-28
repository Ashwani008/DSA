class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l =0, j= 0, n = nums.size(),k=1;

        for(j=1; j<n; j++){
            if(nums[l] != nums[j]) {
                l = l+1;
                nums[l] = nums[j];
                k++;
            }
        }
        return k;
    }
};