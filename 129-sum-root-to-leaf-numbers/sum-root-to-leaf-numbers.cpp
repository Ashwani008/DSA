/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> nums;
    void travel(TreeNode* root, string& num){
        if(root == NULL)
            return;

        char v = root->val + '0';
        num.push_back(v);

        if(root->left == NULL && root->right == NULL) {
            nums.push_back(num);
        } else{
            travel(root->left, num);
            travel(root->right, num);
        }
        num.pop_back();
        return;
    }
    int sumNumbers(TreeNode* root) {
        string num = "";
        travel(root, num);
        int sum = 0;
        for(auto it : nums) {
            int n = stoi(it);
            sum += n;
        }
        return sum;
    }
};