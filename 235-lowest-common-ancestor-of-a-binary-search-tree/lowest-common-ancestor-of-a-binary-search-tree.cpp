/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode*q) {
            if(!root)return NULL;

            if(q->val<root->val&&p->val<root->val){
                return solve(root->left,p,q);
            }
            if(q->val>root->val&&p->val>root->val){
                return solve(root->right,p,q);
            }

            return root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,  p, q);
    }
};