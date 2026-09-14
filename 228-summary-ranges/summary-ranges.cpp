class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(),i=0;
        vector<string> ans;
        string s="";
        while(i<n){
            int st=nums[i];
            while(i+1 < n && nums[i]+1 == nums[i+1]){
                i++;
            }
            if(st == nums[i]){
                ans.push_back(to_string(st));
            } else {
                ans.push_back(to_string(st) + "->" + to_string(nums[i]));
            }
            i++;
        }
        return ans;
    }
};