class Solution {
public:

    void RotatebyOne(vector<int>& nums, int n) {
        int temp = nums[n-1];
        for(int i =n-1; i>=1; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] =  temp;
    }
    void Reverse(vector<int>& nums, int s, int e) {
        int l = s, r = e;
        while(l <= r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return;
        k = k % n; 
        if (k == 0) return;
        Reverse(nums, 0, n-1);
        Reverse(nums, 0, k-1);
        Reverse(nums, k, n-1);
        // for(int i =0; i<k; i++)
        //     RotatebyOne(nums, n);

        return;
    }
};