class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n= nums.size(), k =0;
        sort(nums.begin(), nums.end());

        if((nums[0] == nums[n-1])&& (nums[0] == 0)){
            return {{nums[0], nums[0], nums[0]}};
        }
        while(k < n){
            int i = k+1;
            int j = n-1;

            while(i < j) {
                int s = nums[k] + nums[j] + nums[i];

                if (s > 0)
                    j--;
                else if (s < 0)
                    i++;
                else {
                    vector<int> temp;
                    temp.push_back(nums[k]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[i]);
                    i++;
                    j--;
                    ans.insert(temp);
                }
            }
            k++;

        }

        
        
        vector<vector<int>> res;
        for(auto it : ans) {
            res.push_back(it);
        }
        return res;
    }
};