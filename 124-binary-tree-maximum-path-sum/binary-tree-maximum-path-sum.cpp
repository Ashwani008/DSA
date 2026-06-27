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
    int maxi = INT_MIN;
    int maxPathSumFn(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxlf = max(0, maxPathSumFn(root->left));
        int maxrt = max(0, maxPathSumFn(root->right));


        maxi = max(maxi, root->val + maxlf + maxrt);

        return root->val + max(maxlf,maxrt);
}
    int maxPathSum(TreeNode* root) {
        maxPathSumFn(root);
        return maxi;
    }
};