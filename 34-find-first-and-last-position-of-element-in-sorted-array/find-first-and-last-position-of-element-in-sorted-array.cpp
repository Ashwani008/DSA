class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int l =0, h = nums.size()-1;
        while( l<= h){
            int m = (l+h)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target){
                h = m-1;
            } else {
                l = m+1;
            }
        }
        return -1;
    }
    int findFloor(vector<int>& nums, int target) {
        int l =0, h = nums.size()-1;
        int ans = -1;
        while(l <= h) {
            int m = (l+h)/2;
            if(nums[m] < target) {
                ans = m;
                l = m + 1;
            } else{
                h = m-1;
            }
        }
        return ans;
    }
    int findCeiling(vector<int>& nums, int target) {
        int l = 0, h= nums.size()-1;
        int ans = nums.size();
        while(l <= h) {
            int m = (l+h)/2;
            if(nums[m] > target){
                ans = m;
                h = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int ix = binarySearch(nums, target);
        if( ix == -1 || n == 0){
            return {-1, -1};
        }
        if(nums[0] == nums[n-1] && nums[0] == target){
            return {0, n-1};
        }
        // vector<int> ans;
        int lix = findFloor(nums, target);
        int rix = findCeiling(nums, target);
        // ans.push_back();
        return {lix+1, rix-1};
    }
};