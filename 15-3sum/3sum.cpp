class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int k =0, n = nums.size()-2;


        while(k < n){
            int i = k+1;
            int j = nums.size()-1;
            while(i < j) {
                int s = nums[i] + nums[j] + nums[k];
                if(s > 0) {
                    j--;
                } else if ( s < 0){
                    i++;
                } else {
                    st.insert({nums[i], nums[j], nums[k]});
                    i++;
                    j--;
                }
            }
            k++;
        }
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;

    }
};