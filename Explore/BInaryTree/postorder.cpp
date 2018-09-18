/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root!=NULL){
          post_order(root,res);
        }
        
        return res;
    }

    void post_order(TreeNode* root,vector<int> & values){
      
      if(root->left !=NULL){
        post_order(root->left,values);
      }
      if(root->right!=NULL){
        post_order(root->right,values);
      }
      values.push_back(root->val);
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
// reverse the result 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> treestack;
        if(root==NULL){
          return res;
        }
        treestack.push(root);
        while(!treestack.empty()){
          root = treestack.top();
          treestack.pop();
          res.push_back(root->val);
          if(root->left!=NULL){
            treestack.push(root->left);
          }

          if(root->right!=NULL){
            treestack.push(root->right);
          }

        }

        std::reverse(res.begin(),res.end());

        return res;
    }
};