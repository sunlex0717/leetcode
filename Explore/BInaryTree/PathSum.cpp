/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// top-down
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
      // if is leaf
      bool left_res = false;
      bool right_res = false;

      if(root==NULL){
        return false;
      }
      if(root->left==NULL && root->right==NULL){
        return (sum==root->val);
      }

      if(root->left!=NULL){
        left_res = hasPathSum(root->left,sum-root->val);
      }

      if(root->right !=NULL){
        right_res = hasPathSum(root->right,sum-root->val);
      }

      return left_res||right_res;
      
        
    }

    
};