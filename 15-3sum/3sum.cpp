class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int k =0, n = nums.size()-2;
        vector<vector<int>> ans;

        while(k < n){
            if( k > 0 && nums[k] == nums[k-1]){
                k++;
                continue;
            }

            int i = k+1;
            int j = nums.size()-1;
            while(i < j) {
                int s = nums[i] + nums[j] + nums[k];
                if(s > 0) {
                    j--;
                } else if ( s < 0){
                    i++;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    i++;
                    j--;
                    while(i<j && nums[i] == nums[i-1])
                        i++;
                    while( i<j && nums[j] == nums[j+1])
                        j--;
                }
            }
            k++;
        }
        // vector<vector<int>> ans;
        // for(auto it : st){
        //     ans.push_back(it);
        // }
        return ans;

    }
};