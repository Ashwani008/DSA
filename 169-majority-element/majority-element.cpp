class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i =0, n = nums.size();
        int cnt = 1, j = 1, ele = nums[0];
        for(int i = 1; i<n; i++) {
            if(ele != nums[i]){
                cnt--;
            }
            if (ele == nums[i]) {
                cnt++;
            }
            if (cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
        }
        return ele;
    }
};