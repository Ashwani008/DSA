class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ele = nums[0];
        for(int i =0; i<nums.size(); i++){
            if (count == 0){
                count =1;
                ele = nums[i];
                continue;
            }
            if (ele != nums[i]){
                count--;
            } else {
                count++;
            }
        }

        return ele;

    }               
};