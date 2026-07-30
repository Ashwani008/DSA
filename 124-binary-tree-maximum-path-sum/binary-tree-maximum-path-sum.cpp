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
    int maxPath(TreeNode* root) {
        if(root == NULL)
            return 0;

        int lftSum = max(0, maxPath(root->left));
        int rtSum = max(0, maxPath(root->right));

        maxi = max(maxi, lftSum + rtSum + root->val);

        return root->val + max(lftSum, rtSum);

    }
    int maxPathSum(TreeNode* root) {
        int ans = maxPath(root);
        return maxi;
    }
};