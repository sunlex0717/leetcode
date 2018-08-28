/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*********** while - stack  solution *****************/ //faster than recursive version in this case.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
      // if()
      if(root == NULL) return true;
      stack<TreeNode*> stack;
      TreeNode* pre = NULL;
      while(root != NULL || !stack.empty()){
        while(root != NULL){
          stack.push(root);
          root = root->left;
        }
        root = stack.top();
        stack.pop();
        if(pre != NULL && root->val <= pre->val) return false;
        pre = root;
        root = root->right;
      }
      return true;
        
    }
};

/*********** recursive solution *****************/

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
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }

    bool validate(TreeNode* root,TreeNode* &prev){
      if(root == NULL) return true;
      if(!validate(root->left,prev)) return false;
      if(prev!=NULL && prev->val >= root->val) return false;
      prev = root;
      return validate(root->right,prev);
      
    }
};