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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root!=NULL){
          inorder(root,res);
        }
        return res;
    }

    void inorder(TreeNode* root,vector<int>& res){
      if(root->left!=NULL){
        inorder(root->left,res);
      }

      res.push_back(root->val);

      if(root->right!=NULL){
        inorder(root->right,res);
      }
    }
};




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> treestack;
        vector<int> res;
        if(root==NULL){
          return res;
        }

        TreeNode* cur = root;
        while(!treestack.empty() || cur){
          if(cur!=NULL){
            treestack.push(cur);
            cur = cur->left;
          }else{
            TreeNode* pnode = treestack.top();
            treestack.pop();
            res.push_back(pnode->val);
            cur = pnode->right;
          }
        }
        return res;

       
    } 
};