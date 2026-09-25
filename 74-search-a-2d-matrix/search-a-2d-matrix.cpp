class Solution {
public:
    bool binarySearch(vector<int> arr, int target){
        int l =0, h = arr.size()-1;
        while(l <= h){
            int m = (l+h)/2;
            if(arr[m] == target)
                return true;
            else if(arr[m] > target) {
                h = m-1;
            } else {
                l = m+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // vector<int> arr;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l =0, h = (m*n)-1;
        while(l <= h) {
            int mid = (l + h)/2;
            int r = mid/n;
            int c = mid%n;
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] < target){
                l = mid +1;
            } else {
                h = mid-1;
            }
        }
        return false;
        
    }
};