class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i= 0, j = numbers.size()-1;

        while(i < j){
            int s = numbers[i] + numbers[j];
            if( s > target){
                j--;
            } else if (s < target){
                i++;
            } else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
        }
        return ans;
    }
};