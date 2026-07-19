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
    vector<TreeNode*> pre;
    void preorder(TreeNode* root) {
        if(root == NULL)
            return;
        pre.push_back(root);
        preorder(root->left);
        preorder(root->right);
        return;
    }
    void flat(TreeNode* root) {
        for(int i = 0; i<pre.size()-1; i++){
            TreeNode* node = pre[i];
            node->left = NULL;
            node->right = pre[i+1];
        }
        pre.back()->left = NULL;
        pre.back()->right = NULL;
        return;
    }

    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        preorder(root);
        flat(root);
        return;
    }
};