/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// go down until p and q are not in one subtree of a node, then we return that node
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root->val == p->val || root->val == q->val){
        return root;
      }
      if(p->val > root->val && q->val < root->val){ // p > root and q < root
        return root;
      }else if(q->val > root->val && p->val < root->val){ //q > root and p < root
        return root;
      }else if(q->val > root->val && p->val > root->val){
        return lowestCommonAncestor(root->right,p,q);
      }else if(q->val < root->val && p->val < root->val){
        return lowestCommonAncestor(root->left,p,q);
      }
      return NULL;
        
    }
};