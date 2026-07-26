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
    TreeNode* build(vector<int>& postorder, int pst, int pend, vector<int>& inorder, int inst, int inend, map<int, int>& mp) {
        if(pst > pend || inst > inend)
            return NULL;
        
        int inroot = mp[postorder[pend]];
        int numsleft = inroot - inst;

        TreeNode* root = new TreeNode(postorder[pend]);

        root->left = build(postorder, pst, pst+numsleft -1, inorder, inst, inst+numsleft-1, mp);
        root->right = build(postorder, pst+numsleft, pend-1, inorder, inroot+1, inend, mp); 

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};