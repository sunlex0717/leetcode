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
private:
    stack<TreeNode*> sk;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        push_left(root);
        if(sk.empty()) return NULL;
        TreeNode* cur_node;
        if(root->val == val){
          return root;
        }
        while(!sk.empty()){
          cur_node = sk.top();
          sk.pop();
          if(val < cur_node->val){ //val < smallest value in the tree, so return NULL
            return NULL;
          }else if(val == cur_node->val ){
            return cur_node; // return father node
          }else{ // val > cur_val
            if(cur_node->right != NULL){
              push_left(cur_node->right);
            }
          }
        }

        return NULL;

    }

    void push_left(TreeNode* root){
      while(root != NULL){
        sk.push(root);
        root = root->left;
      }
    }

    
};


// recursive solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        while(root != nullptr){
            if(root->val == val) return root;
            if(root->val < val)
                return searchBST(root->right, val);
            else
                return searchBST(root->left, val);
        }
        return nullptr;
    }
};