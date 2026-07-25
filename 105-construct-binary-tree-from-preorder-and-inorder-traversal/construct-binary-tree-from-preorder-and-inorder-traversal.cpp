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
    TreeNode* build(vector<int>& preorder, int pst, int pe, vector<int>& inorder, int inst, int ine, map<int, int>& mp) {
        if(pst> pe || inst > ine)
            return NULL;

        int inroot = mp[preorder[pst]];
        int numsleft = inroot - inst;

        TreeNode* root = new TreeNode(preorder[pst]);

        root->left = build(preorder, pst+1, pst+numsleft, inorder, inst, inst+numsleft-1, mp);
        root->right = build(preorder, pst+numsleft+1, pe, inorder, inroot+1, ine, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i =0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};