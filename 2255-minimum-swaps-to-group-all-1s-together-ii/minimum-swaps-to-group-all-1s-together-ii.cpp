class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(2*n);

        int total_one = accumulate(begin(nums), end(nums), 0);
        int max_one =0;
        int curr_one = 0, i=0, j=0;

        while(j < 2*n){
            if(nums[j%n] == 1){
                curr_one++;
            }
            if(j -i + 1 > total_one){
                curr_one -= nums[i%n];
                i++;
            }
            max_one = max(max_one, curr_one);
            j++;
        }
        return (total_one - max_one);
    }
};