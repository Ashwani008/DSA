class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0)
            return ans;

        int st = nums[0], end = nums[0];
        bool include = false;

        for(int i =0; i<n; i++) {
            if( i == n-1){
                string str = to_string(nums[i]);
                if(include) {
                    string str_s = to_string(st);
                    string str_e = to_string(nums[i]);
                    string temp = str_s;
                    temp += "->";
                    temp += str_e;
                    ans.push_back(temp);
                } else {
                    string str_e = to_string(nums[i]);
                    ans.push_back(str_e);
                }
            }
            else if(nums[i] + 1 == nums[i+1] ){
                if(!include){
                    include = true;
                    st = nums[i];
                }
                
            } else {
                if(include) {
                    string str_s = to_string(st);
                    string str_e = to_string(nums[i]);
                    string temp = str_s;
                    temp += "->";
                    temp += str_e;
                    ans.push_back(temp);
                } else {
                    string str_e = to_string(nums[i]);
                    ans.push_back(str_e);
                }
                include = false;
            }
        }
        return ans;
    }
};