class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums.size();

        // int sl = nums[0];
        // int ft = nums[0];

        // sl = nums[sl];
        // ft = nums[nums[ft]];

        // while(sl != ft) {
        //     sl = nums[sl];
        //     ft = nums[nums[ft]];

        // }

        // sl = nums[0];
        // while(sl != ft) {
        //     sl = nums[sl];
        //     ft = nums[ft];
        // }

        // return sl;
        int n = nums.size();
        vector<int> vis(n+1, 0);
        for(int i =0; i<n; i++) {
            if(vis[nums[i]] == -1){
                return nums[i];
            }
            vis[nums[i]] = -1;
        }
        return -1;
    }
};