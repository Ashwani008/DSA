class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        int i=0, n = nums.size();
        sort(nums.begin(), nums.end());

        while(i < n) {
            int j = i+1;
            while( j < n) {
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long int sum = (long long int)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target){
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        s.insert(temp);
                        l--;
                        k++;
                    }
                }
                j++;
            }
            i++;
        }

        vector<vector<int>> ans;
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;

    }
};