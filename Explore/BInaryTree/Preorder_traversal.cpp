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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root!=NULL){
          pre_order(root,res);
        }
        
        return res;
    }

    void pre_order(TreeNode* root,vector<int> & values){
      values.push_back(root->val);
      if(root->left !=NULL){
        pre_order(root->left,values);
      }
      if(root->right!=NULL){
        pre_order(root->right,values);
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
//iterative solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > node_stack;
        if(root !=NULL){
          //res.push_back(root->val);
          node_stack.push(root);
          while(!node_stack.empty()){
            root = node_stack.top();
            node_stack.pop();
            res.push_back(root->val);
            if(root->right!=NULL){
              node_stack.push(root->right);
            }
            if(root->left!=NULL){
              node_stack.push(root->left);
            }

          }
        }

        return res;
    }
};