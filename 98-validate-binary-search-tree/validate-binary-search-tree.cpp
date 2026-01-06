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
    private:
   bool solve(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;
        if(root->val<=mini||root->val>=maxi){
            return false;
        }
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);

    }

// bool isStrictlyIncreasing(const vector<int>& v) {
//     return is_sorted(v.begin(), v.end()) &&
//            adjacent_find(v.begin(), v.end()) == v.end();
// }
public:
    bool isValidBST(TreeNode* root) {
      if(root==NULL) return true;
      //  vector<int> order;
      return solve(root,LONG_MIN,LONG_MAX);
       //return isStrictlyIncreasing(order)
        
    }
};