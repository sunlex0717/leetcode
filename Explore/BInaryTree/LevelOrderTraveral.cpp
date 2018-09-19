/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// BFS breadth-first search
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> BFS;
        vector<vector<int>> res;
        if(root==NULL){
          return res;
        }
        BFS.push(root);
        while(!BFS.empty()){
          int size = BFS.size();
          vector<int> tmp;
          for(int i = 0;i<size;i++){
            TreeNode* cur = BFS.front();
            if(cur->left!=NULL){
              BFS.push(cur->left);
            }
            if(cur->right!=NULL){
              BFS.push(cur->right);
            }
            tmp.push_back(cur->val);
            BFS.pop();
          }
          res.push_back(tmp);
        }
        return res;
    }
};