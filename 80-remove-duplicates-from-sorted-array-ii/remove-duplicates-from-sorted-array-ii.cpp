class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=2, n= nums.size();
        if(n <= 2)
            return n;
        for(i =2; i<n; i++){
            if(nums[i] != nums[j-2]){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};