/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// bot-up
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int a,b;
        if(root==NULL){
          return 0;
        }
        if(root->left == NULL && root->right == NULL){
          return 1;
        }

        a = maxDepth(root->left);

        b = maxDepth(root->right);

        return max(a,b) +1;
        
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
// top-down
class Solution {
private:
int answer;
public:
    int maxDepth(TreeNode* root) {
      if(root==NULL){
        return 0;
      }
      
      answer = 0;
      sol(root,1);
      return answer;
        
    }

    void sol(TreeNode* root,int dep){
      if(root->left == NULL && root->right==NULL){
        answer = max(answer,dep);
      }
      if(root->left !=NULL){
        sol(root->left,dep+1);
      }
      if(root->right !=NULL){
        sol(root->right,dep+1);
      }


    }
};