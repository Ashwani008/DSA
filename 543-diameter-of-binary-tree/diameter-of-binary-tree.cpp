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
    int maxdia= 0;
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        maxdia = max(maxdia, lh+rh);
        int ans = max(lh, rh) + 1;
        return ans;
    }



    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        height(root);

        return maxdia;
    }
};