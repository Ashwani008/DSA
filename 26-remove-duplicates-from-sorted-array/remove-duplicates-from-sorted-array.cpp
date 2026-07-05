class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l =0, j= 0, n = nums.size(),k=1;
        nums[j++] = nums[0];
        for(int i=1; i<n; i++) {
            if (nums[i] != nums[i-1]){
                nums[j++] = nums[i];
                k++;
            }
        }

        return k;
    }
};